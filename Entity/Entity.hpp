#pragma once
#include <string>

class Entity {
protected:
    std::string fullName;
    int maxHealth, maxMana, health, mana, attackPower, abilityPower, poisonedCounter;
    float guardReduction = 0.6;
    bool isGuarding, isPoisoned;

public:
    void dealDamage(int damage, Entity* entity);

    void raiseGuard();
    
    std::string getFullName();
};