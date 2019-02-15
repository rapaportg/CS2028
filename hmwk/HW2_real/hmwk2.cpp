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

bool YNInput(string msg)
{
    char input;

    while (true)
    { 
        cout << msg << endl;
        cin >> input;

        if (toupper(input) == 'Y')
            return true;
        else if (toupper(input) == 'N')
            return false;
        else
        {
            cout << "Invalid Input!" << endl;
        }
    }

}
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
        while (!isdigit(*str) && *str != '\0')
        {
            str++;
        }
        ret = atoi(str);
        //cout << ret << endl;

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
    guess = validIntInput("Enter you Guess ", 1, player->getSize());

    if (player->spin(guess))
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

    wager = validIntInput("Enter your bet: ", 1, player->getBalance());
    guess = validIntInput("Enter your Guess ", 1, player->getSize());

    if (player->spin(guess))
    {   
        srand(time(NULL)+10);
        i = rand()%house->getSize() + 1;
        cout << endl << "House Guess: " << i << endl;
        if (house->spin(i))
        {
            cout << "\nLoser! House Wins!\n";
            player->setBalance(player->getBalance() - wager);
            house->setHeat(house->getHeat() + 1);
            
            if (house->getHeat() >= 2 && house->getSize() > player->getSize())
            {
                house->resizeWheel(house->getSize() - 1);
                house->setHeat(0);
            }
        }
        else
        {
            cout << "\nPlayer Wins!\n";
            player->setBalance(player->getBalance() + wager);
            house->resizeWheel(house->getSize() + 1);
            house->setHeat(0);

        }

    }
    else 
    {
        cout << "\nLoser! House Wins!\n";
        player->setBalance(player->getBalance() - wager);
        house->setHeat(house->getHeat() + 1);

        if (house->getHeat() >= 2 && house->getSize() > player->getSize())
        {
            house->resizeWheel(house->getSize() - 1);
            house->setHeat(0);
        }
        

    }
    cout << "House Heat: " << house->getHeat() << endl;
    cout << "Player Wheel Size: " << player->getSize() << endl;
    cout << "House Wheel size: " << house->getSize() << endl;

}

void initWheel(Player *player, Player *house)
{
    int size;
    size = validIntInput("How many values should be on the wheel ", 6, 20);
    cout << endl << size << endl << endl;
    player->resizeWheel(size);
    house->resizeWheel(size);

    cout << "Player Wheel Size: " << player->getSize() << endl;
    cout << "House Wheel size: " << house->getSize() << endl;

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

    do
    { 
        if (mode == 'e')
        {
           
            playRound(player);
        }
        if (mode == 'h')
        {
            playRound(player, house);

        }
        
        cout << "Current Balance: " << player->getBalance() <<  endl;
        keepPlaying = YNInput("Do you want to cash out? Y/N ");
        
    }while(player->getBalance() > 0 && !keepPlaying);

    if (player->getBalance() <= 0)
        cout << "\nGAME OVER\n";
    else
        cout << "Congratulations you ended with $" << player->getBalance() << endl;

    return 0;
}