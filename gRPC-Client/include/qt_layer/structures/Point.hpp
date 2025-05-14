#pragma once

namespace cloudseal::qt_layer
{
    struct Point
    {
        int x = 0;
        int y = 0;
    };
    MY_JSON_INTRUSIVE(Point, x, y)
}