#include "Entity.hpp"

void Entity::takeDamage(int damage){
    if(isGuarding) damage *= guardDamageMultipier;
    health -= damage;
}

void Entity::raiseGuard() { isGuarding = true; }

std::string Entity::getFullName() { return fullName; }

void Entity::getPoisoned(){
    isPoisoned = true;
    poisonedCounter = 3;
}

int Entity::randomizer(int lowest, int highest){
    srand(time(0));
    int interval = highest - lowest;
    return rand() % interval + lowest;
}
