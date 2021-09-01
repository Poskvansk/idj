#include "Sprite.hpp"
#include "Game.hpp"
#include <iostream>

Sprite::Sprite() {
    texture = nullptr;
}

Sprite::Sprite(const char* file) {

    texture = nullptr;
    Open(file);
}

Sprite::~Sprite() {
    SDL_DestroyTexture(texture);
}

void Sprite::Open(const char* file) { 

    if (texture == nullptr) {

        texture =  IMG_LoadTexture(Game::GetInstance().GetRenderer(), file);
    }
    else {

        SDL_DestroyTexture(texture);

        texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file);
        if (texture == nullptr) {
            std::cout << "Texture == nullptr !!!" << SDL_GetError() << std::endl;
            std::cin.get();
        }
    }

    if (SDL_QueryTexture(texture, nullptr, nullptr, &width, &height)) {
        std::cout << "SDL_Query Error: " << SDL_GetError() << std::endl;
        std::cin.get();
    }

    SetClip(0, 0, width, height);
}

void Sprite::SetClip(int x, int y, int w, int h) {
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::Render(int x, int y) {
    SDL_Rect dstrect;
    dstrect.x = x;
    dstrect.y = y;
    dstrect.w = clipRect.w;
    dstrect.h = clipRect.h;

    if(SDL_RenderCopy(Game::GetInstance().GetRenderer(), this->texture, &clipRect, &dstrect)) {
        std::cout << "Erro Render Copy" << SDL_GetError() << std::endl;
    }
}

int Sprite::GetWidth() {
    return width;
}

int Sprite::GetHeight() {
    return height;
}

bool Sprite::IsOpen() {
    
    if (texture != nullptr) {
        return true;
    }
    return false;
}