#include "Entity.hpp"

bool Entity::takeDamage(int damage){ return false; }

int Entity::calculateDamage(int damage){
    if(guarding) damage *= guardDamageMultipier;
    return damage;
}

void Entity::raiseGuard() { guarding = true; }

bool Entity::isGuarding() { return guarding; }

std::string Entity::getFullName() { return fullName; }

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
    guarding = false;
}

void Entity::heal(int amount){
    health = (health + amount) > maxHealth ? maxHealth : health + amount; 
}

void Entity::setOnFire(int _burnDamage){
    burningCounter += 3;
    burnDamage = _burnDamage;
}

bool Entity::isOnFire(){ return burningCounter > 0; }

int Entity::getBurnDamage(){ return burnDamage; }

int Entity::getHealth(){ return health; }

void Entity::becomePoisoned(){
    isPoisonedCounter += 3;
}

bool Entity::isPoisoned(){ return isPoisonedCounter > 3; }

void Entity::lowerGuard(){ guarding = false; }
