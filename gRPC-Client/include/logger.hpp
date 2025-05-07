#pragma once

#include <nanochi/cc/colors.hpp>
#include <iostream>
#include <string_view>
#include <chrono>
#include <mutex>
#include <iomanip>

namespace cloudseal {

	namespace cc = nanochi::cc;

    class logger final {
    public:
        class log_entry;
        class log_entry_debug;

        inline logger(const logger&) = delete;
        inline logger(logger&&) noexcept = delete;

        inline logger& operator=(const logger&) = delete;
        inline logger& operator=(logger&&) noexcept = delete;

        inline explicit logger(std::ostream& os) noexcept
            : os_(os)
        {
        }

        inline log_entry info() {
			return make_log_entry("info", cc::green);
        }

        inline log_entry warning() {
			return make_log_entry("warning", cc::yellow);
        }

        inline log_entry error() {
			return make_log_entry("error", cc::red);
        }

        inline log_entry_debug debug() {
            return log_entry_debug{ *this, current_time_string() };
        }

    private:
		inline log_entry make_log_entry(const char* level, const nanochi::colors::ConsoleColor& color) {
			return { *this, level, color, current_time_string() };
		}

        inline std::string current_time_string() const {
            using namespace std::chrono;

            auto now = system_clock::now();
            std::time_t now_c = system_clock::to_time_t(now);

            std::tm tm;
#if defined(_MSC_VER)
            localtime_s(&tm, &now_c);
#else
            localtime_r(&now_c, &tm);
#endif

            std::ostringstream oss{};
            oss << std::put_time(&tm, "%H:%M:%S");
            return oss.str();
        }

        std::ostream& os_;
        std::mutex mutex_;

    private:
        static constexpr bool is_debug_build() {
#if defined(DEBUG_BUILD)                  // Zdefiniowane przez CMake
            return true;
#elif defined(_DEBUG)                    // MSVC: _DEBUG w trybie debug
            return true;
#elif !defined(NDEBUG)                   // GCC/Clang: brak NDEBUG => debug
            return true;
#else
            return false;                        // Domyślnie: release
#endif
        }

		static constexpr bool is_release_build() {
			return !is_debug_build();
		}

    public:
        class log_entry {
        public:
            inline log_entry(logger& logger, std::string_view prefix, const nanochi::colors::ConsoleColor& color, const std::string& timestamp)
                : logger_(logger), lock_(logger.mutex_)
            {
                logger_.os_
                    << cc::white << '[' << cc::gray << timestamp << cc::white << "] "
                    << '[' << color << prefix << cc::white << "] "
                    << cc::reset;
            }

            inline log_entry(const log_entry&) = delete;

            inline log_entry& operator=(const log_entry&) = delete;

            inline ~log_entry() {
                logger_.os_ << std::endl;
            }

            template <typename T>
            inline log_entry& operator<<(const T& value) {
                logger_.os_ << value;
                return *this;
            }

            inline log_entry& operator<<(std::ostream& (*fn)(std::ostream&)) {
                logger_.os_ << fn;
                return *this;
            }

        private:
            logger& logger_;
            std::lock_guard<std::mutex> lock_;
        };

        class log_entry_debug {
        public:
            inline explicit log_entry_debug(logger& logger, const std::string& timestamp)
                : logger_(logger)
#if defined(DEBUG_BUILD) || defined(_DEBUG) || !defined(NDEBUG)
                , lock_(logger.mutex_)
#endif
            {
                if constexpr (is_debug_build()) {
                    logger_.os_ 
                        << cc::white << '[' << cc::gray << timestamp << cc::white << "] "
                        << cc::white << '[' << cc::blue << "debug" << cc::white << "] "
                        << cc::reset;
                }
            }

            inline log_entry_debug(const log_entry_debug&) = delete;

            inline log_entry_debug& operator=(const log_entry_debug&) = delete;

            inline ~log_entry_debug() {
                if constexpr (is_debug_build()) logger_.os_ << std::endl;
            }

            template <typename T>
            inline log_entry_debug& operator<<(const T& value) {
                if constexpr (is_debug_build()) logger_.os_ << value;
                return *this;
            }

            inline log_entry_debug& operator<<(std::ostream& (*fn)(std::ostream&)) {
                if constexpr (is_debug_build()) logger_.os_ << fn;
                return *this;
            }
        private:
            logger& logger_;
#if defined(DEBUG_BUILD) || defined(_DEBUG) || !defined(NDEBUG)
            std::lock_guard<std::mutex> lock_;
#endif
        };
    };

#if LOG_TO_FILE == 1
#include <fstream>

    inline std::ofstream _log_file("log.txt", std::ios::app);
    inline log log{ _log_file };
#else
    inline logger log{ std::cout };
#endif

} // namespace nanochi