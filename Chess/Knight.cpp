#include "Knight.h"

int Knight::moveCheck(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr)
{
	string curLoc = this->getLocation();

	if (curLoc == newLocation) {
		return 7;
	}

	//if there is a piece in the newLocation and it has the same color as the piece moving return false
	if ((*pieces_ptr).find(newLocation) != (*pieces_ptr).end() &&
		(*pieces_ptr)[newLocation]->getColor() == (*pieces_ptr)[curLoc]->getColor()) {
		return 3;
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
		return 6;
	}

	return 0;
}