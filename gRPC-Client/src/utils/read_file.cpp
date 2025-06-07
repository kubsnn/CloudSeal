#include <cloudseal/utils/utils.hpp>
#include <fstream>
#include <stdexcept>

namespace cloudseal::utils {
	std::string read_file(const std::filesystem::path& path) {
        std::ifstream file(path);

        if (!file.is_open()) [[unlikely]] {
            throw std::runtime_error("Unable to open file: " + path.string());
        }

        return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	}

	std::string read_file(const std::string& path) {
        std::ifstream file(path);

        if (!file.is_open()) [[unlikely]] {
            throw std::runtime_error("Unable to open file: " + path);
        }

        return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    }
}