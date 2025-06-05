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

namespace cloudseal::qqt::jinja
{
    std::string QMLJinja::process(const std::string &filename, std::shared_ptr<const Object> data)
    {
        // Prepare filename for loading
        std::filesystem::path template_path("resources");
        template_path /= "templates";
        template_path /= filename + ".inja";
        std::string file_path = template_path.string();
        std::string template_str = load_jinja(file_path); // Fixed: use file_path

        nlohmann::json json_data = serialized(data); // Serialize the Object to JSON
        // Check if the data is a valid JSON object
        if (json_data.is_null())
        {
            throw std::runtime_error("Invalid JSON data provided.");
        }

        // Render the template with the JSON data
        return render(template_str, json_data);
    }

    std::string QMLJinja::load_jinja(const std::string &template_file_path) const // Renamed parameter for clarity
    {
        std::ifstream file(template_file_path);
        if (!file.is_open())
        {
            throw std::runtime_error("Unable to open template file: " + template_file_path);
        }
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        return content;
    }

    std::string QMLJinja::render(const std::string &template_str, const nlohmann::json &data) const
    {
        inja::Environment env("resources/templates/");
        return env.render(template_str, data);
    }
} // namespace cloudseal::qqt::jainja