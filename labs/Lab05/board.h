#ifndef BOARD_H
#define BOARD_H
#include "base.h"
#include "entertainmentCollection.h"
#include <string>

#pragma once

class Board :public Base
{
	private:
		int position;

	public:
		Board();
        //Board(string n, int v);
		void Play();
		void Winner();
		int getPosition();
		void setPosition(int p);
};
#endif