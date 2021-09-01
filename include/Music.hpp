#ifndef _MUSIC_HPP
#define _MUSIC_HPP

#define INCLUDE_SDL_IMAGE 
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

class Music
{
    private:
        Mix_Music* music;
    public:
        Music();
        Music(const char* file);

        void Play(int times);
        void Stop(int msToStop);
        void Open(const char* file);
        bool IsOpen();
        ~Music();
};

#endif