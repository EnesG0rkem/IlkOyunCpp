#pragma once
#include <vector>
#include "../Entity/Entity.hpp"

class Monster : public Entity{

    // Attributes
    protected:
        std::vector<std::string> adjectives={
            "Sıradan", "Şaşkın", "Sinirli", "Endişeli", "Korkmuş", "Neşeli",
            "Yakışıklı", "Çirkin", "Uzun Boylu", "Kısa Boylu", "Şişman", "Zayıf",
            "Acıkmış", "Susamış", "Zeki", "Esmer", "Sarışın", "Kızıl"};
        std::string typeName;
        int baseGoldValue, goldValue;
        float powerDifference;

    public:
        int cantGuardCounter = 0, damageReducedCounter = 0, exhaustedCounter = 0;
        bool isBurning = false, isWeakToMagic = false, isExhausted = false;
        Monster(float _powerDifference, int _baseGoldValue);
        void takeDamage(int damage) override;
};