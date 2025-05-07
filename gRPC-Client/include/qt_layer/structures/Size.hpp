#pragma once

namespace cloudseal::qt_layer
{
    struct Size
    {
        int width = 0;
        int height = 0;
    };
    MY_JSON_INTRUSIVE(Size, width, height)
}