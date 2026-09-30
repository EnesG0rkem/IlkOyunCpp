#pragma once
#include "Fight/Fight.hpp"
#include "./Player.hpp"

class Paladin : public Player{
    private:


    public:
        Paladin(std::string fullName);

        void noviceHeal(Player* target);

        void noviceFireball(Monster* target);

        void noviceLightning(Monster* target);

        void soulReaper(Monster* target);

        void silverFang(Monster* target);

        void raiseGuard() override;
};