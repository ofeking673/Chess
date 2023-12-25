#include "Pawn.h"

int Pawn::moveCheck(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr)
{
	int isDown = this->getColor() == 'b' ? 1 : -1;
	std::string currLocation = this->getLocation();

	// if eating
	if (newLocation[1] == currLocation[1] + 1 && newLocation[0] == currLocation[0] + 1 || newLocation[0] == currLocation[0] - 1) {
		//if piece in eating index
		if ((*pieces_ptr).find(newLocation) != (*pieces_ptr).end()) {
			//if deiffrent color piece
			if ((*pieces_ptr)[newLocation]->getColor() != this->getColor()) {
				return 0;
			}
			else {
				return 3;
			}
		}
		else {
			return 6;
		}
	}

	// if same location
	if (newLocation == currLocation)
	{
		return 7;
	}

	if ((newLocation[0] != currLocation[0]) || (currLocation[1] != newLocation[1] + 1 * isDown) && (this->hasMoved && currLocation[1] != newLocation[1] + 1 * isDown)) {
		return 6;
	}

	if ((*pieces_ptr).find(newLocation) != (*pieces_ptr).end()) {
		//if deiffrent color piece
		if ((*pieces_ptr)[newLocation]->getColor() == this->getColor()) {
			return 3;
		}
	}
	//check next row || same column
	if (newLocation[1] == currLocation[1] + 1 * isDown || newLocation[0] == currLocation[0]) {
		return 0;
	}

	if (this->hasMoved) {
		//check next next row || same column
		if (newLocation[1] == currLocation[1] + 2 * isDown || newLocation[0] == currLocation[0]) {
			return 0;
		}
	}

	return 6;
}