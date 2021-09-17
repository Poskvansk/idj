#include "../include/Vec2.hpp"

Vec2 Vec2::GetRotated(float theta) {
	
	x = x * std::cos(theta) - y * std::sin(theta);
	y = y * std::cos(theta) + x * std::sin(theta);

	return Vec2(x, y);
}