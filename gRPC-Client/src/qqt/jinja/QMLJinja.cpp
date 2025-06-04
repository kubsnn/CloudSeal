#include <cloudseal/qqt/jinja/QMLJinja.hpp>

#include <cloudseal/utils/utils.hpp>
#include <nlohmann/json.hpp>
#include <inja/inja.hpp>
#include <fstream>
#include <stdexcept>

namespace cloudseal::qqt::jinja
{
    std::string QMLJinja::process(const std::string &filename, std::shared_ptr<const Object> data)
    {
        // Prepare filename for loading
        std::string file_path = "resources\\templates\\" + filename + ".inja";
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