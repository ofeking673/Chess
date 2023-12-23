#include "Bishop.h"



bool Bishop::moveCheck(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr)
{

    std::string currLocation = this->getLocation();
    int i = 0;

    if (abs(currLocation[0] - newLocation[0]) != abs(currLocation[1] - newLocation[1]))
    {
        return false;
    }


    int xSlope = (newLocation[0] < currLocation[0] ? -1 : 1);// if newX < currX xSlope is negative otherwise positive
    int ySlope = (newLocation[1] < currLocation[1] ? -1 : 1);// if newX < currX xSlope is negative otherwise positive
    std::string iterLine = "a1";// used to iterate over the path of the bishop

    for (i = 1; i < abs(newLocation[0] - currLocation[0]); i++) {
        iterLine[0] = currLocation[0] + (i * xSlope);
        iterLine[1] = currLocation[1] + (i * ySlope);

        if ((*pieces_ptr).find(iterLine) != (*pieces_ptr).end()) {
            return false;
        }
    }

    //if there is a piece in the newLocation and it has the same color as the piece moving return false
    if ((*pieces_ptr).find(newLocation) != (*pieces_ptr).end() &&
        (*pieces_ptr)[newLocation]->getColor() == (*pieces_ptr)[currLocation]->getColor()) {
        return false;
    }

    return true;
}

int Bishop::move(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr)
{

    if (moveCheck(newLocation, pieces_ptr))
    {
        this->setLocation(newLocation);
        return 0;
    }
    return 3;
}
