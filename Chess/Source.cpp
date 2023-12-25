/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project,
in order to read and write information from and to the Backend
*/

#include "Board.h"
#include "Pipe.h"
#include <iostream>
#include <thread>
#include <cstring>
using std::cout;
using std::endl;
using std::string;


void main()
{
	srand(time_t(NULL));


	Pipe p;
	bool isConnect = p.connect();

	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else
		{
			p.close();
			return;
		}
	}

	Board* brd = new Board();
	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE

	strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1");

	p.sendMessageToGraphics(msgToGraphics);   // send the board string	

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	BasePiece* blackKing = brd->pieces["d8"];
	BasePiece* whiteKing = brd->pieces["d1"];

	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)

		std::pair<string, string> locationPair = Board::getLocationPair(msgFromGraphics);

		auto it = brd->pieces.find(locationPair.first);
		BasePiece* piece = nullptr;
		if (it != brd->pieces.end())
		{
			piece = it->second;
		}
		
		if (piece && brd->isTurn(piece))
		{
			int ok = piece->move(locationPair.second, &(brd->pieces));
			brd->pieces.erase(locationPair.first);
			brd->pieces[locationPair.second] = piece;
			//black turn
			if (brd->isTurn(blackKing)) {
				if (brd->isOnCheck(blackKing)) {
					ok = 4;
				}
				else if (brd->isOnCheck(whiteKing)) {
					ok = 1;
				}
			}
			//white turn
			else {
				if (brd->isOnCheck(whiteKing)) {
					ok = 4;
				}
				else if (brd->isOnCheck(blackKing)) {
					ok = 1;
				}
			}

			if (!brd->isTurn(piece)) {// if the player tryes to mave a piece not on turn
				ok = 2;
			}

			if (ok == 0 || ok == 1)/* && brd->isTurn(piece))*/
			{
				brd->moveTurn();
			}
			else
			{
				piece->setLocation(locationPair.first);
				brd->pieces.erase(locationPair.second);
				brd->pieces[locationPair.first] = piece;
			}
			// YOUR CODE
			strcpy_s(msgToGraphics, std::to_string(ok).c_str()); // msgToGraphics should contain the result of the operation

			
		}
		else //if nothing in location
		{
			strcpy_s(msgToGraphics, std::to_string(2).c_str());
		}

		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}
	p.close();
}
