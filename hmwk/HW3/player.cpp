#include "player.h"
#include <iostream>
#include <vector>       // vector
#include <ctime>        // time
#include <algorithm>    // random_shuffle
#include <cstdlib>      // rand, srand

Player::Player()
{
    initDeck();
    //deck->printDeck();
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

void Player::draw()
{
    hand->push_back(deck->dequeue());
}

void Player::bury()
{
    deck->enqueue(hand->at(0));
}

void Player::pushToSide()
{
    side->push(hand->at(0));
    draw();
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
    std::cout << "Your hand: " << std::endl;
    for (int i = 0; i < hand->size(); i++)
    {
        std::cout << hand->at(i) << " - ";
    }
    std::cout << std::endl;
}

bool Player::hasCards()
{
    return side->size() == 0 || deck->size() == 1;
}

int Player::handPos()
{
    for (int i = 0; i < 6; i++)
    {
        if (hand->at(i) == 0)
            return i;
    }
    return 7;
}

void Player::getFromPile()              // grabs card from pile and puts it in players hand
{
    int pos;
    pos = handPos();
    if (pos == 7)
    {
        std::cout << "your hand is full\n";
        return;
    }
    hand->at(pos) = side->pop();
}

void Player::addToHand(std::vector<int> *tmp)
{
    while (tmp->size() > 0)
    {
        hand->push_back(tmp->back());
        tmp->pop_back();
    }
}

std::vector<int> *Player::getHand()
{
    return hand;
}
