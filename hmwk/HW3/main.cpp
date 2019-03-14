#include "player.h"
#include <iostream>
#include <string>

using namespace std;


int validIntInput(string outputMsg, int min, int max)
{
	string tmp;
	const char *str;
	bool validSize;
	int ret;

	do
	{
		cout << outputMsg << "(" << min << " - " << max << "): ";
		cin >> tmp;
		str = tmp.c_str();
		while (!isdigit(*str))
		{
			str++;
		}
		ret = atoi(str);

		if (ret < min || ret > max)
		{
			cout << "Error invalid input!\n";
			validSize = false;
		}
		else
			validSize = true;

	} while (!validSize);

	return ret;
}


void computerMove(Player *cpu)
{
	std::vector<int> * theHand = cpu->getHand();
	if (theHand->at(0) > 10)
	{	
		return;	
	}
	else if (theHand->at(0) > 6)
	{
		if (!cpu->isSidePileFull() && cpu->cardsLeftInDeck() != 0)
		{
			cpu->pushToSide();
			cpu->draw();
			return;
		}
		else 
		{
			return;	
		}
	}
	else if (theHand->at(0) > 3)
	{
		if (!cpu->isSidePileEmpty())
		{
			cpu->getFromPile();
			return;
		}
		else 
		{	
			return;	
		}
	}
	else 
	{	
		return;	
	}
}


void playRound(Player *me, Player *cpu)
{
	int input;


	me->clearHand();
	cpu->clearHand();	
	if (me->cardsLeftInDeck() == 0 && !me->isSidePileEmpty() && cpu->cardsLeftInDeck() != 0)
	{
		me->getFromPile();
		cpu->draw();
	}
	if (cpu->cardsLeftInDeck() == 0 && !cpu->isSidePileEmpty() && me->cardsLeftInDeck() != 0)
	{
		cpu->getFromPile();
		me->draw();
	}
	if (cpu->cardsLeftInDeck() == 0 && !cpu->isSidePileEmpty() && me->cardsLeftInDeck() == 0 && !me->isSidePileEmpty())
	{
		me->getFromPile();			// This block is redundant...
		cpu->getFromPile();
	}
	if (me->cardsLeftInDeck() != 0 && cpu->cardsLeftInDeck() != 0)
	{
		me->draw();
		cpu->draw();
	}

	cout << "\nCards left in your deck: " << me->cardsLeftInDeck() << endl;
	cout << "Cards left in CPU deck: " << cpu->cardsLeftInDeck();

	me->peekHand();
	me->peekSidePile();
	cout << endl;
	if (!me->isSidePileEmpty() && !me->isSidePileFull() && me->cardsLeftInDeck() != 0)
	{
		cout << "\n1. Save Card in side pile" << endl;
		cout << "2. Draw from side pile" << endl;
		cout << "3. Do Nothing" << endl;
		input = validIntInput("What would you like to do?", 1, 3);
	}
	else if ((!me->isSidePileEmpty() && me->isSidePileFull()) || (!me->isSidePileEmpty() && me->cardsLeftInDeck() == 0))
	{
		cout << "\n2. Draw from side pile" << endl;
		cout << "3. Do Nothing" << endl;
		input = validIntInput("What would you like to do?", 2, 3);
	}
	else
	{
		if (me->isSidePileEmpty() && me->cardsLeftInDeck() == 0)
		{
			input = 3;
		}
		else
		{
			input = 2;

			cout << "\n1. Save Card in side pile" << endl;
			cout << "3. Do Nothing" << endl;
			input = validIntInput("What would you like to do?", 1, 3);

			while (input == 2)
			{
				cout << "Error invaild input!" << endl;
				input = validIntInput("What would you like to do?", 1, 3);
			}
		}
	}

	computerMove(cpu);

	if (input == 1)
	{
		me->pushToSide();
		me->draw();
	}
	else if (input == 2)
	{
		me->getFromPile();
	}


	me->peekHand();
	me->peekSidePile();

	if (me->handSum() > cpu->handSum())
	{
		cout << "\n\nWinner! you: " << me->handSum() << "\t cpu: " << cpu->handSum();
		me->addToHand(cpu->getHand());
		me->bury();
	}
	else
	{
		cout << "\nLoser! you: " << me->handSum() << "\t cpu: " << cpu->handSum();
		cpu->addToHand(me->getHand());
		cpu->bury();
	}

}

int main()
{
	Player *me;
	Player *computer;
	string user_choice;


	me = new Player();

	cout << "Would you like to play War?" << endl << "Enter 1 for yes, and anything else for no: ";
	cin >> user_choice;
	if (user_choice != "1")
	{
		return 0;
	}
	cout << "Whatever you do, don't run out of cards!" << endl << "You lose if you run out of cards... " << endl;

	computer = new Player(); //initalized computer deck after a user input to allow enough time for a new random seed



	while ( (me->cardsLeftInDeck() != 0 || me->isSidePileEmpty() == false) && (computer->cardsLeftInDeck() != 0 || computer->isSidePileEmpty() == false) )
	{
		cout << "\n------------------------------------------\n\n";
		playRound(me, computer);
	}

	if (me->cardsLeftInDeck() == 0)
	{
		cout << "\nThe computer wins! Keep practicing... " << endl;
	}
	else if (computer->cardsLeftInDeck() == 0)
	{
		cout << "\nYou win! Now get back to work! " << endl;
	}

	return 0;
}
