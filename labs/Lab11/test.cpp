#include "sort.h"
#include <iostream>

using namespace std;

int main()
{
    int arr[9] = {1,69,6,1010,5,0,10,8,9};
    Sort<int> *tmp;
    tmp = new Sort<int>(arr);

    cout << tmp->getLength() << endl;
    tmp->print();
    //tmp->bubbleSort();
    tmp->insertionSort();
    tmp->print();
    return 0;
}
