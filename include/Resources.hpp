#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"

#include "Game.hpp"

#include <unordered_map>
#include <string>

class Resources {
    private:
        static std::unordered_map< const char*, SDL_Texture*> imageTable;
        static std::unordered_map< const char*, Mix_Music*> musicTable;
        static std::unordered_map< const char*, Mix_Chunk*> soundTable;
    public:
        // Resources(/* args */);
        // ~Resources();

        static SDL_Texture* GetImage( const char* file);
        static void ClearImages();

        static Mix_Music* GetMusic( const char* file);
        static void ClearMusics();

        static Mix_Chunk* GetSound( const char* file);
        static void ClearSounds();
};

#endif