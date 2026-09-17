#pragma once
#include "../PlayerClasses/Player.hpp"

class Shadow : public Player{
    int roundCounter;

    void takeDamage(int damage) override;
};