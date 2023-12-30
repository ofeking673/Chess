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

	//need to check if +1 in any direction
	if(!(std::abs(newRow - currentRow) <= 1 && std::abs(newCol - currentCol) <= 1))
	{
		return ILLEGAL_MOVEMENT;
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