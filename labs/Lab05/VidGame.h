#ifndef VIDGAME_H
#define VIDGAME_H
#include <string>
#include "base.h"
//#include "entertainmentCollection.h"

class VideoGame :public Base
{
	private:
		int display;

	public:
		VideoGame();
		void Play();
		void Winner();
		void setPosition(int d);
		std::string getDisplay();
};
#endif