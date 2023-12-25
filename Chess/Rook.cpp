#include "Rook.h"

int Rook::moveCheck(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr)
{//a5 / e5
    bool same_x = this->getLocation()[0] == newLocation[0];
    bool same_y = this->getLocation()[1] == newLocation[1];

    if (same_x && same_y) {
        return 7;
    }

    if (!(same_x || same_y)) {
        // if NOT same x or y level
        return 6;
    }

    auto it = pieces_ptr->find(newLocation);
    if (it != pieces_ptr->end())
    {
        if (this->getColor() == it->second->getColor())
        {
            return 3;
        }
    }
    

    int diff = same_x ? newLocation[1] - this->getLocation()[1] : newLocation[0] - this->getLocation()[0];
    
    if (diff > 0)
    {
        //if rook is going in either positive direction (up or right)

        for (int i = 1; i < diff; i++) {
            std::string iterLine = same_x ? std::string(1, this->getLocation()[0]) + char(this->getLocation()[1] + i) :
                char(this->getLocation()[0] + i) + std::string(1, this->getLocation()[1]); // if same x, go over y, if not, enlarge x

            if ((*pieces_ptr).find(iterLine) != (*pieces_ptr).end()) {
                return 6;
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
                return 6;
            }
        }
    }

    return 0;
}