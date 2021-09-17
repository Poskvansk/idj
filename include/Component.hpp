#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "GameObject.hpp"
#include <string>

class GameObject;

class Component {
    protected:
        GameObject &associated;
    public:
        Component(GameObject &associated)
            : associated(associated) {}

        virtual ~Component();

        void virtual Update(float dt) = 0;
        void virtual Render() = 0;
        bool virtual Is(std::string type) = 0;
};

#endif