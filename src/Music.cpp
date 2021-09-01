#include "Music.hpp"
#include <iostream>

Music::Music() {
    music = nullptr;
}

Music::Music(const char* file) {
    Music();
    if (music == nullptr) {
        Open(file);
    }
    else {
        std::cout << "music not null" << std::endl;
    }
}

void Music::Play(int times) {

    if (music != nullptr) {
        Mix_PlayMusic(music, times);
    }
}

void Music::Stop(int msToStop) {
    
    if (music != nullptr) {
        Mix_FadeOutMusic(msToStop);
    }
}

void Music::Open(const char* file) {

    music = Mix_LoadMUS(file);

    if (music == nullptr) {
        std::cout << "Erro LoadMUS nullptr: " << SDL_GetError() << std::endl;
        std::cin.get();
    }
}

bool Music::IsOpen() {
    if (music == nullptr) {
        return true;
    }
    return false;
}

Music::~Music() {
    Stop(1500);
    Mix_FreeMusic(music);
}