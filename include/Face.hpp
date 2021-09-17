#ifndef FACE_HPP
#define FACE_HPP

#include "Component.hpp"
#include "Sound.hpp"

class Face : public Component {

	private:
		int hitpoints;

	public:

		Face(GameObject& associated) 
			: Component(associated), hitpoints(30) {};

		~Face ();

		void Damage(int damange);

		void Update(float dt) override;
		void Render() override;
		bool Is(std::string type) override;
};

#endif
