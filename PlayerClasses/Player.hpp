#pragma once
#include <vector>
#include "../Entity/Entity.hpp"
#include "../Fight/Fight.hpp"
#include "../Inventory/Inventory.hpp"
#include "../Monsters/Monster.hpp"
#include "../PlayerSupports/Shadow.hpp"

class Player : public Entity{
    // Attributes
    protected:
        int maxEnergy, energy,
            parchemnts, 
            parchmentCounter = 0, poisonedCounter = 0;

        bool usedPoison = false, usedParchment = false;

        Inventory inventory;
    
    public:
        void takeDamage(int damage) override;

        virtual void endOfTurn();

        virtual void startOfTurn();

};