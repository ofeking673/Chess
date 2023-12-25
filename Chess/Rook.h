#pragma once
#include "BasePiece.h"
#include <iostream>
#include <map>

#define BoardLength 8

class Board;

class Rook : public BasePiece
{
public:
	Rook(std::string location, char color) : BasePiece(location, color) {};
	Rook(BasePiece* piece) : BasePiece(piece->getLocation(), piece->getColor()) {};
	//again no use for constructor, so we use default constructor

	
	int moveCheck(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr) override;
};

