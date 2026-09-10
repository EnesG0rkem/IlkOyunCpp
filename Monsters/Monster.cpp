#include <iostream>
#include "./Monster.hpp"

    Monster::Monster(float _powerDifference, int _baseGoldValue): 
        powerDifference(_powerDifference), baseGoldValue(_baseGoldValue), 
        goldValue(_powerDifference*_baseGoldValue),
        cantGuardCounter(0), damageReducedCounter(0), exhaustedCounter(0),
        isBurning(false), isWeakToMagic(false), isExhausted(false){};