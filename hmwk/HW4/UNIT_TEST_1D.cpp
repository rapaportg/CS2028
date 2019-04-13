#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "hashTable.h"

using namespace std;

void    INSERT_TEST(HashTable *test)
{
    int     size = test->getMaxSize();
    int     tmp;

    cout << "Max Size: " << test->getMaxSize() << endl;
    cout << "INSERT TEST: 1 (Output of Max Size means the table is full)\t Hash: x % " << test->getMaxSize() << "\n";
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
    cout << "Max Size: " << test->getMaxSize() << endl;
    cout << "INSERT TEST: 2 (Output of Max Size means the table is full)\t Hash: x % " << test->getMaxSize() << "\n";
    cout << "-------------------------------------------------------------------------------------------------------------\n";
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

void    REMOVE_TEST(HashTable *test)
{
    cout << "Max Size: " << test->getMaxSize() << endl;
    cout << "REMOVE TEST: 1 (Output of Max Size + 1 means the item is on in the table)\t Hash: x % " << test->getMaxSize() << "\n";
    cout << "------------------------------------------------------------------------------------------------------------------------\n";
    int random[50] = {4, 36, 15, 32, 27, 37, 30, 36, 1, 32, 23, 2, 20, 16, 21, 0, 26, 32, 6, 27, 15, 26, 10, 4, 38, 2, 99, 8, 7, 30, 6, 12, 17, 25, 10, 39, 4, 5, 13, 39};
    int check[50] = {0, 0, 0, 0, 0, 22, 0, 1, 17, 1, 0, 0, 0, 0, 0, 1, 0, 2, 0, 2, 7, 2, 0, 5, 0, 1, 41, 0, 0, 1, 8, 0, 0, 0, 1, 0, 31, 0, 0, 1, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41};
    int tmp = 0;

    for (int i = 0; i < test->getMaxSize() + 10; i++)
    {
        tmp = test->remove(random[i]);

        cout << i + 1 << ". \tValue Entered: " << random[i] << " \tSpots Checked: " << tmp << " \tExpected Checked: " << check[i];

        if (tmp == check[i])
            cout << " \tPASS\n";
        else
            cout << " \tFAIL\n";
    }
    cout << endl;

}

void    FIND_TEST(HashTable *test)
{
    cout << "Max Size: " << test->getMaxSize() << endl;
    cout << "FIND TEST: 1 (Output of Max Size + 1 means the item is on in the table)\t Hash: x % " << test->getMaxSize() << "\n";
    cout << "------------------------------------------------------------------------------------------------------------------------\n";
    int random[50] = {4, 36, 15, 32, 27, 37, 30, 36, 1, 32, 23, 2, 20, 16, 21, 0, 26, 32, 6, 27, 15, 26, 10, 4, 38, 2, 99, 8, 7, 30, 6, 12, 17, 25, 10, 39, 4, 5, 13, 39};
    int check[50] = {0, 0, 0, 0, 0, 22, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int tmp = 0;

    for (int i = 0; i < test->getMaxSize() + 10; i++)
    {

        tmp = test->find(random[i]);

        cout << i + 1 << ". \tValue Entered: " << random[i] << " \tSpots Checked: " << tmp << " \tExpected Checked: " << check[i];

        if (tmp == check[i])
            cout << " \tPASS\n";
        else
            cout << " \tFAIL\n";

        //cout << tmp << ", ";
    }
    cout << endl;
}

int     main()
{
    HashTable *test = new HashTable(40);

    INSERT_TEST(test);
    FIND_TEST(test);
    test->print();
    REMOVE_TEST(test);
    test->print();
    return 0;
}