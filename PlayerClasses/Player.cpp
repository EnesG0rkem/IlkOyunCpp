#include "./Player.hpp"

void Player::takeDamage(int damage){
            Entity::takeDamage(damage);
            Fight::playerAllience.lastDamagedMember = this;
}