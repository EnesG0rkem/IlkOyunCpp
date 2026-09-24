#pragma once
#include <vector>
#include "./Party.hpp"
#include "PlayerClasses/Player.hpp"
#include "Monsters/Monster.hpp"

class Fight{
    public:
        static Party<Player> playerAllience;
        static Party<Monster> monsterAllience;

};