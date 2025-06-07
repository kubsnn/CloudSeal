#pragma once

#include <filesystem>
#include <string>

#if defined(DEBUG_BUILD) || \
   (defined(_MSC_VER) && defined(_DEBUG)) || \
   (!defined(_MSC_VER) && !defined(NDEBUG))

#define CLOUDSEAL_DEBUG_ENABLED
#endif

namespace cloudseal::utils {


#if defined(CLOUDSEAL_DEBUG_ENABLED)
	inline static constexpr bool is_debug_build = true;
#else
	inline static constexpr bool is_debug_build = false;
#endif
	
	inline static constexpr bool is_release_build = !is_debug_build;

	// Zwraca UUID v4 w postaci std::string
	std::string generate_uuid();

	// Zwraca sciezke do katalogu, w ktorym znajduje sie plik wykonywalny
	std::filesystem::path get_executable_directory();

	std::string read_file(const std::filesystem::path& path);

	std::string read_file(const std::string& path);
} // namespace cloudseal::utils

#if defined(CLOUDSEAL_DEBUG_ENABLED)
#undef CLOUDSEAL_DEBUG_ENABLED
#endif