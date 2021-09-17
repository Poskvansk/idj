#ifndef SPRITE_HPP
#define SPRITE_HPP

#define INCLUDE_SDL_IMAGE 
#include "SDL_include.h"

#include "Component.hpp"

class Sprite : public Component {
    private:
        SDL_Texture* texture;
        int width;
        int height;
        SDL_Rect clipRect;

    public:
        Sprite(GameObject& associated)
            : Component(associated), texture(nullptr) {};

        Sprite(GameObject& associated, const char* file);
        ~Sprite();

        void Open(const char* file);
        void SetClip(int x, int y, int w, int h);
        int GetWidth();
        int GetHeight();
        bool IsOpen();

        void Render() override;
        void Update(float dt) override;
        bool Is(std::string type) override;
};
#endif