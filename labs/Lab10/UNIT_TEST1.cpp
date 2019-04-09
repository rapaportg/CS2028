#include <iostream>
#include <string>
#include "hashTable.h"

using namespace std;

int main()
{
    HashTable<int,string>   *table;

    table = new HashTable<int,string>();
    table->print();
}