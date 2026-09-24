#pragma once
#include <map>
#include "./Player.hpp"
#include "Monsters/Monster.hpp"


class Ninja : public Player{
    private:
        int invisibilityCounter = 0, turnCounter = 0,
            usedKunaiAmount = 0, baseWeight = 10;
        std::map <Monster*, int> ninjaStarMap;

        std::string NINJA_STAR = "Ninja Yıldızı", KUNAI = "Kunai";

    public:
        Ninja(std::string fullName);

        void startOfTurn() override;

        void endOfTurn() override;
        
        void intoShadows();

        void shadowClone();

        void ninjaStar(Monster* target);

        void kunaiStorm();

        void deathDagger(Monster* target);

        void becomeVisible();

        bool flee() override;

};