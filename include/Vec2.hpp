#ifndef VEC2_HPP
#define VEC2_HPP

#include <cmath>

class Vec2 {

    public:

        float x, y;

        Vec2()
            : x(0), y(0) {}

        Vec2(float x, float y)
            : x(x), y(y) {}

        Vec2 GetRotated(float theta);

        Vec2 operator+(const Vec2& v1) const
        {
            return Vec2(x + v1.x, y + v1.y);
        }
};

#endif