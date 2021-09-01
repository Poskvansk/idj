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
    // bg = new Sprite("assets/img/ocean.jpg");
    // music = new Music("assets/audio/stageState.ogg");
}

void State::Render() {
    bg->Render(0,0);
}

bool State::QuitRequested() {
    return quitRequested;
}