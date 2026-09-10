#pragma once
#include <string>

class Item{
    private:
        std::string itemName;
        int itemNumber;
    public:
        Item(std::string _itemName, int _itemNumber);
        
        Item(std::string _itemName);

        void increaseItemNumber(int number = 1);

        void decreaseItemNumber(int number = 1);

        std::string getItemName();

        int getItemNumber();




};