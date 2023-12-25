#include "Knight.h"

bool Knight::moveCheck(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr)
{
	string curLoc = this->getLocation();
	return (newLocation[0] == curLoc[0] + 2 && newLocation[1] == curLoc[1] + 1 ||
		newLocation[0] == curLoc[0] + 1 && newLocation[1] == curLoc[1] + 2 ||
		newLocation[0] == curLoc[0] - 2 && newLocation[1] == curLoc[1] + 1 ||
		newLocation[0] == curLoc[0] + 2 && newLocation[1] == curLoc[1] - 1 ||
		newLocation[0] == curLoc[0] - 2 && newLocation[1] == curLoc[1] - 1 ||
		newLocation[0] == curLoc[0] + 1 && newLocation[1] == curLoc[1] - 2 ||
		newLocation[0] == curLoc[0] - 1 && newLocation[1] == curLoc[1] - 2 ||
		newLocation[0] == curLoc[0] - 1 && newLocation[1] == curLoc[1] + 2); //source: trust me bro
}

int Knight::move(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr)
{
	if (moveCheck(newLocation, pieces_ptr))
	{
		this->setLocation(newLocation);
		return 0;
	}
	return 3;
}
