#ifndef STATE_HPP
#define STATE_HPP

#include <vector>
#include <memory>
#include "Vec2.hpp"
#include "GameObject.hpp"
#include "Face.hpp"
#include "Sound.hpp"
#include "Sprite.hpp"
#include "Music.hpp"

class State {
    private:
        Sprite* bg;
        Music* music;
        bool quitRequested;
        std::vector<std::unique_ptr<GameObject>> objectArray;
    public:

        State();
        ~State();

        bool QuitRequested();
        void LoadAssets();
        void Update(float dt);
        void Render();
        void Input();
        void AddObject(int mouseX, int mouseY);
};

#endif