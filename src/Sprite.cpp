#include "../include/Sprite.hpp"
#include "../include/Game.hpp"
#include <iostream>

Sprite::Sprite(GameObject& associated, const char* file) : Component(associated) {
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

    associated.box.h = height;
    associated.box.w = width;

    SetClip(0, 0, width, height);
}

void Sprite::SetClip(int x, int y, int w, int h) {
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::Render() {

    SDL_Rect dstrect;

    dstrect.x = associated.box.x;
    dstrect.y = associated.box.y;
    dstrect.w = associated.box.w;
    dstrect.h = associated.box.h;

    if (SDL_RenderCopy(Game::GetInstance().GetRenderer(), this->texture, &clipRect, &dstrect)) {
        std::cout << "Erro Render Copy" << SDL_GetError() << std::endl;
    }
}

void Sprite::Update(float dt) {

}

bool Sprite::Is(std::string type) {

    if (type == "Sprite") {
        return true;
    }
    return false;
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