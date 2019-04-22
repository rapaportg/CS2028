#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
    Stack<int> *stack = new Stack<int>();
    stack->push_back(1);
    stack->push_back(2);
    stack->push_back(3);
    stack->push_back(4);
    stack->push_back(5);
    stack->push_back(6);
    cout << "BACK: " << stack->back() << endl;
    stack->pop_back();

    stack->push_back(7);
    stack->print();

    return 0;
}