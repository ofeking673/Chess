#include "King.h"

int King::moveCheck(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr)
{
	char currentCol = getLocation()[0];
	char currentRow = getLocation()[1];
	char newCol = newLocation[0];
	char newRow = newLocation[1];

	// if same location
	if (newLocation == this->getLocation())
	{ 
		return SAME_MOVE_LOCATION;
	}

	// if same color
	if ((*pieces_ptr).find(newLocation) != (*pieces_ptr).end() && (*pieces_ptr)[newLocation]->getColor() == this->getColor())
	{
		return PIECE_IN_LOCATION;
	}

	//need to check if +1 in any direction
	if(std::abs(newRow - currentRow) <= 1 && std::abs(newCol - currentCol) <= 1)
	{
		return CORRECT;
	}
	else {
		return ILLEGAL_MOVEMENT;
	}
}