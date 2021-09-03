#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include "Component.hpp"
#include "Rect.hpp"
#include <string>
#include <vector>

class GameObject {
    private:
        std::vector<Component*> components;
        bool isDead;
    public:
        Rect box;

        GameObject();
        ~GameObject();

        void Update();
        void Render();
        bool IsDead();
        void RequestDelete();
        void AddComponent(Component* cpt);
        void RemoveComponent(Component* cpt);
        Component* GetComponent(std::string type);   
};

#endif