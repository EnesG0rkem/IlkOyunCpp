#include "IceSummon.hpp"

IceSummon::IceSummon(int level) : Summon(level){
    fullName = "Buz İfriti ( " + std::to_string(level) + " seviye)";
    maxHealth = 75 + level*25;
    health = maxHealth;
    abilityPower = 5 + level*5;
    weight = 20;
}

void IceSummon::startOfTurn(){}

void IceSummon::endOfTurn(){}