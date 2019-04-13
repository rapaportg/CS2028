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
    cout << "INSERT TEST: (Output of Max Size + 2 means the table is full)\t Hash: x % " << test->getMaxSize() << "\n";
    cout << "-------------------------------------------------------------------------------------------------------------\n";
    int check[50] = {1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 2, 1, 1, 1, 9, 1, 3, 2, 1, 1, 1, 2, 1, 2, 18, 2, 2, 23, 3, 3, 8, 29, 32, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41};
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
    cout << "REMOVE TEST: (Output of Max Size + 2 means the item is on in the table)\t Hash: x % " << test->getMaxSize() << "\n";
    cout << "------------------------------------------------------------------------------------------------------------------------\n";
    int random[50] = {19, 22, 35, 21, 9, 6, 35, 18, 17, 28, 19, 36, 3, 10, 31, 6, 17, 15, 37, 26, 15, 21, 20, 3, 35, 22, 33, 14, 33, 35, 21, 4, 17, 8, 25, 18, 6, 21, 28, 23, 9, 7, 19, 4, 9, 10, 10, 18, 17, 39};
    int check[50] = {42, 42, 42, 1, 42, 1, 42, 42, 1, 42, 42, 1, 42, 1, 42, 9, 42, 1, 23, 1, 8, 42, 1, 42, 42, 42, 42, 42, 42, 42, 42, 1, 42, 1, 1, 42, 42, 42, 42, 1, 42, 1, 42, 6, 42, 2, 42, 42, 42, 1};
    int tmp = 0;

    srand(time(0));
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
    cout << "FIND TEST: (Output of Max Size + 1 means the item is on in the table)\t Hash: x % " << test->getMaxSize() << "\n";
    cout << "------------------------------------------------------------------------------------------------------------------------\n";
    int random[50] = {4, 36, 15, 32, 27, 37, 30, 36, 1, 32, 23, 2, 20, 16, 21, 0, 26, 32, 6, 27, 15, 26, 10, 4, 38, 2, 99, 8, 7, 30, 6, 12, 17, 25, 10, 39, 4, 5, 13, 39};
    int check[50] = {1, 1, 1, 1, 1, 23, 1, 1, 18, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 42, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    int tmp = 0;

    for (int i = 0; i < test->getMaxSize() + 10; i++)
    {
        tmp = test->find(random[i]);

        cout << i + 1 << ". \tValue Entered: " << random[i] << " \tSpots Checked: " << tmp << " \tExpected Checked: " << check[i];

        if (tmp == check[i])
            cout << " \tPASS\n";
        else
            cout << " \tFAIL\n";

    }
    cout << endl;
}

int     main()
{
    HashTable *test = new HashTable(40);

    test->print();
    INSERT_TEST(test);
    test->print();
    FIND_TEST(test);
    test->print();
    REMOVE_TEST(test);
    test->print();
    return 0;
}