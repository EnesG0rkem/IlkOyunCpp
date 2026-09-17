#include "./Shadow.hpp"
#include "../Fight/Fight.hpp"


Shadow::Shadow(){
    fullName = "Gölge Klonu";
    health = 70;
    weight = 10;
    roundCounter = 3;
}

void Shadow::endOfTurn(){
    roundCounter--;
}

void Shadow::startOfTurn(){
    if(roundCounter == 0) Fight::playerAllience.members.erase();
}
