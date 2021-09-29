#include "../include/Sprite.hpp"
#include "../include/Game.hpp"
#include "../include/Resources.hpp"
#include <iostream>

Sprite::Sprite(GameObject& associated, const char* file) : Component(associated) {
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite() {

}

void Sprite::Open(const char* file) { 

    texture = Resources::GetImage(file);
    if (texture == nullptr) {
        std::cout << "Texture == nullptr !!!" << SDL_GetError() << std::endl;
        std::cin.get();
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
    
    // std::cout << clipRect.x << " " << clipRect.y << " " <<  clipRect.w << " " << clipRect.h << std::endl;
    
}

void Sprite::Render() {
    // std::cout << associated.box.x << " " << associated.box.y << " " <<  associated.box.w << " " << associated.box.h << std::endl;
    Render(associated.box.x, associated.box.y);
}

void Sprite::Render(float x, float y) {

    // std::cout << x << " " << y << " " <<  w << " " << h << std::endl;
    SDL_Rect dstrect;

    dstrect.x = x;
    dstrect.y = y;
    dstrect.w = clipRect.w;
    dstrect.h = clipRect.h;

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