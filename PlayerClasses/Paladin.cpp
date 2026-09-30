#include "./Paladin.hpp"

Paladin::Paladin(std::string _fullName)
    :Player(_fullName, 300, 250, 300) {
    attackPower = 25;
    abilityPower = 25;
    weight = 25;

    inventory.addItem(HEAL_POTION, 3);
    inventory.addItem(PARCHEMNT, 10);
}

void Paladin::noviceHeal(Player* target){
    mana -= 35;
    int amount = abilityPower*6/5;
    amount += randomizer(-amount/20, amount/20);
    target->heal(amount);
}

void Paladin::noviceFireball(Monster* target){
    mana -= 40;
    
    int damage = abilityPower + randomizer(-abilityPower/10, abilityPower/10);
    if(target->isWeakToMagic){
        damage *= 1.5;
    }
    target -> takeDamage(damage);

    int burnDamage = attackPower*3/5;
    if(target -> burnDamage < burnDamage &&
        randomizer(0,100) < 30) target->setOnFire(burnDamage);

}

void Paladin::noviceLightning(Monster* target){
    mana -= 40;
    int damage = abilityPower*4/5;
    damage += randomizer(-damage/25, damage/25);
    target->takeDamage(damage);

    bool check = false;
    for(Monster* sideTarget : Fight::monsterAllience.members){
        if(randomizer(0,100) > 30){
            sideTarget->takeDamage(damage*2/3);
            check = true;
        }
    }
    if(check) Fight::monsterAllience.lastDamagedMember = nullptr;

}

void Paladin::soulReaper(Monster* target){
    energy -= 10;
    int damage = attackPower;
    if(target->getHealth() < 50 ) damage += attackPower*4/5;
    else if(target->getHealth() < 100 ) damage += attackPower*3/5;
    damage += randomizer(-damage/10, damage/10);

    target->takeDamage(damage);
}

void Paladin::silverFang(Monster* target){
    energy -= 10;
    int damage = attackPower;
    damage += randomizer(-damage/25, damage/25);
    target->takeDamage(damage);
}

void Paladin::raiseGuard(){
    Player::raiseGuard();
    energy += 15;
}

