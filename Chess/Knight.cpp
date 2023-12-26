#include "Knight.h"

int Knight::moveCheck(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr)
{
	string curLoc = this->getLocation();

	if (curLoc == newLocation) {
		return SAME_MOVE_LOCATION;
	}

	//if there is a piece in the newLocation and it has the same color as the piece moving return false
	if ((*pieces_ptr).find(newLocation) != (*pieces_ptr).end() &&
		(*pieces_ptr)[newLocation]->getColor() == (*pieces_ptr)[curLoc]->getColor()) {
		return PIECE_IN_LOCATION;
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

	return CORRECT;
}