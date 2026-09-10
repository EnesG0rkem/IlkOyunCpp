#pragma once
#include <vector>
#include <string>
#include "./Item.hpp"

class Inventory{
    private:
        std::vector<Item> items;

    public: 
        int getItemNumber(std::string itemName);

        void addItem(std::string itemName, int number = 1);

        void useItem(std::string itemName, int number = 1);

};