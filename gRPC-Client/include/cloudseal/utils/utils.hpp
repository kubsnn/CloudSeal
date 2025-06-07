#pragma once

#include <filesystem>
#include <string>

namespace cloudseal::utils {

	// Zwraca UUID v4 w postaci std::string
	std::string generate_uuid();

	// Zwraca sciezke do katalogu, w ktorym znajduje sie plik wykonywalny
	std::filesystem::path get_executable_directory();

	std::string read_file(const std::filesystem::path& path);

	std::string read_file(const std::string& path);
} // namespace cloudseal::utils
