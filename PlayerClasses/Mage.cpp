#include "Mage.hpp"

Mage::Mage(std::string _fullName)
    :Player(_fullName, 250, 400, 150){
        attackPower = 10;
        abilityPower = 20;
        weight = 20;

        inventory.addItem(HEALTH_POTION, 2);
        inventory.addItem(MANA_POTION, 4);
    }

void Mage::startOfTurn(){}

void Mage::endOfTurn(){}

void Mage::focus(){
    mana -= 10;
    focusCounter++;
}

void Mage::masterHeal(Player* member){
    mana -= 60;
    int healAmount = abilityPower*7/2;
    healAmount += randomizer(-healAmount/15, healAmount/15);
    if(focusCounter > 1) healAmount *= 2;
    else if(focusCounter > 0) healAmount *= 1.5;
    member->heal(healAmount);
}

void Mage::masterFireball(Monster* target){
    mana -= 70;
    int damage = abilityPower*5/2;
    damage += randomizer(-damage/10, damage/10);

    if(focusCounter > 1) damage *= 2;
    else if(focusCounter > 0) damage *= 1.5;

    if(target->isWeakToMagic){
        damage *= 1.5;
        target->isWeakToMagic = false;
    }
    target->takeDamage(damage);
    
    int burnDamage = abilityPower;
    if(randomizer(0,100) < 30){
        if(target -> getBurnDamage() > burnDamage)
            burnDamage = target->getBurnDamage();
        target->setOnFire(burnDamage);
    }
}

void Mage::masterLightning(Monster* target){
    mana -= 70;
    int damage = abilityPower*2;
    damage += randomizer(-damage/25, damage/25);
    float bonusDamage = 1;
    if(target->isWeakToMagic){
        bonusDamage *= 1.5;
        target->isWeakToMagic = false;
    }
    target->takeDamage(damage * bonusDamage);

    bool check = false;
    for(Monster* sideTarget : Fight::monsterAllience.members){
        if(randomizer(0,100) > 30){
            bonusDamage = 1;
            if(sideTarget->isWeakToMagic){
                bonusDamage *= 1.5;
                sideTarget->isWeakToMagic = false;
            }
            sideTarget->takeDamage(damage*2/3*bonusDamage);
            check = true;
        }
    }
    if(check) Fight::monsterAllience.lastDamagedMember = target;
}

void Mage::conjureAlly(){

}

void Mage::needleslyBigRod(Monster* target){
    energy -= 10;

    int damage = attackPower;
    damage += randomizer(-damage/10, damage /10);
    target->takeDamage(damage);

    if(randomizer(0, 100) > 75)
        target->isWeakToMagic = true;
}

