#pragma once
#include "PlayerClasses/Player.hpp"

class Shadow : public Player{
    public:
        Shadow();
        
        int roundCounter;

        void endOfTurn() override;

        void startOfTurn() override;
};