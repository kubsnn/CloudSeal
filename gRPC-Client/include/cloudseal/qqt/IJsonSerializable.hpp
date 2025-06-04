#pragma once

#include <nlohmann/json.hpp>

namespace cloudseal::qqt
{
    class IJsonSerializable
    {
    public:
        virtual ~IJsonSerializable() = default;

        // Convert the object to a JSON representation
        virtual void serialize(nlohmann::json& j) const = 0;
    };

    void to_json(nlohmann::json& j, const IJsonSerializable& obj)
    {
        obj.serialize(j);
    }

    void to_json(nlohmann::json& j, const IJsonSerializable* const& obj)
    {
        if (obj)
        {
            obj->serialize(j);
        }
        else
        {
            j = nullptr; // or throw an exception, depending on your design choice
        }
    }
} // namespace cloudseal::qqt