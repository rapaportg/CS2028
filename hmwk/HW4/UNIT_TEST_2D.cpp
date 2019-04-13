#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "hashTable2D.h"

using namespace std;

void    TEST_INSERT(HashTable2D *table)
{
    cout << "\nMax Length: " << table->getMaxLength() << "\tMax Depth: " << table->getMaxDepth() << endl;
    cout << "INSERT TEST: (Output of Max Depth means + 1 the Bucket is full)\t Hash: x % " << table->getMaxLength() << "\n";
    cout << "-----------------------------------------------------------------------------------------------\n";
    int random[100] = {19, 8, 16, 8, 9, 14, 23, 19, 15, 21, 14, 9, 6, 13, 6, 19, 9, 27, 18, 1, 6, 6, 5, 24, 15, 22, 27, 3, 21, 20};
    int check[100] = {1, 1, 1, 2, 2, 1, 1, 3, 1, 1, 2, 4, 2, 2, 3, 4, 4, 1, 3, 2, 4, 4, 2, 3, 3, 1, 2, 3, 3, 1};
    int tmp;


    for (int i = 0; i < table->getMaxDepth() * table->getMaxLength(); i++)
    {
        tmp = table->insert(random[i]);
        cout << i + 1 << ".\tValue Entered: " << random[i] << "\tSpots Checked: " << tmp << "\tExpected Spots Checked: " << check[i];
        if (tmp == check[i])
            cout << "\tPASS";
        else
            cout << "\tFAIL";

        cout << endl;
    }
}

void    TEST_FIND(HashTable2D *table)
{
    cout << "\nMax Length: " << table->getMaxLength() << "\tMax Depth: " << table->getMaxDepth() << endl;
    cout << "FIND TEST: (Output of Max Depth + 1 means the Item is not in the table)\t Hash: x % " << table->getMaxLength() << "\n";
    cout << "-----------------------------------------------------------------------------------------------\n";
    int random[30] = {18, 3, 25, 29, 13, 8, 12, 26, 24, 0, 23, 23, 23, 24, 22, 10, 6, 23, 17, 1, 7, 11, 15, 29, 19, 8, 3, 27, 15, 15};
    int check[30] = {3, 3, 4, 4, 2, 1, 4, 4, 3, 2, 1, 1, 1, 3, 1, 4, 2, 1, 4, 2, 4, 4, 1, 4, 1, 1, 3, 1, 1, 1};

    for (int i = 0; i < table->getMaxDepth() * table->getMaxLength(); i++)
    {
        int tmp = table->find(random[i]);
        cout << i + 1 << ".\tValue Entered: " << random[i] << "\tSpots Checked: " << tmp << "\tExpected Spots Checked: " << check[i];
        if (tmp == check[i])
            cout << "\tPASS";
        else
            cout << "\tFAIL";

        cout << endl;
    }

}

void    TEST_REMOVE(HashTable2D *table)
{
    cout << "\nMax Length: " << table->getMaxLength() << "\tMax Depth: " << table->getMaxDepth() << endl;
    cout << "REMOVE TEST: (Output of Max Depth + 1 means the Item is not in the table)\t Hash: x % " << table->getMaxLength() << "\n";
    cout << "-----------------------------------------------------------------------------------------------\n";

    int random[30] = {15, 7, 19, 4, 22, 19, 3, 29, 28, 15, 14, 9, 15, 8, 14, 8, 21, 13, 9, 22, 0, 27, 6, 15, 9, 24, 9, 2, 15, 28};
    int check[30] = {1, 4, 1, 4, 1, 1, 3, 4, 4, 1, 1, 2, 1, 1, 1, 1, 1, 2, 2, 1, 2, 1, 2, 1, 2, 3, 2, 4, 1, 4};

    for (int i = 0; i < table->getMaxDepth() * table->getMaxLength(); i++)
    {
        int tmp = table->remove(random[i]);
        cout << i + 1 << ".\tValue Entered: " << random[i] << "\tSpots Checked: " << tmp << "\tExpected Spots Checked: " << check[i];
        if (tmp == check[i])
            cout << "\tPASS";
        else
            cout << "\tFAIL";

        cout << endl;
    }
}

int     main()
{

    HashTable2D *table = new HashTable2D(10, 3);

    table->print();
    TEST_INSERT(table);
    table->print();
    TEST_FIND(table);
    table->print();
    TEST_REMOVE(table);
    table->print();

    return 0;
}