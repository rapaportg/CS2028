#include <iostream>
#include <string>
#include "hashTable.h"

using namespace std;

int main()
{
    HashTable<int,string>   *table;

    table = new HashTable<int,string>();
    table->addItem("a");
    table->addItem("b");
    table->addItem("c");
    table->addItem("d");
    table->addItem("e");
    table->addItem("f");
    table->addItem("g");

    table->print();

    table->removeItem("c");
    cout << "\n\n\n";
    table->print();
}