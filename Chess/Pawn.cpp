#include "Pawn.h"

int Pawn::moveCheck(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr)
{
	int isDown = this->getColor() == 'b' ? -1 : 1;
	std::string currLocation = this->getLocation();

	// if same location
	if (newLocation == currLocation)
	{
		return SAME_MOVE_LOCATION;
	}

	////check if not next column or not next next col(only if first time moving)
	//if ((currLocation[1] != newLocation[1] + 1 * isDown) && (!(this->hasMoved) && currLocation[1] != newLocation[1] + 2 * isDown)) {
	//	return ILLEGAL_MOVEMENT;
	//}

	if ((*pieces_ptr).find(newLocation) != (*pieces_ptr).end()) {
		//if deiffrent color piece
		if ((*pieces_ptr)[newLocation]->getColor() == this->getColor()) {
			return PIECE_IN_LOCATION;
		}
		// check if tryes to eat
		if (this->checkEat(newLocation, pieces_ptr)) {
			this->hasMoved = true;
			return CORRECT;
		}
		//if not
		else {
			return ILLEGAL_MOVEMENT;
		}
	}

	//check next row && same column
	if (newLocation[1] == currLocation[1] + 1 * isDown && newLocation[0] == currLocation[0]) {
		this->hasMoved = true;
		return CORRECT;
	}

	if (!this->hasMoved) {
		//check next next row && same column
		if (newLocation[1] == currLocation[1] + 2 * isDown && newLocation[0] == currLocation[0]) {
			this->hasMoved = true;
			return CORRECT;
		}
	}

	return ILLEGAL_MOVEMENT;
}

bool Pawn::checkEat(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr)
{
	int isDown = this->getColor() == 'b' ? -1 : 1;

	// if eating
	if ((newLocation[1] == this->getLocation()[1] + 1 * isDown)
		&& ((newLocation[0] == this->getLocation()[0] + 1) || (newLocation[0] == this->getLocation()[0] - 1))) {
		//if piece in eating index
		if ((*pieces_ptr).find(newLocation) != (*pieces_ptr).end()) {
			//if deiffrent color piece
			if ((*pieces_ptr)[newLocation]->getColor() != this->getColor()) {
				(*pieces_ptr).erase(newLocation);
				return true;
			}
		}
	}
	return false;
}
