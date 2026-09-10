#include <string>
#include <iostream>
#include "./Inventory.hpp"

int Inventory::getItemNumber(std::string itemName){

    for(Item item : items){
        if( item.getItemName() == itemName ) return item.getItemNumber(); 
    }

    return 0;
}

void Inventory::addItem(std::string itemName, int number){
    for(Item& item : items){
        if( item.getItemName() == itemName ){
            item.increaseItemNumber(number);
            return;
        }
    }

    items.push_back(Item(itemName, number));
}

void Inventory::useItem(std::string itemName, int number){
    for(Item& item : items){
        if( item.getItemName() == itemName ){
            item.decreaseItemNumber(number);
            return;
        }
    }
    
    std::cout << "Kullanılacak eşya bulunamadı!" << std::endl;

    return;
}