#pragma once
#include <map>
#include "./Player.hpp"
#include "../Monsters/Monster.hpp"
#include "../Fight/Fight.hpp"


class Ninja : public Player{
    private:
        int invisibilityCounter = 0, usedKunaiAmount = 0, baseWeight = 10;
        std::map <Monster*, int> ninjaStarMap;

    public:
        Ninja(std::string fullName);

        void endOfTurn() override;
        
        void intoShadows();

        void shadowClone();

        void ninjaStar(Monster* target);

        void kunaiStorm();

        void deathDagger(Monster* target);

        void becomeVisible();

};