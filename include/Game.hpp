#ifndef GAME_HPP
#define GAME_HPP

#define INCLUDE_SDL_IMAGE 
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

#include <SDL2/SDL.h>
#include "State.hpp"

class Game
{
    private:
        static Game* instance;
        SDL_Window* window;
        SDL_Renderer* renderer;
        State* state;
        Game(int width, int height, const char* title);
    public:
        ~Game();
        void Run();
        State& GetState();
        static Game& GetInstance();
        SDL_Renderer* GetRenderer();
};
#endif