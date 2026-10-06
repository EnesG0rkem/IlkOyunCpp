#pragma once
#include <string>

class Entity {
protected:
    std::string fullName;
    int maxHealth, maxMana, health, mana, 
        attackPower, abilityPower, weight,
        isPoisonedCounter = 0,
        burningCounter = 0, burnDamage = 0;
    float guardDamageMultipier = 0.6;

    bool guarding = false;

    virtual void raiseGuard();

    bool isGuarding();

    int randomizer(int lowest, int highest);

    virtual void endOfTurn();
    
    virtual void startOfTurn();
    
public:

    virtual bool takeDamage(int damage);

    int calculateDamage(int damage);
    
    std::string getFullName();
    
    void heal(int amount);
    
    void setOnFire(int fireDamage);
    
    bool isOnFire();

    int getBurnDamage();
    
    int getHealth();
    
    void becomePoisoned();

    bool isPoisoned();

    void lowerGuard();
};