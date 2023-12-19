#pragma once
#include "Board.h"
#include <iostream>

class BasePiece
{
private:
	std::string location;
	char color; //b or w

public:
	virtual void move(std::string newLocation) = 0;
	virtual bool moveCheck(std::string newLocation) = 0;
	virtual bool isCheck() = 0;
	char getColor() { return this->color; };
	std::string getLocation() { return this->location; };
};

