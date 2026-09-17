#include "./Party.hpp"

bool Party::isLastDamagedMemeber(Entity* member){
    return member == lastDamagedMember;
}