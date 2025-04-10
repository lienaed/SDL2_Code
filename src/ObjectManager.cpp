#include "ObjectManager.hpp"

void ObjectManager::addObject (GameObject* obj)
{
    objects.emplace_back (obj);
    names.emplace (obj->name, obj);
    tags.emplace (obj->tag, obj);
}

GameObject* ObjectManager::findObject (const std::string& name)
{
    auto obj = names.find (name);
    return obj != names.end() ? obj->second : nullptr;
}

std::vector <GameObject*> ObjectManager::findObjectType (const std::string& tag)
{
    std::vector <GameObject*> result;
    auto range = tags.equal_range (tag);
    for (auto i = range.first; i != range.second; ++i)
        result.emplace_back (i->second);
        
    return result;
}

void ObjectManager::updateAll()
{
    for (auto o : objects)
        o -> update();
}

void ObjectManager::drawAll()
{
    for (auto o : objects)
        o -> draw();
}