#include "entertainmentCollection.h"
#include "board.h"
#include "VidGame.h"
#include <iostream>
#include <string>
#define INT_MAX 2147483647

using namespace std;

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

int validIntInput(string outputMsg) // accepts only positive integers
{
    string tmp;
    const char *str;
    bool validSize;
    int ret;

    do
    {
        cout << outputMsg;
        cin >> tmp;
        str = tmp.c_str();
        while (!isdigit(*str) && *str != '\0')
        {
            str++;
        }
        ret = atoi(str);
        //cout << ret << endl;

        if (ret < 0 || ret > INT_MAX)
        {
            cout << "Error invalid number!\n";
            validSize = false;
        }
        else
        {
            validSize = false;
            for(int x = 0; x < tmp.length(); x++)
            {
                if (isdigit(tmp[x++]))
                {
                    validSize = true;
                }
            }
        }

    }while (!validSize);

    return ret;
}

void pushHelper(EntertainmentCollection<Board> *s, Board *item)
{
    int value;
    string name;
    cout << "Enter a name for the new item" << endl;
    cin.ignore();
    getline(cin, name, '\n');
    cin.clear();
    cout << "Enter a value for the new item" << endl;
    value = validIntInput("A number: ");

    item->setName(name);
    item->setValue(value);
    s->push(item);
}

void pushHelper(EntertainmentCollection<VideoGame> *s, VideoGame *item)
{
    int value;
    string name;
    cout << "Enter a name for the new item" << endl;
    cin.ignore();
    getline(cin, name, '\n');
    cin.clear();
    cout << "Enter a value for the new item" << endl;
    value = validIntInput("A number: ");

    item->setName(name);
    item->setValue(value);
    s->push(item);
}

void printMenu()
{
    cout << "\nPress 1 to add an item to the Collection" << endl;
    cout << "Press 2 to remove an item from the Collection"  << endl;
    cout << "Press 3 to see how many items are on the Collection" << endl;
    cout << "Press 4 to quit" << endl;
}

int main()
{
    int type;
    int input;

    type = validIntInput("Which type of game do you want to enter? Board Game = 1, Video Game = 2 ", 1, 2);

    if (type == 1)
    {
        EntertainmentCollection<Board> *s;
        s = new EntertainmentCollection<Board>();
        s->setMaxSize(10);
        do
        {
            s->printCollection();
            printMenu();
            input = validIntInput("Enter: ", 1, 4);

            if (input == 1)
            {
                try
                {
                    Board *item = new Board();
                    pushHelper(s, item);
                }
                catch (EntertainmentCollection<Board>::StackOverFlowException err)
                {
                    cout << "\n\n\nStackOverFlow Error! There are already 10 items on the shelf";
                }
            }
            if (input == 2)
            {
                try
                {
                    Board removedGame;
                    removedGame = s->pop();
                    cout << "\nGame removed: " << removedGame.getName() << endl;
                }
                catch (EntertainmentCollection<Board>::StackUnderFlowException err)
                {
                    cout << "\n\n\nStackUnderFlow Error! No items in collection to remove.";
                }
            }
            if (input == 3)
            {
                cout << "There are " << s->getNumOfItems() << " items in the collection\n";
            }
        }while (input != 4);
    }

    if (type == 2)
    {
        EntertainmentCollection<VideoGame> *s;
        s = new EntertainmentCollection<VideoGame>();
        s->setMaxSize(10);
        do
        {
            s->printCollection();
            printMenu();
            input = validIntInput("Enter: ", 1, 4);

            if (input == 1)
            {
                try
                {
                    VideoGame *item = new VideoGame();
                    pushHelper(s, item);
                }
                catch (EntertainmentCollection<VideoGame>::StackOverFlowException err)
                {
                    cout << "\n\n\nStackOverFlow Error! There are already 10 items on the shelf";
                }
            }
            if (input == 2)
            {
                try
                {
                    VideoGame removedGame;
                    removedGame = s->pop();
                    cout << "\nGame removed: " << removedGame.getName() << endl;
                }
                catch (EntertainmentCollection<VideoGame>::StackUnderFlowException err)
                {
                    cout << "\n\n\nStackUnderFlow Error! No items in collection to remove.";
                }
            }
            if (input == 3)
            {
                cout << "There are " << s->getNumOfItems() << " items in the collection\n";
            }

        }while (input != 4);

    }
    return 0;
}