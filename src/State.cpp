#include "State.hpp"
#include <iostream>

State::State() {

    quitRequested = false;
    bg = new Sprite("assets/img/ocean.jpg");
    music = new Music("assets/audio/stageState.ogg");
    music->Play(-1);
}

void State::Update(float dt) {
    
    if (SDL_QuitRequested()) {
        quitRequested = true;
    }
}

void State::LoadAssets() {
    //std::cout << &this->music << std::endl;
    //std::cout << &this->bg << std::endl;
    //this->music = new Music("stageState.ogg");
    //this->bg = new Sprite();
}

void State::Render() {
    bg->Render(0,0);
}

bool State::QuitRequested() {
    return quitRequested;
}