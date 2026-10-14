#pragma once
#include "Fight/Fight.hpp"
#include "PlayerClasses/Player.hpp"
#include "Monsters/Monster.hpp"

class Summon : public Player{
    protected:
        int lifeCounter = 3;

        Summon(int level);
        
    public:

        void startOfTurn() override;

        void endOfTurn() override;
};