#ifndef BOARD_H
#define BOARD_H
#include "base.h"

class Board :public Base
{
	private:
		int position;

	public:
		Board();
		void Play();
		void Winner();
		int getPosition();
		void setPosition(int p);
};
#endif