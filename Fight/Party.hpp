#pragma once
#include <vector>
#include "../Entity/Entity.hpp"
template <typename T>

class Party{
    public:
        std::vector<T*> members;
        T* lastDamagedMember = nullptr;

        bool isLastDamagedMemeber(T* member);
};