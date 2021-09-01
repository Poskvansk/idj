#ifndef _SPRITE_HPP
#define _SPRITE_HPP

#define INCLUDE_SDL_IMAGE 
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Sprite
{
    private:
        SDL_Texture* texture;
        int width;
        int height;
        SDL_Rect clipRect;
    public:
        Sprite();
        Sprite(const char* file);
        ~Sprite();
        void Open(const char* file);
        void SetClip(int x, int y, int w, int h);
        void Render(int x, int y);
        int GetWidth();
        int GetHeight();
        bool IsOpen();
};
#endif