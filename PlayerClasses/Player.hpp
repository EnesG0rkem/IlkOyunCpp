#pragma once
#include <vector>
#include "Entity/Entity.hpp"
#include "Inventory/Inventory.hpp"

class Player : public Entity{
    // Attributes
    protected:
        int maxEnergy, energy, level = 1, xp = 0,
            parchemnts, poisons,
            parchmentCounter = 0, poisonedCounter = 0;

        bool usedPoison = false, usedParchment = false;

        Inventory inventory;

        void removeFromMembers();

        std::string GOLD = "Altın", MONSTER_PARTS = "Canavar Parçası",
                    HEAL_POTION = "Can İksiri", MANA_POTION = "Mana İksiri",
                    ENERGY_POTION = "Enerji İksiri", 
                    PARCHEMNT = "Parşömen", POISON = "Zehir";
    
    public:
        bool takeDamage(int damage) override;

        virtual void endOfTurn() override;

        virtual void startOfTurn() override;

        virtual bool flee();


};