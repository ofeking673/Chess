#pragma once
#include "BasePiece.h"
#include <iostream>
#include <map>

#define BoardLength 8

class Board;

class Bishop : public BasePiece
{
public:
	Bishop(std::string location, char color) : BasePiece(location, color) {};
	//again no use for constructor, so we use default constructor


	int moveCheck(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr) override;
};

