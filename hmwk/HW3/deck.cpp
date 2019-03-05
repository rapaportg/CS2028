#include "deck.h"
#include "node.h"

void Deck::enqueue(int card) // insert front of link list
{
        Node *tmp = new Node(card);
        if (head == nullptr)
        {
                head = tmp;
        }
        else
        {
                tmp->next = head;
                head = tmp;
        }
        length++;
}

int Deck::dequeue()  // remove from back of link list
{
        int ret;

        if (length == 0)
        {
                throw EmptyListException(length);
        }
        else
        {
                Node *tmp = head;

                while (tmp->next != nullptr)
                {
                        tmp = tmp->next;
                }
                ret = tmp->getValue();
                delete tmp;
                length--;
        }
        return ret;
}

int Deck::size()
{
        return length + 1;
}