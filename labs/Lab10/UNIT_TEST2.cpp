#include <iostream>
#include <string>
#include "chainedHashTable.h"


int validIntInput(string outputMsg) {
    string tmp;
    const char *str;
    int ret;

    do
    {
        cout << outputMsg;
        cin >> tmp;
        str = tmp.c_str();
        while (!isdigit(*str))
        {
            str++;
        }
        ret = atoi(str);

    }while (ret == 0);

    return ret;
}


int main()
{

    ChainedHashTable<string>    *test_str = new ChainedHashTable<string>();
    ChainedHashTable<int>       *test_int = new ChainedHashTable<int>();

    for (int i = 0; i < 20; i++)
    {
        string  tmp;
        cout << "enter a string: ";
        cin  >> tmp;
        test_str->addItem(tmp);
    }
    test_str->print();





    return 0;
}