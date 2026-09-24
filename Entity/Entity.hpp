#pragma once
#include <string>

class Entity {
protected:
    std::string fullName;
    int maxHealth, maxMana, health, mana, 
        attackPower, abilityPower, weight,
        poisonedCounter = 0;
    float guardDamageMultipier = 0.6;

public:
    bool isGuarding = false, isPoisoned = false;

public:
    virtual bool takeDamage(int damage);

    virtual void raiseGuard();
    
    virtual std::string getFullName();

    virtual void getPoisoned();

    int randomizer(int lowest, int highest);

    virtual void endOfTurn();

    virtual void startOfTurn();
};