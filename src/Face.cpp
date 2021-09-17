#include "../include/Face.hpp"

Face::~Face() {

}

void Face::Update(float dt) {

}

void Face::Damage(int damage) {

	hitpoints -= damage;

	if (hitpoints <= 0) {
		
		associated.RequestDelete();

		if (associated.GetComponent("Sound") != nullptr) {

			Sound* sound = (Sound*)associated.GetComponent("Sound");
			sound->Play(-1);
		}
	}
}

void Face::Render() {

}

bool Face::Is(std::string type) {

	if (type == "Face") {
		return true;
	}
	return false;
}