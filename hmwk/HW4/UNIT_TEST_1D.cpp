#include <iostream>
#include "hashTable.h"

using namespace std;

void INSERT_TEST()
{
    HashTable *test = new HashTable();
    int         tmp;

    for (int i = 0; i < 50; i++)
    {
        tmp = test->insert(i % 10);
        if (i < 10)
            cout << i << ".\tSpot Checked: " << tmp << "\tExpected Checked: " << 0;

        if (i < 20)
            cout << i << ".\tSpot Checked: " << tmp << "\tExpected Checked: " << i % 10;

    }

}


int main()
{
    INSERT_TEST();
    return 0;
}