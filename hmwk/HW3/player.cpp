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
    for (int i = 0; i < hand->size(); i++)
    {
        deck->enqueue(hand->back());
        hand->pop_back();
    }
}

void Player::pushToSide()
{
    side->push(hand->back());
    hand->pop_back();
    draw();
}

int Player::handSum()         // Sums all the ints returned from dequeue
{                                           // Iterates for as many cards that are in the deck
    int hSum = 0;
    for (int i = 0; i < hand->size(); i++)
    {
        hSum += hand->back();
        hand->pop_back();
    }
    return hSum;
}

void Player::peekHand()             // Displays hand unless there is no card there
{                                       // May have to edit above code to set pushed hand members to nullptr
    std::cout << "\nYour hand: " << std::endl;
    for (int i = 0; i < hand->size(); i++)
    {
        std::cout << hand->at(i) << " | ";
    }
    //std::cout << std::endl;
}

void Player::peekSidePile()
{
    std::cout << "\nSide Pile:" << std::endl;
    for (int i = 0; i < side->size(); i++)
    {
        std::cout << side->look(i) << " | ";
    }
}

bool Player::hasCards()
{
    return side->size() == 0 || deck->size() == 1;
}

void Player::getFromPile()              // grabs card from pile and puts it in players hand
{
    hand->push_back(side->pop());
}

void Player::addToHand(std::vector<int> *tmp)
{
    for (int i = 0; i < tmp->size(); i++)
    {
        hand->emplace_back(tmp->back());
        tmp->pop_back();
    }
}

std::vector<int> *Player::getHand()
{
    std::vector<int> *tmp = hand;
    hand->clear();
    return tmp;
}

bool Player::isSidePileEmpty()
{
    if (side->size() == 0)
        return true;
    return false;
}

bool Player::isSidePileFull()
{
    if(side->size() == 5)
        return true;
    return false;
}

void Player::clearHand()
{
    hand->clear();
}