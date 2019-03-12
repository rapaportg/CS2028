#include "sidePile.h"

void SidePile::push(int card)
{
    if (head > 4)
    {
        throw StackOverFlowException(head);
    }
    else
    {
        pile[head] = card;
        head++;
    }
}

int SidePile::pop()
{
    if (head == -1)
    {
        throw StackUnderFlowException(head);
    }
    else
    {
        head--;
        return pile[head];
    }
}

int SidePile::look(int index)
{
    if (index > 4)
        throw StackOverFlowException(index);
    return pile[index];
}

unsigned int SidePile::size()
{
    return head;
}