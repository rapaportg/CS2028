#include <iostream>
#include <string>
#include "player.h"
#include <cstdlib>
#include <ctime>

using namespace std;


/*#################################################

TODO:
    - convert hard mode to use derived class. Is setup for that.

    - add player cash out


###################################################*/

// work in progress
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
            cout << "Error invalid number!\n";
            validSize = false;
        }
        else
            validSize = true;

    }while (!validSize);

    return ret;
}

int validIntInput(string outputMsg)
{
    string tmp;
    const char *str;
    int ret;

    do
    {
        cout << outputMsg;
        cin >> tmp;
        str = tmp.c_str();
        while (!isdigit(*str))
        {
            str++;
        }
        ret = atoi(str);

    }while (ret == 0);

    return ret;
}

void playRound(Player *player)
{
    int wager;
    int guess = 0;
    int playerBalance = player->getBalance();

    cout << "Current Balance: " << playerBalance <<  endl;
    wager = validIntInput("Enter your bet: ", 1, playerBalance);
    guess = validIntInput("Enter you Guess ", 1, player->wheel->getSize());

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

void playRound(Player *player, Player *house)
{
    int wager;
    int guess = 0;
    int i;

    cout << "Current Balance: " << player->getBalance() <<  endl;
    wager = validIntInput("Enter your bet: ", 1, player->getBalance());
    guess = validIntInput("Enter your Guess ", 1, player->wheel->getSize());

    if (player->getResult(guess))
    {   
        srand(time(NULL)+10);
        i = rand()%house->wheel->getSize() + 1;
        cout << endl << i << endl << endl;
        if (house->getResult(i))
        {
            cout << "\nLoser! House Wins!\n";
            player->setBalance(player->getBalance() - wager);
            house->setHeat(house->getHeat() + 1);
            
            if (house->getHeat() >= 2 && house->wheel->getSize() > player->wheel->getSize())
            {
                house->resizeWheel(house->wheel->getSize() - 1);
                house->setHeat(0);
            }
        }
        else
        {
            cout << "\nPlayer Wins!\n";
            player->setBalance(player->getBalance() + wager);
            house->resizeWheel(house->wheel->getSize() + 1);
            house->setHeat(0);

        }

    }
    else 
    {
        cout << "\nLoser! House Wins!\n";
        player->setBalance(player->getBalance() - wager);
        house->setHeat(house->getHeat() + 1);

        if (house->getHeat() >= 2 && house->wheel->getSize() > player->wheel->getSize())
        {
            house->resizeWheel(house->wheel->getSize() - 1);
            house->setHeat(0);
        }
        

    }
    cout << "House Heat: " << house->getHeat() << endl;
    cout << "Player Wheel Size: " << player->wheel->getSize() << endl;
    cout << "House Wheel size: " << house->wheel->getSize() << endl;

}

void initWheel(Player *player, Player *house)
{
    int size;
    size = validIntInput("How many values should be on the wheel ", 6, 20);
    cout << endl << size << endl << endl;
    player->resizeWheel(size);
    house->resizeWheel(size);

    cout << "Player Wheel Size: " << player->wheel->getSize() << endl;
    cout << "House Wheel size: " << house->wheel->getSize() << endl;

}

int main()
{
    Player *player = new Player();
    Player *house = new Player();
    char mode;
    bool keepPlaying = true;

    cout << "Enter a game mode Hard (h) or Easy (e): ";
    cin >> mode;
    initWheel(player, house);

    if (mode == 'e')
    {
        while(player->getBalance() != 0 && keepPlaying)
        {
            playRound(player);
        }

    }
    if (mode == 'h')
    {
        while(player->getBalance() != 0 && keepPlaying)
        {
            playRound(player, house);
        }

    }
    return 0;
}