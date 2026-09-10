#include <string>
#include "./Item.hpp"

Item::Item(std::string _itemName, int _itemNumber)
    : itemName(_itemName), itemNumber(_itemNumber){};

Item::Item(std::string _itemName)
    : itemName(_itemName){};

void Item::increaseItemNumber(int number){
    itemNumber += number;
}

void Item::decreaseItemNumber(int number){
    itemNumber -= number;
}

std::string Item::getItemName() { return itemName; }

int Item::getItemNumber() { return itemNumber; }