#pragma once
#include <iostream>
#include <map>

class Board;

class BasePiece
{
private:
	std::string _location;
	char color; //b or w

public:
	BasePiece(std::string location, char color) : _location(location), color(color) {};
	//no use for constructor because we dont use anything, so we use c++ default constructor
	virtual int move(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr);
	virtual int moveCheck(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr) = 0;


	char getColor();
	std::string getLocation();
	void setLocation(std::string location);
	
	std::pair<std::string, std::string> getLocationPair(std::string location);
};

