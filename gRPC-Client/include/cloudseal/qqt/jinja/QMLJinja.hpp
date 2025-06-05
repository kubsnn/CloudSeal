#pragma once

// Standard library includes
#include <string>
#include <cloudseal/qqt/Object.hpp>
#include <nlohmann/json.hpp>

namespace cloudseal::qqt::jinja
{
    class QMLJinja
    {
    public:
        QMLJinja() = default;
        virtual ~QMLJinja() noexcept = default;

        std::string process(const std::string &filename, std::shared_ptr<const Object> data);

        std::string load_jinja(const std::string &template_file_path) const;

        std::string render(const std::string &template_str, const nlohmann::json &data) const;
    };
} // namespace cloudseal::qqt