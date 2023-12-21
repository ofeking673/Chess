#include "Rook.h"

bool Rook::moveCheck(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr)
{//a5 / e5
    bool same_x = this->getLocation()[0] == newLocation[0];
    bool same_y = this->getLocation()[1] == newLocation[1];

    if (!(same_x || same_y)) {
        // if NOT same x or y level
        return false;
    }

    int diff = same_x ? newLocation[1] - this->getLocation()[1] : newLocation[0] - this->getLocation()[0];
    
    if (diff > 0)
    {
        //if rook is going in either positive direction (up or right)

        for (int i = 1; i < diff; i++) {
            std::string iterLine = same_x ? std::string(1, this->getLocation()[0]) + char(this->getLocation()[1] + i) :
                char(this->getLocation()[0] + i) + std::string(1, this->getLocation()[1]);

            if ((*pieces_ptr).find(iterLine) != (*pieces_ptr).end()) {
                return false;
            }
        }
    }
    else
    {
        for (int i = -1; i > diff; i--)
        {
            std::string iterLine = same_x ? std::string(1, this->getLocation()[0]) + char(this->getLocation()[1] + i) :
                char(this->getLocation()[0] + i) + std::string(1, this->getLocation()[1]);

            if ((*pieces_ptr).find(iterLine) != (*pieces_ptr).end()) {
                return false;
            }
        }
    }

    return true;
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
