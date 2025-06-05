#include <cloudseal/qqt/Object.hpp>

namespace cloudseal::qqt
{
    const std::string& Object::type() const
    {
        return type_;
    }

    const std::string& Object::uuid() const
    {
        return id;
    }

    void Object::addChild(const std::shared_ptr<Object>& child)
    {
        children.push_back(child);
    }

    void Object::addChild(Object&& child)
    {
        children.push_back(std::make_shared<Object>(std::move(child)));
    }

    const std::vector<std::shared_ptr<Object>>& Object::getChildren() const
    {
        return children;
    }

    std::vector<std::shared_ptr<Object>> Object::releaseChildren()
    {
        std::vector<std::shared_ptr<Object>> c = std::move(children);
        children.clear();
        children.shrink_to_fit();
        return c;
    }

    std::shared_ptr<Callbacks> Object::releaseCallbacks()
    {
        if (callbacks_)
        {
            auto cb = std::move(callbacks_);
            callbacks_.reset();
            return cb;
        }
        return nullptr;
    }

    void Object::serialize(nlohmann::json& j) const
    {
        j = nlohmann::json{
            {"id", id},
            {"visible", visible},
            {"size", size},
            {"position", position},
            {"layout", layout},
            {"type", type_} ,
            {"color", color},
            {"colorOnHover", colorOnHover},
            {"colorOnPress", colorOnPress}
        };
    }

    const std::string& Object::getQMLString() const
    {
        return qmlString;
    }

    void Object::setCallbacks(std::shared_ptr<Callbacks> callbacks)
    {
        callbacks_ = std::move(callbacks);
    }

} // namespace cloudseal::qqt