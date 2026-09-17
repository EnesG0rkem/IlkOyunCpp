#include <map>
#include "./Ninja.hpp"


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
    inventory.addItem("Ninja yıldızı", 5);
    inventory.addItem("Kunai", 30);

}

void Ninja::endOfTurn(){
    Player::endOfTurn();
    if(invisibilityCounter > 0) invisibilityCounter--;

}

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

    ninjaStarMap[target]++;

    target->takeDamage(damage + randomizer(-damage/10, damage/10));
    
}

void Ninja::kunaiStorm(){
    int kunaiAmount = 0;

    int amount = std::min(energy-50, inventory.getItemNumber("Kunai")-10); 
    energy -= amount*5;
    int damage = amount * attackPower / 10;
    damage += randomizer(-damage/5, damage/5);

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