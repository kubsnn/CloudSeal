#pragma once
#include <cloudseal/utils/utils.hpp>
#include <nlohmann/json.hpp>
#include <string>
#include <optional>
#include <vector>
#include <memory>
#include <cloudseal/qqt/Layout.hpp>
#include <cloudseal/qqt/structures/Size.hpp>
#include <cloudseal/qqt/structures/Point.hpp>
#include <cloudseal/qqt/builders/ObjectBuilder.hpp>
#include <cloudseal/qqt/IJsonSerializable.hpp>
#include <cloudseal/qqt/QFunctions.hpp>
#include <cloudseal/qqt/Callbacks.hpp>

namespace cloudseal::qqt
{
    class Loader;
    class Object : public IJsonSerializable
    {
    public:
        friend class cloudseal::qqt::builders::ObjectBuilder<Object>;
        friend class cloudseal::qqt::Loader;

        Object(const std::string &type)
            : id(utils::generate_uuid()), type_(type) {}
        virtual ~Object() = default;

        // NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(
        //     Object,
        //     id,
        //     visible,
        //     size,
        //     position,
        //     layout,
        //     type_
        // )

        const std::string &type() const
        {
            return type_;
        }

        const std::string &uuid() const
        {
            return id;
        }

        virtual void addChild(const std::shared_ptr<Object> &child)
        {
            children.push_back(child);
        }

        virtual void addChild(Object &&child)
        {
            children.push_back(std::make_shared<Object>(std::move(child)));
        }

        virtual const std::vector<std::shared_ptr<Object>> &getChildren() const
        {
            return children;
        }

        std::vector<std::shared_ptr<Object>> releaseChildren()
        {
            std::vector<std::shared_ptr<Object>> c = std::move(children);
            children.clear();
            children.shrink_to_fit();
            return c;
        }

        inline std::shared_ptr<Callbacks> releaseCallbacks()
        {
            if (callbacks_)
            {
                auto cb = std::move(callbacks_);
                callbacks_.reset();
                return cb;
            }
            return nullptr;
        }

        virtual void serialize(nlohmann::json &j) const override
        {
            j = nlohmann::json{
                {"id", id},
                {"visible", visible},
                {"size", size},
                {"position", position},
                {"layout", layout},
                {"type", type_}};
        }
        
        inline const std::string &getQMLString() const
        {
            return qmlString;
        }

        inline void setCallbacks(std::shared_ptr<Callbacks> callbacks)
        {
            callbacks_ = std::move(callbacks);
        }

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

}