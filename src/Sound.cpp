#include "../include/Sound.hpp"

Sound::Sound(GameObject& associated, std::string file) : Component(associated) {
	
	 //Sound(associated);
	chunk = nullptr;
	Open(file.c_str());
}

void Sound::Play(int times) {

	times = 1;
	channel = Mix_PlayChannel(-1, chunk, times - 1);
}

void Sound::Stop() {

	if (chunk != nullptr) {
		Mix_HaltChannel(channel);
	}
}

void Sound::Open(const char* file) {

	// tratar caso n abra
	chunk = Mix_LoadWAV(file);
}

Sound::~Sound() {
	
	if (chunk != nullptr) {
		Stop();
		Mix_FreeChunk(chunk);
	}
}

bool Sound::IsOpen() {

	if (chunk != nullptr) {
		return true;
	}
	return false;
}

// funcao que verifica se o som esta tocando
bool Sound::IsPlaying() {

	if (Mix_Playing(channel)) {
		return true;
	}
	return false;
}

void Sound::Update(float dt) {
	return;
}

void Sound::Render() {
	return;
}

bool Sound::Is(std::string type) {
	if(type == "Sound") {
		return true;
	}
	return false;
}