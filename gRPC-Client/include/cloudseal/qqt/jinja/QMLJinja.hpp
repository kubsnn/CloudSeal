#pragma once

#include <cloudseal/qqt/Object.hpp>
#include <nlohmann/json.hpp>
#include <filesystem>
#include <string>

namespace cloudseal::qqt::jinja
{
	std::string process(const std::string& filename, std::shared_ptr<const Object> data);
} // namespace cloudseal::qqt