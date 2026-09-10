#include <string>
#include "Entity.hpp"

    void Entity::dealDamage(int damage, Entity* entity){
        if (entity->isGuarding) damage *= guardReduction;
            entity->health -= damage;
    }

    void Entity::raiseGuard() { isGuarding = true; }

    std::string Entity::getFullName() { return fullName; }