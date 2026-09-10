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
        int baseGoldValue, goldValue, cantGuardCounter, damageReducedCounter, exhaustedCounter;
        float powerDifference;
        bool isBurning, isWeakToMagic, isExhausted;

    public:
        Monster(float _powerDifference, int _baseGoldValue);
};