#pragma once
#include "Monsters/Monster.hpp"
#include "PlayerSupports/Summon.hpp"

class StoneSummon: public Summon{

    public:
    
    StoneSummon(int level);

    void startOfTurn() override;

    void endOfTurn() override;
    
};