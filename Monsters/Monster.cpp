#include <iostream>
#include "./Monster.hpp"
#include "Fight/Fight.hpp"

    Monster::Monster(float _powerDifference, int _baseGoldValue): 
        Entity(), 
        powerDifference(_powerDifference), baseGoldValue(_baseGoldValue), 
        goldValue(_powerDifference*_baseGoldValue){};

    bool Monster::takeDamage(int damage){
        damage = Entity::calculateDamage(damage);
        health -= damage;
        Fight::monsterAllience.totalDamageTaken += damage;
        Fight::monsterAllience.lastDamagedMember = this;
        if(health < 1) removeFromMembers();
        return health < 1;
    }

    void Monster::removeFromMembers(){}

    void Monster::raiseGuard(){ Entity::raiseGuard(); }

    void Monster::endOfTurn(){}

    void Monster::startOfTurn(){}

    