cmake_minimum_required(VERSION 3.16)
project(IlkOyunCpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(IlkOyunCpp
    Main/main.cpp
    Entity/Entity.cpp
    Monsters/Monster.cpp
    PlayerClasses/Player.cpp
    PlayerClasses/Ninja.cpp
    PlayerClasses/Knight.cpp
    PlayerClasses/Paladin.cpp
    PlayerClasses/BloodMage.cpp
    PlayerSupports/Shadow.cpp
    Fight/Fight.cpp
    Inventory/Inventory.cpp
    Inventory/Item.cpp
)

target_include_directories(IlkOyunCpp PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
