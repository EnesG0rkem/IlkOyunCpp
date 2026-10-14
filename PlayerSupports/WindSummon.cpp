#include "WindSummon.hpp"

WindSummon::WindSummon(int level) : Summon(level){
    fullName = "Rüzgar İfriti ( " + std::to_string(level) + " seviye)";
    maxHealth = 50 + level*25;
    health = maxHealth;
    attackPower = 15 + level*5;
    weight = 20;
}

void WindSummon::startOfTurn(){}

void WindSummon::endOfTurn(){}