#include <iostream>

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