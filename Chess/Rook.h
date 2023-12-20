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
	//again no use for constructor, so we use default constructor

	
	bool moveCheck(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr) override;
	int move(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr) override;

};

