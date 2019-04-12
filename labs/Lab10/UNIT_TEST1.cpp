#include <iostream>
#include <string>
#include "hashTable.h"

using namespace std;

int main()
{
    HashTable<string>   *table;

    table = new HashTable<string>();
    table->addItem("a");
    table->addItem("b");
    table->addItem("c");
    table->addItem("d");
    table->addItem("eeeeeeeeeeee");
    table->addItem("f");
    table->addItem("g");

    table->print();

    table->removeItem("c");
    cout << "\n\n\n";
    table->print();
}