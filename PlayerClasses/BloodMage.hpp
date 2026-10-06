#pragma once
#include "./Player.hpp"
#include "Monsters/Monster.hpp"

class BloodMage : public Player{
    private:
        int weaponCounter = 0;

    public:
        BloodMage(std::string _fullName);

        void startOfTurn() override;

        void endOfTurn() override;

        void drinkPoison();

        void mandatoryDonation(Monster* target);

        void coagulateBlade();

        void bloodSpikes();

        void bloodArrows();

        void bloodDagger(Monster* target);
};