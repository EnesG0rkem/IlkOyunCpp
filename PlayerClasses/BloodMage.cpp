#include "./BloodMage.hpp"
#include "Fight/Fight.hpp"

BloodMage::BloodMage(std::string _fullName)
    :Player(_fullName, 400, 0, 150){
    weight = 20;
    attackPower = 20;
    abilityPower = 15;
    inventory.addItem(POISON, 5);
    inventory.addItem(HEAL_POTION, 10);
}

void BloodMage::startOfTurn(){}

void BloodMage::endOfTurn(){}

void BloodMage::drinkPoison(){
    inventory.useItem(POISON);
    becomePoisoned();
}

void BloodMage::mandatoryDonation(Monster* target){
    health -= abilityPower;

    float multiplier = 1;
    if(health < maxHealth/2) multiplier = 1.1;
    else if(health < maxHealth/3) multiplier = 1.2;
    else if(health < maxHealth/4) multiplier = 1.4;
    else if(health < maxHealth/5) multiplier = 1.6;
    else if(health < maxHealth/6) multiplier = 1.8;
    
    if(target->isPoisoned()) becomePoisoned();
    int damage = abilityPower*2*multiplier;
    damage += randomizer(-damage/10, damage/10);
    target->takeDamage(damage);
    
    int healAmount = abilityPower*multiplier;
    healAmount = randomizer(-healAmount/10, healAmount/10);
    heal(healAmount);
}

void BloodMage::coagulateBlade(){
    health -= abilityPower*2/3;
    weaponCounter = 3;
    if(isPoisoned()) usedPosionCounter = 3;
}

void BloodMage::bloodSpikes(){
    health -= 30;
    float battleBonus = Fight::monsterAllience.totalDamageTaken + Fight::playerAllience.totalDamageTaken;
    battleBonus *= 0.2;
    int damage = abilityPower + battleBonus;
    damage += randomizer(-damage/10, damage/10);
    for(Monster* member : Fight::monsterAllience.members){
        member->takeDamage(damage);
    }
    Fight::monsterAllience.lastDamagedMember = nullptr;
}

void BloodMage::bloodArrows(){
    health -= abilityPower;
    int damage = abilityPower;
    damage += randomizer(-damage/10, damage/10);
    for(Monster* member : Fight::monsterAllience.members){
        member->takeDamage(damage);
        if(isPoisonedCounter > 0) member->becomePoisoned();
    }
    Fight::monsterAllience.lastDamagedMember = nullptr;
}

void BloodMage::bloodDagger(Monster* target){
    energy -= 25;
    int damage = attackPower;
    damage = randomizer(-damage/10, damage/10);
    target->takeDamage(damage);
    weaponCounter--;
}