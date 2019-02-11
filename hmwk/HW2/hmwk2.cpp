#include <iostream>
#include <string>
#include "player.h"

using namespace std;

/*  //work in progress
int validIntInput(string outMsg)
{
    string input;
    int inputInt;

    cout << outMsg;
    getline(cin, input);

    while(cin.fail() || cin.eof() || input.find_first_not_of("0123456789") != string::npos)
    {

        cout << "Error" << endl;

        if(input.find_first_not_of("0123456789") == string::npos)
        {
            cin.clear();
            cin.ignore(256,'\n');
        }

        getline(cin, input);
    }

    string::size_type st;
    inputInt = stoi(input, &st);
    return inputInt;
}
*/ 

void playRound(Player *player, Player *house)
{
    string tmp = "";
    int wager;
    int guess = 0;
    int playerBalance = player->getBalance();

    cout << "Current Balance: " << playerBalance <<  endl;
    //wager = validIntInput("Enter your bet: ");
    do
    {
        cout << tmp;
        cout << "Enter your bet: ";
        cin >> wager;
        if (wager > playerBalance)
            tmp = "Error!\n";
    
    }while(wager > playerBalance);

    while(!(guess > 0 && guess <= player->wheel->getSize()))
    {   
        cout << "Enter your guess (1 - " << player->wheel->getSize() << "): ";
        cin >> guess;
    }

    if (player->getResult(guess))
    {
        cout <<"Winner!\n";
        playerBalance += wager;
    }
    else 
    {
        cout << "Loser!\n";
        playerBalance -= wager;
    }

    player->setBalance(playerBalance);
}

void initWheel(Player *player, Player *house)
{
    int size;
    bool validSize;
    do 
    {
        cout << "How many values should be on the wheel: (max: 20, min: 6) " << endl;
        cin >> size;

        if (size < 6 || size > 20)
        {
            cout << "Error invalid size!\n";
            validSize = false;
        }
        else
            validSize = true;

    }while (!validSize);

    player->resizeWheel(size);
    house->resizeWheel(size);
}



int main()
{
    Player *player = new Player();
    Player *house = new Player();
    bool keepPlaying = true;

    initWheel(player, house);
    // test
    //Player bob = Player(10, 10, 10);
    //cout << bob.getSpin() << endl;
    while(player->getBalance() != 0 && keepPlaying)
    {
        playRound(player, house);

    }
    //cout << player->wheel->getSize() << endl;
    //cout << house->wheel->getSize() << endl;


    return 0;
}