#ifndef VIDGAME_H
#define VIDGAME_H
#include <string>
#include "base.h"

class VideoGame :public Base
{
	private:
		std::string display;

	public:
		VideoGame();
		void Play();
		void Winner();
		void setDisplay(std::string d);
		std::string getDisplay();
};
#endif