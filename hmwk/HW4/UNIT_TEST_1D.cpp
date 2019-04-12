#include <iostream>
#include "hashTable.h"

using namespace std;

void INSERT_TEST()
{
    HashTable *test = new HashTable();
    int         tmp;
    int         x = 0;

    for (int i = 0; i < 50; i++)
    {
        tmp = test->insert(i % 10);
        if (i < 10)
        {
            cout << i << ". \tValue Entered: " << i % 10 << " \tSpot Checked: " << tmp << " \tExpected Checked: " << 0;
            if (0 == tmp)
                cout << " \tPASS\n";
            else
                cout << " \tFAIL\n";
        }
        else if (i >= 10 && i < 20)
        {
            cout << i << ". \tValue Entered: " << i % 10 << " \tSpot Checked: " << tmp << " \tExpected Checked: " << 10;
            if (10 == tmp)
                cout << " \tPASS\n";
            else
                cout << " \tFAIL\n";
        }
        else if (i >= 20 && i < 30)
        {
            cout << i << ". \tValue Entered: " << i % 10 << " \tSpot Checked: " << tmp << " \tExpected Checked: " << 20;
            if (20 == tmp)
                cout << " \tPASS\n";
            else
                cout << " \tFAIL\n";
        }
        else if (i >= 30 && i < 40)
        {
            cout << i << ". \tValue Entered: " << i % 10 << " \tSpot Checked: " << tmp << " \tExpected Checked: " << 30;
            if (30 == tmp)
                cout << " \tPASS\n";
            else
                cout << " \tFAIL\n";
        }
        else if (i >= 40 && i < 50)
        {
            cout << i << ". \tValue Entered: " << i % 10 << " \tSpot Checked: " << tmp << " \tExpected Checked: " << 40;
            if (40 == tmp)
                cout << " \tPASS\n";
            else
                cout << " \tFAIL\n";
        }


    }

}


int main()
{
    INSERT_TEST();
    return 0;
}