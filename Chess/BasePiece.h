#pragma once
#include "Board.h"
#include <iostream>

class BasePiece
{
private:
	std::string _location;
	char color; //b or w

public:
	BasePiece(std::string location, char color) : _location(location), color(color) {};
	//no use for constructor because we dont use anything, so we use c++ default constructor
	virtual int move(std::string newLocation, std::map<BasePiece*, std::string>* pieces_ptr) = 0;
	virtual bool moveCheck(std::string newLocation, std::map<BasePiece*, std::string>* pieces_ptr) = 0;
	virtual bool isCheck(std::map<BasePiece*, std::string>* pieces_ptr) = 0;

	char getColor() { return this->color; };
	std::string getLocation() { return this->_location; };
	void setLocation(std::string location) { this->_location = location; };
	
	std::pair<std::string, std::string> getLocationPair(std::string location) { return std::pair<std::string, std::string>(location.substr(0,2),location.substr(2,2)); };
};

