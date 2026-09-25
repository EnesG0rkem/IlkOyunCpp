#pragma once
#include "./Player.hpp"
#include "Monsters/Monster.hpp"

class Knight : public Player{
    private:
        int dontFallCounter = 0, powerBurstCounter = 0,
            powerBurstBuff = 0;
        double powerBurstMultiplier = 0.5;
    public:
        Knight(std::string fullName);

        bool takeDamage(int damage) override;

        void powerBurst();

        void dontFall();

        void cuttingImpact(Monster* target);

        void wideSwing();

        void withAllYourMight(Monster* target);

        void endOfTurn() override;

};