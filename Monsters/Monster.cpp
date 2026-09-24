#include <iostream>
#include "./Monster.hpp"
#include "Fight/Fight.hpp"

    Monster::Monster(float _powerDifference, int _baseGoldValue): 
        Entity(), 
        powerDifference(_powerDifference), baseGoldValue(_baseGoldValue), 
        goldValue(_powerDifference*_baseGoldValue){};

    bool Monster::takeDamage(int damage){
        Fight::monsterAllience.lastDamagedMember = this;
        return Entity::takeDamage(damage);
}