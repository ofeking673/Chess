#include "Rook.h"

int Rook::moveCheck(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr)
{//a5 / e5
    bool same_x = this->getLocation()[0] == newLocation[0];
    bool same_y = this->getLocation()[1] == newLocation[1];

    if (same_x && same_y) {
        return SAME_MOVE_LOCATION;
    }

    if (!(same_x || same_y)) {
        // if NOT same x or y level
        return ILLEGAL_MOVEMENT;
    }
    
    int diff = same_x ? newLocation[1] - this->getLocation()[1] : newLocation[0] - this->getLocation()[0];
    
    if (diff > 0)
    {
        //if rook is going in either positive direction (up or right)

        for (int i = 1; i < diff; i++) {
            std::string iterLine = same_x ? std::string(1, this->getLocation()[0]) + char(this->getLocation()[1] + i) :
                char(this->getLocation()[0] + i) + std::string(1, this->getLocation()[1]); // if same x, go over y, if not, enlarge x

            if ((*pieces_ptr).find(iterLine) != (*pieces_ptr).end()) {
                return ILLEGAL_MOVEMENT;
            }
        }
    }
    else
    {
        //if rook is going in negative directions (down or left)
        for (int i = -1; i > diff; i--)
        {
            std::string iterLine = same_x ? std::string(1, this->getLocation()[0]) + char(this->getLocation()[1] + i) :
                char(this->getLocation()[0] + i) + std::string(1, this->getLocation()[1]); // if same x, y goes DOWN, if not, x goes DOWN

            if ((*pieces_ptr).find(iterLine) != (*pieces_ptr).end()) {
                return ILLEGAL_MOVEMENT;
            }
        }
    }

    //if there is a piece in the newLocation 
    if ((*pieces_ptr).find(newLocation) != (*pieces_ptr).end())
    {
        // if piece in newLocation has the same color as the piece moving
        if ((*pieces_ptr)[newLocation]->getColor() == this->getColor())
        {
            return PIECE_IN_LOCATION;
        }
        // if not
        (*pieces_ptr).erase(newLocation);
    }

    return CORRECT;
}