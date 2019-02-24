#include "stdafx.h"
#include "VidGame.h"
#include <iostream>
#include <string>

using namespace std;

VideoGame::VideoGame()
{
	setName("Video Game");
	setValue(5555);
	display = "Video Game Display";
}

void VideoGame::Play()
{
	cout << "Mash the Buttons" << endl;
}

void VideoGame::Winner()
{
	cout << "Winner, winner, chicken dinner" << endl;
}

void VideoGame::setDisplay(string d)
{
	display = d;
}

string VideoGame::getDisplay()
{
	return display;
}


