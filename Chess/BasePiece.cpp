#include "BasePiece.h"

#include "Board.h"



int BasePiece::move(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr)
{
	int ok = moveCheck(newLocation, pieces_ptr);
	if (ok == 0)// all legal result(1 and 8 excluded because moveCheck dosnt suport check and mate)
	{
		this->setLocation(newLocation);
	}

	return ok;
}

bool BasePiece::canEat(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr)
{
	if(this->moveCheck(newLocation, pieces_ptr) == CORRECT){
		return true;
	}
	return false;
}

char BasePiece::getColor()
{
	return this->color;
}

std::string BasePiece::getLocation()
{
	return this->_location;
}

void BasePiece::setLocation(std::string location)
{
	this->_location = location;
}

std::pair<std::string, std::string> BasePiece::getLocationPair(std::string location)
{
	return std::pair<std::string, std::string>(location.substr(0, 2), location.substr(2, 2));
}
