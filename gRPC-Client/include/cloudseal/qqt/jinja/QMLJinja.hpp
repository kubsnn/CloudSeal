#pragma once

// Standard library includes
#include <string>
#include <fstream>

// Third-party includes (BEFORE any namespace declarations)
#include <nlohmann/json.hpp>
#include <inja/inja.hpp>

// CloudSeal includes
#include <cloudseal/utils/utils.hpp>
#include <cloudseal/qqt/Object.hpp>
#include <cloudseal/logger.hpp>

namespace cloudseal::qqt
{
    class QMLJinja
    {
    public:
        QMLJinja() = default;
        virtual ~QMLJinja() = default;

        template<typename T>
        std::string process(const std::string& filename, const T& data) {
            // Prepare filename for loading
            std::string file_path = "resources\\templates\\" + filename + ".inja";
            std::string template_str = load_jinja(file_path); // Fixed: use file_path

            nlohmann::json json_data(data);
            // Check if the data is a valid JSON object
            if (json_data.is_null()) {
                throw std::runtime_error("Invalid JSON data provided.");
            }

            // Render the template with the JSON data
            return render(template_str, json_data);
        }

        std::string load_jinja(const std::string& template_file_path) const // Renamed parameter for clarity
        {
            std::ifstream file(template_file_path);
            if (!file.is_open()) {
                throw std::runtime_error("Unable to open template file: " + template_file_path);
            }
            std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
            return content;
        }

        std::string render(const std::string& template_str, const nlohmann::json& data) const
        {
            inja::Environment env("resources/templates/");
            return env.render(template_str, data);
        }
    };
} // namespace cloudseal::qqt