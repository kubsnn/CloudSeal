#include <cloudseal/utils/utils.hpp>
#include <optional>
#include <string>

#if defined(_WIN32)
#include <windows.h>
#elif defined(__APPLE__)
#include <mach-o/dyld.h>
#elif defined(__linux__)
#include <unistd.h>
#endif

namespace {
	std::optional<std::filesystem::path> executable_directory_cache = std::nullopt;
}

namespace cloudseal::utils {

    std::filesystem::path get_executable_directory() {
		if (executable_directory_cache.has_value()) {
			return executable_directory_cache.value();
		}

        std::filesystem::path exePath;

#if defined(_WIN32)
        char buffer[MAX_PATH];
        DWORD length = GetModuleFileNameA(NULL, buffer, MAX_PATH);
        exePath = std::string(buffer, length);
#elif defined(__APPLE__)
        char buffer[1024];
        uint32_t size = sizeof(buffer);
        if (_NSGetExecutablePath(buffer, &size) == 0) {
            exePath = std::string(buffer);
        }
        else {
            throw std::runtime_error("Buffer too small for executable path on macOS");
        }
#elif defined(__linux__)
        char buffer[1024];
        ssize_t length = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);
        if (length == -1) {
            throw std::runtime_error("Cannot read /proc/self/exe");
        }
        buffer[length] = '\0';
        exePath = std::string(buffer);
#else
        static_assert(false, "Unsupported platform");
#endif

        executable_directory_cache = exePath.parent_path();

		return executable_directory_cache.value();
    }

} // namespace cloudseal::utils