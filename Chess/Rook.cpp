#include "Rook.h"

bool Rook::moveCheck(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr)
{//a5 / e5
    bool same_x = this->getLocation()[0] == newLocation[0];
    bool same_y = this->getLocation()[1] == newLocation[1];
    int i = 0;

    if (!(same_x || same_y)) {
        // if NOT same x or y level
        return false;
    }

    for (i = 1; i < BoardLength; i++) {
        
    }

    return true;
}

bool Rook::isCheck(std::map<std::string, BasePiece*>* pieces_ptr)
{
    return false;
}

int Rook::move(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr)
{
    if (moveCheck(newLocation, pieces_ptr))
    {
        this->setLocation(newLocation);
        return 1;
    }
    return 3;
}
