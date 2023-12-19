#pragma once
#include "Board.h"

class Rook : public BasePiece
{
public:
	Rook(std::string location, char color) : BasePiece(location, color) {};
	//again no use for constructor, so we use default constructor

	
	bool moveCheck(std::string newLocation) override;
	bool isCheck() override;
	int move(std::string newLocation) override;

};

