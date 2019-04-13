#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "hashTable2D.h"

using namespace std;

int main()
{
    HashTable   *table1 = new HashTable(500);
    HashTable2D *table2 = new HashTable2D(100, 5);
    int         input[100];
    int         results_1D[100];
    int         results_2D[100];
    int         sum_add_1D = 0;
    int         sum_add_2D = 0;
    int         sum_remove_1D = 0;
    int         sum_remove_2D = 0;

    srand(time(0));
    for (int i = 0; i < 100; i++)
    {
        input[i] = rand() % 100;
    }

    for (int i = 0; i < 50; i++)
    {
        results_1D[i] = table1->insert(input[i]);
        results_2D[i] = table2->insert(input[i]);
        sum_add_1D += results_1D[i];
        sum_add_2D += results_2D[i];
    }

    for (int i = 0; i < 50; i++)
    {
        if (i % 7 == 0)
        {
            results_1D[i] = table1->remove(input[i]);
            results_2D[i] = table2->remove(input[i]);
            sum_remove_1D += results_1D[i];
            sum_remove_2D += results_2D[i];
        }
    }

    for (int i = 50; i < 100; i++)
    {
        results_1D[i] = table1->insert(input[i]);
        results_2D[i] = table2->insert(input[i]);
        sum_add_1D += results_1D[i];
        sum_add_2D += results_2D[i];

    }

    cout << "Add Running Total-\t1D: "<<sum_add_1D << "\t 2D: " << sum_add_2D << endl;
    cout << "Remove Running Total-\t1D: " << sum_remove_1D << "\t 2D: " << sum_remove_2D << endl;
    /*
    for (int i = 0; i < 100; i++)
    {
        cout << i << ".\t" << results_1D[i] << '\t' << results_2D[i] << endl;
    }
    */
    //table1->print();
    //table2->print();



    return 0;
}