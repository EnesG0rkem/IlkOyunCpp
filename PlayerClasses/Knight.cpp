#include "./Knight.hpp"
#include "Fight/Fight.hpp"

Knight::Knight(std::string _fullName)
    :Player(_fullName, 400, 200, 400) {
    attackPower = 30;
    weight = 40;
    guardDamageMultipier = 0.3;

    inventory.addItem(HEAL_POTION, 5);
    inventory.addItem(ENERGY_POTION, 5);
}

bool Knight::takeDamage(int damage){
    if(dontFallCounter > 0 && Player::takeDamage(damage)) health = 1;
    return health > 0;
}

void Knight::powerBurst(){
    mana -= 20;
    powerBurstBuff = attackPower * powerBurstMultiplier;
    attackPower += powerBurstBuff;
    powerBurstCounter = 3;
}

void Knight::dontFall(){
    mana -= 100;
    dontFallCounter = 3;
}

void Knight::cuttingImpact(Monster* target){
    int energyCost = 30;
    if(isGuarding) energyCost *= 2;
    energy -= energyCost;
    int damage = attackPower + randomizer(-damage/10, damage/10);
    if(target->takeDamage(damage) && dontFallCounter > 0){
        health += 100;
        dontFallCounter = 0;
    }
}

void Knight::wideSwing(){
    int energyCost = 45;
    if(isGuarding) energyCost *= 2;
    energy -= energyCost;
    int damage = attackPower + randomizer(-damage/10, damage/10);
    for(Monster* target : Fight::monsterAllience.members){
        if(target->takeDamage(damage) && dontFallCounter > 0){
            health += 100;
            dontFallCounter = 0;
        }
    }
}

void Knight::withAllYourMight(Monster* target){
    energy -= 80;
    int damage = attackPower*2/3 + randomizer(-attackPower/10, attackPower/10);
    if(target->takeDamage(damage) && dontFallCounter > 0){
        health += 100;
        dontFallCounter = 0;
    }
}

void Knight::endOfTurn(){
    Player::endOfTurn();
    if( dontFallCounter > 0) dontFallCounter--;
    if( powerBurstCounter > 0) {
        powerBurstCounter--;
        attackPower -= powerBurstBuff;
    }
}

