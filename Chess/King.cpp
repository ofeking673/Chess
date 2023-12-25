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
		return 7;
	}

	// if same color
	if ((*pieces_ptr).find(newLocation) != (*pieces_ptr).end() && (*pieces_ptr)[newLocation]->getColor() == this->getColor())
	{
		return 3;
	}

	//need to check if +1 in any direction
	if(std::abs(newRow - currentRow) <= 1 && std::abs(newCol - currentCol) <= 1)
	{
		return 0;
	}
	else {
		return 6;
	}
}