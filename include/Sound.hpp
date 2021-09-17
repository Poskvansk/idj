#ifndef SOUND_HPP
#define SOUND_HPP

#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

#include "Component.hpp"
// #include <string>

class Sound : public Component {

	private:
		Mix_Chunk* chunk;
		int channel;
	
	public:

		Sound(GameObject& associated)
			: Component(associated), chunk(nullptr) {}

		Sound(GameObject& associated, std::string file);

		~Sound();

		void Play(int times);
		void Stop();
		void Open(const char* file);
		bool IsOpen();

		void Update(float dt) override;
		void Render() override;
		bool Is(std::string type) override;

		bool IsPlaying();
};

#endif