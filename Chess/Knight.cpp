#include "Knight.h"

int Knight::moveCheck(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr)
{
	string curLoc = this->getLocation();

	if (curLoc == newLocation) {
		return SAME_MOVE_LOCATION;
	}

	if (!(newLocation[0] == curLoc[0] + 2 && newLocation[1] == curLoc[1] + 1 ||
		newLocation[0] == curLoc[0] + 1 && newLocation[1] == curLoc[1] + 2 ||
		newLocation[0] == curLoc[0] - 2 && newLocation[1] == curLoc[1] + 1 ||
		newLocation[0] == curLoc[0] + 2 && newLocation[1] == curLoc[1] - 1 ||
		newLocation[0] == curLoc[0] - 2 && newLocation[1] == curLoc[1] - 1 ||
		newLocation[0] == curLoc[0] + 1 && newLocation[1] == curLoc[1] - 2 ||
		newLocation[0] == curLoc[0] - 1 && newLocation[1] == curLoc[1] - 2 ||
		newLocation[0] == curLoc[0] - 1 && newLocation[1] == curLoc[1] + 2))
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