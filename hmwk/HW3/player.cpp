#include "player.h"
#include <vector>       // vector
#include <ctime>        // time
#include <algorithm>    // random_shuffle
#include <cstdlib>      // rand, srand

Player::Player()
{
    initDeck();
}

void Player::initDeck()    // creates a new shuffeled deck for the player per game
{
    if (deck != nullptr)
        delete deck;

    deck = new Deck();
    std::vector<int> tmp;
    std::srand (unsigned(std::time(0)));

    for (int i = 1; i <= 13; i++)
        for (int j = 0; j < 4; j++)
            tmp.push_back(i);

    std::random_shuffle(tmp.begin(), tmp.end());

    for (int i = 0; i < 52; i++)
    {
        deck->enqueue(tmp.at(i));
    }
}

int Player::draw()
{
    return deck->dequeue();
}

void Player::bury()
{
    deck->enqueue(hand[0]);
}

void Player::saveCard()
{
    side->push(hand[1]);
}

int Player::deckSum()         // Sums all the ints returned from dequeue
{                                           // Iterates for as many cards that are in the deck
    int dSum = 0;
    for (int i = 0; i < deck->size(); i++)
    {
        dSum += deck->dequeue();    
    }
    return dSum;
}

void Player::peekHand()             // Displays hand unless there is no card there
{                                       // May have to edit above code to set pushed hand members to nullptr
    std::cout << "Your hand: " << endl;
    for (int i = 0; i < 3; i++)
    {
        if (hand[i] != nullptr)
        {
            std::cout << &hand[i] << " ";   
        }
    }
    std::cout << endl;
}

bool Player::hasCards()  
{
    return side->size() == 0 || deck->size() == 1;
}
