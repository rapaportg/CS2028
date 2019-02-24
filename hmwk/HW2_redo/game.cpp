#include <iostream>
#include "player.h"

using namespace std;

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

// You every get that problem where you go to enter a number in c++ and you get that really annoy error
// where it spases out in the terminal if you enter anything besides a number. Well look no farther. 
// here a better input function than just cin. 
// Note: it woulds just like atoi so if a number it hidden in a jumble of letter it will find it. just the first one.

int validIntInput(string outputMsg) {
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

int validIntInput(string outputMsg, int min, int max) // just like the other validIntInput but this one has an option valid range toooooo
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

void initWheel(Player *player, Player *house) // set the starting size for the wheel
{
    int size;
    size = validIntInput("How many values should be on the wheel ", 6, 20);
    cout << endl << size << endl << endl;
    player->setSize(size);
    house->setSize(size);
}

void printStats(Player *p, Player *h)
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "house Heat: " << h->getHeat() << endl;
    cout << "House Size: " << h->getSize() << endl;
    cout << "Wheel Size: " << p->getSize() << endl;
    cout << "Your Balance: $" << p->getBalance() << endl;
    cout << "Your Current Wager: $" << p->getWager() << endl;
    cout << "You Spin: " << p->getSpin() << endl;
    cout << "House Spin: " << h->getSpin() << endl;
    cout << "-------------------------------------------\n";
}

void printOptions()
{
    cout << "1 - Spin \n";
    cout << "2 - Raise Bet\n";
    cout << "3 - Cash out\n";
}

void printOptions2()
{
    cout << "0 - to continue\n";
    cout << "1 - Raise Bet\n";
    cout << "2 - Cash out\n";
}

void printMenu(Player *p, Player *h)
{
    printStats(p, h);
    printOptions();
}

void printMenu2(Player *p, Player *h)
{
    printStats(p, h);
    printOptions2();
}

bool balanceVsWager(Player *p)
{
    if (p->getBalance() <= (p->getWager() * 2))
        return true;
    else 
        return false;
}

void isWagerValid(Player *p)
{
    if (p->getWager() > p->getBalance())
        p->setWager(p->getBalance());
}

void playEasy(Player *player, Player *house)
{
    bool keepPlaying = true;
    int menuIn;
    while (player->getBalance() > 0 && keepPlaying)
    {
        isWagerValid(player);
        printMenu(player, house);
        menuIn = validIntInput("Enter option: ", 1, 3);
        if (menuIn == 1)
        {
            player->Spin();
            printMenu2(player, house);
            menuIn = validIntInput("Enter option: ", 0, 2);
            if (menuIn == 1)
            {
                player->setWager(validIntInput("Enter new wager: ", player->getWager(), balanceVsWager(player) ? player->getBalance():player->getWager() * 2));
            }
            if (menuIn == 2)
            {
                cout << "Thanks for playing\n";
                return;
            }
            house->Spin();
            if (player->getSpin() > house->getSpin())
            {
                player->setBalance(player->getBalance() + player->getWager());
            }
            else
            {
                player->setBalance(player->getBalance() - player->getWager());
            }
        }
        if (menuIn == 2)
        {
            player->setWager(validIntInput("Enter new wager: ", player->getWager(), balanceVsWager(player) ? player->getBalance():player->getWager() * 2));
        }
        if (menuIn == 3)
        {
            return;
        }
    }
}

void playHard(Player *player, Player *house)
{
    bool keepPlaying = true;
    int menuIn;
    while (player->getBalance() > 0 && keepPlaying)
    {
        isWagerValid(player);
        printMenu(player, house);
        menuIn = validIntInput("Enter option: ", 1, 3);
        if (menuIn == 1)
        {
            player->Spin();
            printMenu2(player, house);
            menuIn = validIntInput("Enter option: ", 0, 2);
            if (menuIn == 1)
            {
                player->setWager(validIntInput("Enter new wager: ", player->getWager(), balanceVsWager(player) ? player->getBalance():player->getWager() * 2));
            }
            if (menuIn == 2)
            {
                cout << "Thanks for playing\n";
                return;
            }
            house->Spin(player);
            if (player->getSpin() > house->getSpin())
            {
                player->setBalance(player->getBalance() + player->getWager());
            }
            else
            {
                player->setBalance(player->getBalance() - player->getWager());
            }
        }
        if (menuIn == 2)
        {
            player->setWager(validIntInput("Enter new wager: ", player->getWager(), balanceVsWager(player) ? player->getBalance():player->getWager() * 2));
        }
        if (menuIn == 3)
        {
            return;
        }
    }
}

int main()
{
    Player *player = new Player();
    Player *house = new Player();  
    int wager;
    
    initWheel(player, house);

    if(YNInput("Would you like to play the hard mode? Y/N "))
        playHard(player, house);
    else 
        playEasy(player, house);

    cout << "You end balance is: $" << player->getBalance() << endl;
    cout << "Thanks for playing!" << endl;


    return 0;
}