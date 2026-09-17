#include <iostream>
#include "./Monster.hpp"

    Monster::Monster(float _powerDifference, int _baseGoldValue): 
        Entity(), 
        powerDifference(_powerDifference), baseGoldValue(_baseGoldValue), 
        goldValue(_powerDifference*_baseGoldValue){};

    void Monster::takeDamage(int damage){
            Entity::takeDamage(damage);
            Fight::monsterAllience.lastDamagedMember = this;
}