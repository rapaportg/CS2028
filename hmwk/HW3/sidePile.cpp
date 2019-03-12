#include "sidePile.h"

void SidePile::push(int card)
{
    if (head == 5)
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

int SidePile::size()
{
    return head;
}

int SidePile::getHead()
{
    return head;

}