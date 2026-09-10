#pragma once
#include <vector>
#include "../Entity/Entity.hpp"
#include "../Inventory/Inventory.hpp"

class Player : public Entity{
    // Attributes
    protected:
        int gold, monsterParts, maxEnergy, energy, weight,
            parchemnts, 
            parchmentCounter, poisonedCounter;

        bool usedPoison, usedParchment;

        Inventory playerInventory;
        // gibi kullanarak eşya ekleme gibi şeyleri daha kolay halletmek istiyorum

};