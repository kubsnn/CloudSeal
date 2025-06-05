#pragma once

#include <nlohmann/json.hpp>

namespace cloudseal::qqt
{
    class IJsonSerializable
    {
    public:
        virtual ~IJsonSerializable() noexcept = default;

        // Convert the object to a JSON representation
        virtual void serialize(nlohmann::json& j) const = 0;
    };

    inline void to_json(nlohmann::json& j, const IJsonSerializable& obj)
    {
        obj.serialize(j);
    }

    inline void to_json(nlohmann::json& j, const IJsonSerializable* const& obj)
    {
        if (obj == nullptr)
        {
            j = nullptr; // or throw an exception, depending on your design choice
            return;
        }

        obj->serialize(j);
    }

    inline nlohmann::json serialized(const IJsonSerializable& obj)
    {
        nlohmann::json j;
        obj.serialize(j);
        return j;
    }

    inline nlohmann::json serialized(std::shared_ptr<const IJsonSerializable> obj)
    {
        nlohmann::json j;
        obj->serialize(j);
        return j;
    }
} // namespace cloudseal::qqt