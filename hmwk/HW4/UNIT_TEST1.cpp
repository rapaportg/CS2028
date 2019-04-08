// UNIT TEST for 1D hash table class

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "hashTable1D.h"

using namespace std;

void    insert_TEST(HashTable1<int,int> *t)
{
    int ret;
    srand(time(0));

    cout << "\n\n\nPasses if the number of collisions isnt static per try\n";
    for (int i = 0; i < 100; i++)
    {
        cout << t->insert(rand()) << '\t';
    }
    cout << endl;
}

int     main()
{
    HashTable1<int, int> table;
    // function to test insert
    insert_TEST(&table);
    // function to test find

    // functiom to test print

    // function to test remove

    return 0;
}