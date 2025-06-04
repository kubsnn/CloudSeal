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
        template <typename TObject>
        class ObjectBuilder;
    }

    class Loader;

    class Object : public IJsonSerializable
    {
    public:
        friend class cloudseal::qqt::builders::ObjectBuilder<Object>;
        friend class cloudseal::qqt::Loader;

        Object(const std::string &type)
            : id(utils::generate_uuid()), type_(type) {}

        virtual ~Object() = default;

        const std::string &type() const;

        const std::string &uuid() const;

        virtual void addChild(const std::shared_ptr<Object> &child);

        virtual void addChild(Object &&child);

        virtual const std::vector<std::shared_ptr<Object>> &getChildren() const;

        std::vector<std::shared_ptr<Object>> releaseChildren();

        std::shared_ptr<Callbacks> releaseCallbacks();

        virtual void serialize(nlohmann::json &j) const override;

        const std::string &getQMLString() const;

        void setCallbacks(std::shared_ptr<Callbacks> callbacks);

    protected:
        bool visible = true;
        Size size;
        Point position;
        std::string qmlString;
        std::optional<Layout> layout;
        std::vector<std::shared_ptr<Object>> children;

    private:
        std::string id;
        std::string type_ = "Object";
        std::shared_ptr<Callbacks> callbacks_;
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