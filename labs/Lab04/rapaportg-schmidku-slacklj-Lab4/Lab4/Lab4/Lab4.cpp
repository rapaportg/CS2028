// Lab4.cpp : Defines the entry point for the console application.
// This is the Test File

#include "stdafx.h"
#include "base.h"
#include "board.h"
#include "VidGame.h"
#include <iostream>

using namespace std;

void viewAndUpdate(Base &instGame)							// Overloaded function for choice 1
{
	string newName = " ";
	int newValue = 0;
	int tempValue = 0;

	cout << "The game's name is: " << instGame.getName() << endl;
	cout << "The game's value is: " << instGame.getValue() << endl;
	cout << "Please update the Game attributes: " << endl;
	cout << "New name -- ";
	cin >> newName;
	cout << "New value -- ";
	cin >> newValue;						
	while (cin.fail())							// Checks/resets cin register
	{
		cout << "Please enter an Integer" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> newValue;
	}
	cout << endl;

	instGame.setName(newName);					// Sets new attributes
	instGame.setValue(newValue);
};

void viewAndUpdate(Board &instBGame)							// Overloaded function for choice 2
{
	string newName = " ";
	int newPosition = 0;
	int newValue = 0;

	cout << "The Board game's name is: " << instBGame.getName() << endl;
	cout << "The Board game's position is: " << instBGame.getPosition() << endl;
	cout << "The game's value is: " << instBGame.getValue() << endl;
	cout << "Please update the Game attributes: " << endl;
	cout << "New name -- ";
	cin >> newName;
	cout << "New position -- ";
	cin >> newPosition;						
	while (cin.fail())							// Checks/resets cin register
	{
		cout << "Please enter an Integer" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> newPosition;
	}
	cout << "New Value -- ";
	cin >> newValue;						
	while (cin.fail())							// Checks/resets cin register
	{
		cout << "Please enter an Integer" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> newValue;
	}
	cout << endl;

	instBGame.setName(newName);					// Sets new attributes
	instBGame.setPosition(newPosition);
	instBGame.setValue(newValue);
};

void viewAndUpdate(VideoGame &instVGame)						// Overloaded function for choice 3
{
	string newName = " ";
	string newDisplay = " ";
	int newValue = 0;

	cout << "The Video game's name is: " << instVGame.getName() << endl;
	cout << "The Video game's display is: " << instVGame.getDisplay() << endl;
	cout << "The game's value is: " << instVGame.getValue() << endl;
	cout << "Please update the Game attributes: " << endl;
	cout << "New name -- ";
	cin >> newName;
	cout << "New display -- ";
	cin >> newDisplay;
	cout << "New value -- ";
	cin >> newValue;						
	while (cin.fail())							// Checks/resets cin register
	{
		cout << "Please enter an Integer" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> newValue;
	}
	cout << endl;

	instVGame.setName(newName);					// Sets new attributes
	instVGame.setDisplay(newDisplay);
	instVGame.setValue(newValue);
};

int userContinue(char cont_choice)							// Prompts to choose whether to continue. Returns choice
{
	cout << "Would you like to continue? \nEnter Y for yes, anything else for no: " << endl;
	cin >> cont_choice;
	return cont_choice;
}


int main()
{
	int user_choice;
	char cont_choice = 'Y';
	Base instGame;
	Board instBGame;
	VideoGame instVGame;
	Base instGameB("Board Game", 123456789);
	Base instGameV("Video Game", 5555);

	do
	{
		cout << "Press 1 for instance of game" << endl;								// Instance Menu
		cout << "Press 2 for instance of board game" << endl;
		cout << "Press 3 for instance of video game" << endl;
		cout << "Press 4 for instance of a board game declared as a game" << endl;
		cout << "Press 5 for instance of a video game declared as a game" << endl;
		cin >> user_choice;

		while (user_choice > 5 || user_choice < 1)									// Checks Input
		{
			cout << "Input out of range!" << endl << "Try Again" << endl;
			cin >> user_choice;
			while (cin.fail())														// Clears cin register
			{
				cout << "Please enter an Integer" << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cin >> user_choice;
			}
		}

		if (user_choice == 1)														// Calls member functions and overloaded
		{																			//	function based on menu choice
			instGame.Play();
			instGame.Winner();
			viewAndUpdate(instGame);
		}

		if (user_choice == 2)
		{
			instBGame.Play();
			instBGame.Winner();
			viewAndUpdate(instBGame);
		}

		if (user_choice == 3)
		{
			instVGame.Play();
			instVGame.Winner();
			viewAndUpdate(instVGame);
		}

		if (user_choice == 4)
		{
			instGameB.Play();
			instGameB.Winner();
			viewAndUpdate(instGameB);
		}

		if (user_choice == 5)
		{
			instGameV.Play();
			instGameV.Winner();
			viewAndUpdate(instGameV);
		}

		cont_choice = userContinue(cont_choice);									// Asks user whether or not to continue

	} while (cont_choice == 'y' || cont_choice == 'Y');
	
    return 0;
}

