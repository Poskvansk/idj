#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP

#include <string>

class GameObject;

class Component {
    protected:
        GameObject& associated;
    public:
        Component(GameObject& associated);
        virtual ~Component();

        void virtual Update(float dt) = 0;
        void virtual Render() = 0;
        bool virtual Is(std::string type) = 0;
};

#endif