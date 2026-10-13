#pragma once
#include "Fight/Fight.hpp"
#include "Player.hpp"
#include "Monsters/Monster.hpp"

class Mage : public Player{
    private:
        int focusCounter = 0;
    public:
        Mage(std::string fullName);

        void startOfTurn() override;

        void endOfTurn() override;

        void focus();

        void masterHeal(Player* member);

        void masterFireball(Monster* target);

        void masterLightning(Monster* target);

        void conjureAlly();

        void needleslyBigRod(Monster* target);

};