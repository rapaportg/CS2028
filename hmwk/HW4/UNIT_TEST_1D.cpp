#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "hashTable.h"

using namespace std;

void INSERT_TEST()
{
    int size = 40;
    HashTable *test = new HashTable(size);
    int         tmp;

    cout << "\n  INSERT TEST: 1\n";
    cout << "--------------------------------------------------------------------------------------\n";
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

    test->reset();
    cout << "\n  INSERT TEST: 2\n";
    cout << "--------------------------------------------------------------------------------------\n";
    int check[50] = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 1, 0, 0, 0, 8, 0, 2, 1, 0, 0, 0, 1, 0, 1, 17, 1, 1, 22, 2, 2, 7, 28, 31, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40};
    int random[50] = {39, 13, 5, 4, 39, 10, 25, 17, 12, 6, 30, 7, 8, 36, 2, 38, 4, 10, 26, 15, 27, 6, 32, 26, 0, 21, 16, 20, 2, 23, 32, 1, 36, 30, 37, 27, 32, 15, 36, 4, 21, 19, 12, 22, 15, 6, 12, 11, 16, 38};

    for (int i = 0; i < size + 10; i++)
    {
        tmp = test->insert(random[i]);

        cout << i + 1 << ". \tValue Entered: " << random[i] << " \tSpot Checked: " << tmp << " \tExpected Checked: " << check[i];

        if (tmp == check[i])
            cout << " \tPASS\n";
        else
            cout << " \tFAIL\n";

    }
    cout << "\n";

}


int main()
{
    INSERT_TEST();
    return 0;
}