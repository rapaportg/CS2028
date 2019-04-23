#include "queue.h"
#include <iostream>

using namespace std;

int main()
{
    Queue<int> *test = new Queue<int>();

    test->enqueue(1);
    test->enqueue(2);
    test->enqueue(3);
    test->enqueue(4);
    test->enqueue(5);
    test->enqueue(6);
    test->enqueue(7);
    test->enqueue(8);
    test->enqueue(9);
    test->print();
    cout << test->dequeue() << endl;
    test->print();


    return 0;



}