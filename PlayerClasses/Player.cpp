#include "./Player.hpp"
#include "Fight/Fight.hpp"

bool Player::takeDamage(int damage){
            Entity::takeDamage(damage);
            Fight::playerAllience.lastDamagedMember = this;
            if(health < 1) removeFromMembers();
            return health < 1;
}

void Player::removeFromMembers(){
    int index = 0;
    for(Player* member : Fight::playerAllience.members){
        if(member == this) break;
        index++;
    }
    Fight::playerAllience.members.erase(
            Fight::playerAllience.members.begin() + index);
    Fight::playerAllience.lastDamagedMember = nullptr;
}

bool Player::flee(){
    int luck = randomizer(0, 100);
    return luck < 40;
}

void Player::endOfTurn(){}

void Player::startOfTurn(){}

