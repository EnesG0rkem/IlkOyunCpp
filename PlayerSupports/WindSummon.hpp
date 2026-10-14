#pragma once
#include "Monsters/Monster.hpp"
#include "PlayerSupports/Summon.hpp"

class WindSummon: public Summon{

    public:
    
    WindSummon(int level);

    void startOfTurn() override;

    void endOfTurn() override;
    
};