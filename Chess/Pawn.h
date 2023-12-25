#pragma once
#include "Board.h"

class Pawn : public BasePiece
{
private:
	bool hasMoved;

public:
	Pawn(std::string location, char color) : BasePiece(location, color) { hasMoved = false; };
	//again no use for destructor, so we use default constructor

	
	int moveCheck(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr) override;
};

