#include <map>
#include "./Ninja.hpp"
#include "PlayerSupports/Shadow.hpp"
#include "Fight/Fight.hpp"

Ninja::Ninja(std::string _fullName){
    fullName = _fullName;
    maxHealth = 250;
    health = maxHealth;
    maxMana = 275;
    mana = maxMana;
    maxEnergy = 200;
    energy = maxEnergy;
    attackPower = 30;
    weight = baseWeight;
    inventory.addItem(NINJA_STAR, 5);
    inventory.addItem(KUNAI, 30);

}

void Ninja::endOfTurn(){
    Player::endOfTurn();
    if(invisibilityCounter > 0) invisibilityCounter--;
    if(turnCounter++ > 1){
        Ninja::secondTurn();
        turnCounter = 0;   
    }
}

void Ninja::startOfTurn(){}

void Ninja::secondTurn(){}

void Ninja::intoShadows(){
    mana -= 50;
    invisibilityCounter = 3;
    weight = 0;
}

void Ninja::shadowClone(){
    mana -= 15;
    Shadow* s = new Shadow();
    Fight::playerAllience.members.push_back(s);
}

void Ninja::ninjaStar(Monster* target){
    energy -= 25;
    int damage = 2 * attackPower / 3;
    if(invisibilityCounter != 0){
        target->isPoisoned = true;
        becomeVisible();
    }

    inventory.useItem(NINJA_STAR);
    ninjaStarMap[target]++;

    if(target->takeDamage(damage + randomizer(-damage/10, damage/10))){
        int regainPercentage = randomizer(0, 80);
        int amount = ninjaStarMap[target];
        inventory.addItem(NINJA_STAR, amount*regainPercentage);
    }
}

void Ninja::kunaiStorm(){
    int kunaiAmount = 0;

    int amount = std::min(energy-50, inventory.getItemNumber(KUNAI)-10); 
    energy -= amount*5;
    int damage = amount * attackPower / 10;
    damage += randomizer(-damage/5, damage/5);
    inventory.useItem(KUNAI, amount);

    bool invisible = false;
    if(invisibilityCounter > 0){
        invisible = true;
        becomeVisible();
    }

    for(Monster* monster : Fight::monsterAllience.members){
        if(invisible){
            monster->isGuarding = false;
            monster->cantGuardCounter = 3;
        }
        monster -> takeDamage(damage);
    }

    usedKunaiAmount += amount;

}

void Ninja::deathDagger(Monster* target){
    energy -= 50;
    int damage = 2 * attackPower / 3;
    if (Fight::playerAllience.lastDamagedMember != this)
        damage *= 2;
    if (invisibilityCounter > 0){
        damage *= 3;
        becomeVisible();
    }
    
    target -> takeDamage(damage);
}

void Ninja::becomeVisible(){
    invisibilityCounter = 0;
    weight = baseWeight;
}

bool Ninja::flee(){
    int luck = randomizer(0, 100);
    return luck < 60;
}