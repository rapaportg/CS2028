//#include "stdafx.h"
#include "VidGame.h"
#include <iostream>
#include <string>

using namespace std;

VideoGame::VideoGame()
{
	setName("Video Game");
	setValue(5555);
	display = 0;
}

void VideoGame::Play()
{
	cout << "Mash the Buttons" << endl;
}

void VideoGame::Winner()
{
	cout << "Winner, winner, chicken dinner" << endl;
}

void VideoGame::setPosition(int d)
{
	//display = d;
	display = d;
}