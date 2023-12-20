#pragma once
#include "Board.h"
#include <iostream>
#include <map>

class BasePiece;
class BasePiece
{
private:
	std::string _location;
	char color; //b or w

public:
	BasePiece(std::string location, char color) : _location(location), color(color) {};
	//no use for constructor because we dont use anything, so we use c++ default constructor
	virtual int move(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr) = 0;
	virtual bool moveCheck(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr) = 0;
	virtual bool isCheck(Board* brd);

	char getColor();
	std::string getLocation();
	void setLocation(std::string location);
	
	std::pair<std::string, std::string> getLocationPair(std::string location);
};

