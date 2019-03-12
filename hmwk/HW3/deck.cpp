#include "deck.h"
#include "node.h"
#include <iostream>

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
                Node *toDelete = tmp->next;

                while (toDelete->next != nullptr)
                {
                        tmp = toDelete;
                        toDelete = toDelete->next;
                }

                tmp->next = nullptr;
                ret = toDelete->getValue();
                delete toDelete;
                length--;
        }
        return ret;
}

void Deck::printDeck()
{
        Node *tmp = head;
        for (int i = 0; i < length; i++)
        {
                std::cout << tmp->getValue() << " | ";
                tmp = tmp->next;
        }
        std::cout << std::endl;
}

int Deck::size()
{
        return length + 1;

}