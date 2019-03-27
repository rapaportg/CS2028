#include "btree.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    BTree<string> *test = new BTree<string>();

    for (int i = 0; i < 100; i++)
    {
        string s = to_string(i);
        cout << i << endl;
        test->insert(s);
    }
    return 0;
}