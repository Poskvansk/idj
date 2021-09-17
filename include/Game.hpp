#ifndef GAME_HPP
#define GAME_HPP

#define INCLUDE_SDL
#include "SDL_include.h"

#include "State.hpp"
#include <cstdlib>
#include <ctime>

class Game {
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