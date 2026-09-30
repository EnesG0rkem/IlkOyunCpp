#include "Entity.hpp"

bool Entity::takeDamage(int damage){
    if(isGuarding) damage *= guardDamageMultipier;
    health -= damage;
    return health < 0;
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

void Entity::endOfTurn(){
    if(burningCounter > 0){
        takeDamage(burnDamage);
        burningCounter--;
        if(burningCounter == 1) burnDamage = 0;
    }
}

void Entity::startOfTurn(){
    isGuarding = false;
}

void Entity::heal(int amount){
    health = (health + amount) > maxHealth ? maxHealth : health + amount; 
}

void Entity::setOnFire(int _burnDamage){
    burningCounter = 3;
    burnDamage = _burnDamage;
}

int Entity::getHealth(){ return health; }
