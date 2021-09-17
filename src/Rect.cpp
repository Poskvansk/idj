#include "../include/Rect.hpp"

bool Rect::Contains(Vec2 p) {

	if (p.x < this->x || p.y < this->y) {
		return false;
	}

	if (p.x > (this->x + this->w) || p.y > (this->y + this->h)) {
		return false;
	}

	return true;
}