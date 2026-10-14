#include "StoneSummon.hpp"

StoneSummon::StoneSummon(int level) : Summon(level){
    fullName = "Taş İfriti ( " + std::to_string(level) + " seviye)";
    maxHealth = 125 + level*75;
    health = maxHealth;
    attackPower = 10 + level*5;
    weight = 45;
}

void StoneSummon::startOfTurn(){}

void StoneSummon::endOfTurn(){}