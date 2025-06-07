#include <cloudseal/qqt/jinja/QMLJinja.hpp>

#include <cloudseal/utils/utils.hpp>
#include <nlohmann/json.hpp>
#include <fstream>
#include <stdexcept>
#include <filesystem>

// Compiler-specific pragmas to suppress warnings for inja.hpp

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wall"
#pragma clang diagnostic ignored "-Wextra"
#pragma clang diagnostic ignored "-Wpedantic"

#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wpedantic"

#elif defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4244) // conversion warnings
#pragma warning(disable : 4267)
#pragma warning(disable : 4996) // deprecated C lib functions

#endif

#include <inja/inja.hpp>

#if defined(__clang__)
#pragma clang diagnostic pop

#elif defined(__GNUC__)
#pragma GCC diagnostic pop

#elif defined(_MSC_VER)
#pragma warning(pop)

#endif

#include <cloudseal/utils/utils.hpp>

namespace {
	std::filesystem::path template_directory = cloudseal::utils::get_executable_directory() / "resources" / "templates/";

	thread_local inja::Environment environment(template_directory.string());
}

namespace cloudseal::qqt::jinja
{
    std::string process(const std::string& filename, std::shared_ptr<const Object> data)
    {
        auto template_path = template_directory / (filename + ".inja");

        std::string template_str = utils::read_file(template_path); 

        nlohmann::json json = serialized(data);

        if (json.is_null()) [[unlikely]]
        {
            throw std::runtime_error("Invalid JSON data provided.");
        }

        // Render the template with the JSON data
        return environment.render(template_str, json);
    }
} // namespace cloudseal::qqt::jainja