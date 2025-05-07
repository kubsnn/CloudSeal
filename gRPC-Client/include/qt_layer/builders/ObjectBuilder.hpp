#pragma once
#include <qt_layer/Layout.hpp>
#include <qt_layer/Object.hpp>
#include <qt_layer/structures/Size.hpp>
#include <qt_layer/structures/Point.hpp>

namespace cloudseal::qt_layer {
    class Object;
}

namespace cloudseal::qt_layer::builders
{
    template <typename TObject>
    class ObjectBuilder
    {
    public:
        ObjectBuilder() = default;
        virtual ~ObjectBuilder() = default;

        inline virtual TObject build() const final {return object_;}

        inline virtual ObjectBuilder& visible(bool visible) final
        {
            object_.visible_ = visible;
            return *this;
        }
        inline virtual ObjectBuilder& size(const Size& size) final
        {
            object_.size_ = size;
            return *this;
        }
        inline virtual ObjectBuilder& position(const Point& position) final
        {
            object_.position_ = position;
            return *this;
        }
        inline virtual ObjectBuilder& anchors(const Anchors& anchors) final
        {
            object_.layout_.anchors_ = anchors;
            return *this;
        }
        inline virtual ObjectBuilder& padding(const Padding& padding) final
        {
            object_.layout_.padding_ = padding;
            return *this;
        }
        inline virtual ObjectBuilder& inset(const Inset& inset) final
        {
            object_.layout_.inset_ = inset;
            return *this;
        }
        inline virtual ObjectBuilder& margin(const Margin& margin) final
        {
            object_.layout_.margin_ = margin;
            return *this;
        }
    protected:
        TObject object_;
    };
} // namespace cloudseal::qt_layer