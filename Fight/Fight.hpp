#pragma once
#include <vector>
#include "../Entity/Entity.hpp"
#include "./Party.hpp"

class Fight{
    public:
        static Party<Player> playerAllience;
        static Party<Monster> monsterAllience;

};