#pragma once
#include <iostream>
#include <map>

#define CORRECT 0
#define CHECK 1
#define NO_PIECE 2
#define PIECE_IN_LOCATION 3
#define CHECK_WILL_OCCUR 4
#define WRONG_INDEX 5
#define ILLEGAL_MOVEMENT 6
#define SAME_MOVE_LOCATION 7
#define CHECKMATE 8

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
	virtual bool canEat(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr);

	char getColor();
	std::string getLocation();
	void setLocation(std::string location);
	
	std::pair<std::string, std::string> getLocationPair(std::string location);
};

