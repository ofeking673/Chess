#include "Rook.h"

bool Rook::moveCheck(std::string newLocation)
{//a5 / e5
    return (this->getLocation()[0] == newLocation[0] || this->getLocation()[1] == newLocation[1]);
}

bool Rook::isCheck()
{
    return false;
}

int Rook::move(std::string newLocation)
{
    if (moveCheck(newLocation))
    {
        this->setLocation(newLocation);
        return 1;
    }
    return 3;
}
