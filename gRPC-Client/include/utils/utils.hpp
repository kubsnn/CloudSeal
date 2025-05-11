#pragma once

#include <string>
#include <nlohmann/json.hpp>

#define MY_JSON_INTRUSIVE_WITH_BASE(BaseType, ThisType, ...)                            \
    friend void to_json(nlohmann::json& j, const ThisType& t) {                         \
        j = static_cast<const BaseType&>(t);                                            \
        j.update(nlohmann::json{ {# __VA_ARGS__, t.__VA_ARGS__} ... });                 \
    }                                                                                   \
                                                                                        \
    friend void from_json(const nlohmann::json& j, ThisType& t) {                       \
        j.get_to(static_cast<BaseType&>(t));                                            \
        (j.at(#__VA_ARGS__).get_to(t.__VA_ARGS__), ...);                                \
    }

#define MY_JSON_INTRUSIVE(Type, ...)                                           \
    friend void to_json(nlohmann::json& j, const Type& t) {                    \
        j = nlohmann::json{ __VA_ARGS__ };                                     \
    }                                                                          \
    friend void from_json(const nlohmann::json& j, Type& t) {                  \
        (j.at(std::string_view{#__VA_ARGS__}).get_to(t.__VA_ARGS__), ...);     \
    } 

namespace cloudseal::utils {

// Zwraca UUID v4 w postaci std::string
std::string generate_uuid();

} // namespace cloudseal::utils