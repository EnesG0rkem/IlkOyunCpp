#pragma once
#include "Monsters/Monster.hpp"
#include "PlayerSupports/Summon.hpp"

class IceSummon: public Summon{

    public:
    
    IceSummon(int level);

    void startOfTurn() override;

    void endOfTurn() override;
    
};