#include "BasePiece.h"

#include "Board.h"

bool BasePiece::isCheck(Board* brd)
{
	int i = 0, j = 0;
	std::string kingCords = "";

	for (i = 0; i < BoardLength; i++) {//finds king cordinates
		
		for (j = 0; j < BoardLength; j++) {
			if (brd->_board[i * BoardLength + j] == 'K' + ((this->color) = 'w' ? ('k' - 'K') : 0)) {
				kingCords += char('a' + i);
				kingCords += char('0' + i);
				j = BoardLength;
				i = BoardLength;
			}
		}
	}

	return (this->moveCheck(kingCords, &(brd->pieces)));
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
