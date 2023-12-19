#include "Rook.h"

bool Rook::moveCheck(std::string newLocation, std::map<BasePiece*, std::string>* pieces_ptr)
{//a5 / e5
    if (!(this->getLocation()[0] == newLocation[0] || this->getLocation()[1] == newLocation[1])) {
        // if NOT same x or y level
        return false;
    }

    //int x_ תתכעלם כרגע

    //for() תתעלם כרגע

    return true;
}

bool Rook::isCheck(std::map<BasePiece*, std::string>* pieces_ptr)
{
    return false;
}

int Rook::move(std::string newLocation, std::map<BasePiece*, std::string>* pieces_ptr)
{
    if (moveCheck(newLocation, pieces_ptr))
    {
        this->setLocation(newLocation);
        return 1;
    }
    return 3;
}
