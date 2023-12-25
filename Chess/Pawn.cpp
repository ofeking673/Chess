#include "Pawn.h"

bool Pawn::moveCheck(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr)
{
	bool value;
	(getColor() == 'w') ? (hasMoved == true) ? value = (newLocation[0] == getLocation()[0] && newLocation[1] == getLocation()[1] + 1)
		: value = ((newLocation[0] == getLocation()[0] && newLocation[1] == getLocation()[1] + 1) || (newLocation[0] == getLocation()[0] && newLocation[1] == getLocation()[1] + 2))
		:
		(hasMoved == true) ? value = (newLocation[0] == getLocation()[0] && newLocation[1] == getLocation()[1] - 1)
		: value = ((newLocation[0] == getLocation()[0] && newLocation[1] == getLocation()[1] - 1) || (newLocation[0] == getLocation()[0] && newLocation[1] == getLocation()[1] - 2));;
	std::cout << value << std::endl;
	return value;
}

int Pawn::move(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr)
{
	if (moveCheck(newLocation, pieces_ptr))
	{
		hasMoved = true;
		setLocation(newLocation);
		return 1;
	}
	return 3;
}
