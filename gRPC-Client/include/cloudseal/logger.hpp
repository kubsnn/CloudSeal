#pragma once

#include <nanochi/cc/colors.hpp>
#include <iostream>
#include <string_view>
#include <chrono>
#include <mutex>
#include <iomanip>

#if defined(DEBUG_BUILD) || \
   (defined(_MSC_VER) && defined(_DEBUG)) || \
   (!defined(_MSC_VER) && !defined(NDEBUG))

#define CLOUDSEAL_LOGGER_DEBUG
#endif


namespace cloudseal {

    namespace cc = nanochi::cc;

    class logger final {
        static consteval bool is_debug_build() {
#if defined(CLOUDSEAL_LOGGER_DEBUG)
            return true;
#else
            return false;
#endif
        }

        static consteval bool is_release_build() {
            return !is_debug_build();
        }

    public:
        class log_entry;
        class log_entry_debug;

        inline logger(const logger&) = delete;
        inline logger(logger&&) noexcept = delete;

        inline logger& operator=(const logger&) = delete;
        inline logger& operator=(logger&&) noexcept = delete;

        inline explicit logger(::std::ostream& os) noexcept
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

        inline log_entry fatal() {
            return make_log_entry("fatal", cc::bg::red);
        }

        inline log_entry_debug debug() {
            if constexpr (is_debug_build()) {
                return log_entry_debug{ *this, current_time_string() };
            }
            else {
				return log_entry_debug{ *this };
            }
        }

    private:
        inline log_entry make_log_entry(const char* level, const nanochi::colors::ConsoleColor& color) {
            return { *this, level, color, current_time_string() };
        }

        inline ::std::string_view current_time_string() const noexcept
        {
            using namespace ::std::chrono;

            // Jeden bufor na wątek ⇒ brak rywalizacji i zawsze żyje
            thread_local char buf[9];            // "HH:MM:SS\0"

            const auto  now = system_clock::now();
            ::std::time_t now_c = system_clock::to_time_t(now);

            ::std::tm tm;
#if defined(_MSC_VER)
            localtime_s(&tm, &now_c);
#else
            localtime_r(&now_c, &tm);
#endif

            // Zapisujemy w formacie 8-znakowym
            ::std::strftime(buf, sizeof(buf), "%H:%M:%S", &tm);

            // Zwracamy widok na gotowy bufor
            return { buf, 8 };                   // długość bez '\0'
        }

        ::std::ostream& os_;
        ::std::mutex mutex_;


    public:
        class log_entry {
        public:
            inline log_entry(logger& logger, std::string_view prefix, const nanochi::colors::ConsoleColor& color, std::string_view timestamp)
                : logger_(logger), lock_(logger.mutex_)
            {
                logger_.os_
                    << cc::white << '[' << cc::gray << timestamp << cc::white << "] "
                    << '[' << color << prefix << cc::reset << cc::white << "] "
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

#if defined(CLOUDSEAL_LOGGER_DEBUG)
        class log_entry_debug {
        public:
            inline explicit log_entry_debug(logger& logger, std::string_view timestamp)
                : logger_(logger)
                , lock_(logger.mutex_)
            {
                if constexpr (is_debug_build()) {
                    logger_.os_
                        << cc::white << '[' << cc::gray << timestamp << cc::white << "] "
                        << cc::white << '[' << cc::blue << "debug" << cc::white << "] "
                        << cc::reset;
                }
            }

            inline explicit log_entry_debug(logger& logger)
                : logger_(logger)
				, lock_(logger.mutex_)
            {
				if constexpr(is_debug_build()) {
					logger_.os_ << cc::white << '[' << cc::blue << "debug" << cc::white << "] " << cc::reset;
				}
            }

            inline log_entry_debug(const log_entry_debug&) = delete;
            inline log_entry_debug& operator=(const log_entry_debug&) = delete;

            inline ~log_entry_debug() {
                if constexpr (is_debug_build()) logger_.os_ << std::endl;
            }

            template <typename T>
            inline log_entry_debug& operator<<(const T& value) {
#if defined(QT_CORE_LIB)
                if constexpr (is_debug_build()) {
                    using QByteArrayType = typename std::decay<decltype(value)>::type;
                    if constexpr (std::is_same<QByteArrayType, QByteArray>::value) {
                        logger_.os_ << value.constData();
                    }
                    else {
                        logger_.os_ << value;
                    }
                }
#else
                if constexpr (is_debug_build()) logger_.os_ << value;
#endif
                return *this;
            }

            inline log_entry_debug& operator<<(std::ostream& (*fn)(std::ostream&)) {
                if constexpr (is_debug_build()) logger_.os_ << fn;
                return *this;
            }
        private:
            logger& logger_;
            std::lock_guard<std::mutex> lock_;
        };
#else
        class log_entry_debug {
        public:
            inline explicit log_entry_debug(logger&, std::string_view) noexcept
            { }

			inline explicit log_entry_debug(logger&) noexcept
			{ }

            template <typename T>
            inline const log_entry_debug& operator<<(T&&) const noexcept {
                // Nic nie robi, bo logi są odrzucane
                return *this;
            }
        };
#endif // CLOUDSEAL_LOGGER_DEBUG
    };

    // Globalna instancja loggera
#if LOG_TO_FILE == 1
    inline std::ofstream _log_file("log.txt", std::ios::app);
    inline logger _global_logger{ _log_file };
#else
    inline logger _global_logger{ std::cout };
#endif

    // Dodana funkcja get_logger()
    inline logger& get_logger() {
        return _global_logger;
    }

    // Zachowanie kompatybilności z poprzednim kodem
    inline logger& log = _global_logger;

} // namespace cloudseal

#if defined(CLOUDSEAL_LOGGER_DEBUG)
#undef CLOUDSEAL_LOGGER_DEBUG
#endif