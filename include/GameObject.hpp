#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include "Component.hpp"
#include "Rect.hpp"

#include <string>
#include <algorithm>
#include <vector>
#include <memory>

class Component;

class GameObject {
    private:
        std::vector<std::unique_ptr<Component>> components;
        bool isDead;

    public:
        Rect box;

        GameObject()
            : isDead(false) {}

        ~GameObject();

        void Update(float dt);
        void Render();
        bool IsDead();
        void RequestDelete();
        void AddComponent(Component* cpt);
        void RemoveComponent(Component* cpt);
        Component* GetComponent(std::string type);   
};

#endif