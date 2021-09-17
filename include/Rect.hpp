#ifndef RECT_HPP
#define RECT_HPP

#include "Vec2.hpp"

class Rect {
    
    public:

        float x, y, w, h;

        Rect()
            : x(0), y(0), w(0), h(0) {}

        Rect(float x, float y, float w, float h)
            : x(x), y(y), w(w), h(h) {}

  
        bool Contains(Vec2 p);
};

#endif