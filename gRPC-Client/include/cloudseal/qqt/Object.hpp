#pragma once
#include <cloudseal/qqt/IJsonSerializable.hpp>
#include <cloudseal/utils/utils.hpp>
#include <cloudseal/qqt/Layout.hpp>
#include <cloudseal/qqt/structures/Size.hpp>
#include <cloudseal/qqt/structures/Point.hpp>
#include <cloudseal/qqt/CallbacksStorage.hpp>
#include <cloudseal/qqt/Callbacks.hpp>
#include <string>
#include <optional>
#include <vector>
#include <memory>

namespace cloudseal::qqt
{
    namespace builders
    {
        template <typename TObject, typename TBuilder>
        class ObjectBuilder;
    }

    class Loader;

    class Object : public IJsonSerializable
    {
    public:
        template <typename, typename>
        friend class cloudseal::qqt::builders::ObjectBuilder;
        friend class cloudseal::qqt::Loader;

        inline Object(const std::string &type)
            : id(utils::generate_uuid()), type_(type) {}

        virtual ~Object() noexcept = default;

        const std::string &type() const noexcept;

        const std::string &uuid() const noexcept;

        virtual void addChild(const std::shared_ptr<Object> &child);

        virtual void addChild(Object &&child);

        virtual const std::vector<std::shared_ptr<Object>> &getChildren() const noexcept;

        std::vector<std::shared_ptr<Object>> releaseChildren() noexcept;

        std::shared_ptr<Callbacks> releaseCallbacks() noexcept;

        virtual void serialize(nlohmann::json &j) const override;

        const std::string &getQMLString() const noexcept;

        void setCallbacks(std::shared_ptr<Callbacks> callbacks) noexcept;

    private:
        std::string id;
        std::string type_ = "Object";
        std::shared_ptr<Callbacks> callbacks_;

    protected:
        std::vector<std::shared_ptr<Object>> children;

        std::optional<std::string> color;
        std::optional<std::string> colorOnHover;
        std::optional<std::string> colorOnPress;
        std::optional<Layout> layout;

        std::string qmlString;

        Size size;
        Point position;

        bool visible = true;
    };

    inline nlohmann::json serialized(const Object &obj)
    {
        nlohmann::json j;
        obj.serialize(j);
        return j;
    }

    inline nlohmann::json serialized(std::shared_ptr<const Object> obj)
    {
        nlohmann::json j;
        obj->serialize(j);
        return j;
    }
}