#include "King.h"

bool King::moveCheck(std::string newLocation, std::map<BasePiece*, std::string>* pieces_ptr)
{
	char currentCol = getLocation()[0];
	char currentRow = getLocation()[1];
	char newCol = newLocation[0];
	char newRow = newLocation[1];

	return (std::abs(newRow - currentRow) <= 1 && std::abs(newCol - currentCol) <= 1); //need to check if +1 in any direction
}

bool King::isCheck(std::map<BasePiece*, std::string>* pieces_ptr)
{
	return false;
}

int King::move(std::string newLocation, std::map<BasePiece*, std::string>* pieces_ptr)
{
	if (moveCheck(newLocation, pieces_ptr))
	{
		this->setLocation(newLocation);
		return 1;
	}
	return 3;
}
