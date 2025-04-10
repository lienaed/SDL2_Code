#pragma once
#include "Frame.hpp"
#include "OOP/GameObject.hpp"

class ObjectManager
{
    private:
        std::vector <GameObject*> objects;
        std::unordered_map <std::string, GameObject*> names;
        std::unordered_multimap <std::string, GameObject*> tags;

    public:
        void addObject (GameObject* obj);

        GameObject* findObject (const std::string& name);
        std::vector <GameObject*> findObjectType (const std::string& tag);

        void updateAll();
        void drawAll();
};