#include "Bishop.h"



int Bishop::moveCheck(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr)
{

    std::string currLocation = this->getLocation();
    int i = 0;

    if (currLocation == newLocation) {
        return SAME_MOVE_LOCATION;
    }
    
    if (abs(currLocation[0] - newLocation[0]) != abs(currLocation[1] - newLocation[1]))
    {
        return ILLEGAL_MOVEMENT;
    }


    int xSlope = (newLocation[0] < currLocation[0] ? -1 : 1);// if newX < currX xSlope is negative otherwise positive
    int ySlope = (newLocation[1] < currLocation[1] ? -1 : 1);// if newX < currX xSlope is negative otherwise positive
    std::string iterLine = "a1";// used to iterate over the path of the bishop

    for (i = 1; i < abs(newLocation[0] - currLocation[0]); i++) {
        iterLine[0] = currLocation[0] + (i * xSlope);
        iterLine[1] = currLocation[1] + (i * ySlope);

        if ((*pieces_ptr).find(iterLine) != (*pieces_ptr).end()) {
            return ILLEGAL_MOVEMENT;
        }
    }

    //if there is a piece in the newLocation 
    if ((*pieces_ptr).find(newLocation) != (*pieces_ptr).end())
    {
        // if piece in newLocation has the same color as the piece moving
        if((*pieces_ptr)[newLocation]->getColor() == (*pieces_ptr)[currLocation]->getColor())
        {
            return PIECE_IN_LOCATION;
        }
        // if not
        (*pieces_ptr).erase(newLocation);
    }

    return CORRECT;
}