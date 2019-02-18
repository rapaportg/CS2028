#include "board.h"
#include <iostream>
#include <string>

using namespace std;

Board::Board()
{
	setName("Board Game");
	setValue(123456789);
	position = 0;
}

/*
Board::Board(string n, int v):Base(n,v)
{
    setName("Board Game");
	setValue(123456789);
	position = 0;
}
*/

void Board::Play()
{
	cout << "Roll the Dice" << endl;
}

void Board::Winner()
{
	cout << "Dancing Time!" << endl;
}

void Board::setPosition(int p)
{
	position = p;
}

int Board::getPosition()
{
	return position;
} 