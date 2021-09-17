#include "../include/GameObject.hpp"

#include <iostream>

GameObject::~GameObject() {

    // for (int i = components.size()-1; i >=0 ; i--) { 
    //     auto it = components.begin() + i;
    //     delete(&it);
    // }

    // Nao precisa delete, usando unique_ptr

    components.clear();
}

void GameObject::Update(float dt) {

    for (size_t i = 0; i < components.size(); i++) {
        components[i]->Update(dt);
    }
}

void GameObject::Render() {

    for (size_t i = 0; i < components.size(); i++) {
        components[i]->Render();
    }
}

bool GameObject::IsDead() {
    return isDead;
}

void GameObject::RequestDelete() {
    isDead = true;
}

void GameObject::AddComponent(Component* cpt) {

    components.emplace_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt) {
    
    for (size_t i = 0; i < components.size(); i++) {
        if (components[i].get() == cpt) {
            components.erase(components.begin() + i);
        }
    }
}

Component* GameObject::GetComponent(std::string type) {
    
    for (size_t i = 0; i < components.size(); i++) {

        if ((components[i]->Is(type) == true)) {
            return components[i].get();
        }
    }
     return nullptr;
}