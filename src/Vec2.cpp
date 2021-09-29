#include "../include/Vec2.hpp"

Vec2 Vec2::GetRotated(float theta) {
	
	float x, y;
	x = this->x * std::cos(theta) - this->y * std::sin(theta);
	y = this->y * std::cos(theta) + this->x * std::sin(theta);

	return Vec2(x, y);
}