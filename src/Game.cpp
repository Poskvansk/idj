#include "../include/Game.hpp"
#include "../include/Resources.hpp"
#include <iostream>

Game* Game::instance = nullptr;

Game::Game(int width, int height, const char* title) {

    if (instance != nullptr) {
        std::cout << "ERRO: Ja existe uma instancia de Game!" << std::endl;
        std::cin.get();
    }
    else {
        instance = this;
    }

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)) {
        std::cout << "Erro ao inicializar SDL" << SDL_GetError() << std::endl;
        std::cin.get();
    }
    if (!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF)) {
        std::cout << "Erro IMG_Init" << SDL_GetError() << std::endl;
        std::cin.get();
    }

    if (!Mix_Init(MIX_INIT_OGG)) {
        std::cout << "Erro Mix_init" << SDL_GetError() << std::endl;
        std::cin.get();
    }

    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)) {
        std::cout << "Erro ao inicializar OpenAudio" << SDL_GetError() << std::endl;
    }
    Mix_AllocateChannels(32);

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (window == nullptr) {
        std::cout << "Falha na inicializacao da janela!" << std::endl;
        std::cin.get();
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == nullptr) {
        std::cout << "Falha na inicializacao do renderizador!" << std::endl;
        std::cin.get();
    }
    
    srand(time(NULL));
    state = new State();
}

Game::~Game() {
    SDL_DestroyRenderer(renderer);

    SDL_DestroyWindow(window);

    Mix_CloseAudio();
    Mix_Quit();

    IMG_Quit();

    SDL_Quit();
}

void Game::Run() {

    while (!state->QuitRequested()) {
        state->Update(0);
        state->Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
    
    Resources::ClearImages();
    Resources::ClearMusics();
    Resources::ClearSounds();
}

State& Game::GetState() {
    return *state;
}

Game& Game::GetInstance() {
    if (instance != nullptr) {
        return *instance;
    }
    instance = new Game(1024, 600, "Luis Filipe Siqueira Ribeiro 180053906");
    return *instance;
}

SDL_Renderer* Game::GetRenderer() {
    return renderer;
}
