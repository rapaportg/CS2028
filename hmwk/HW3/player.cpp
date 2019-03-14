#include "player.h"
#include <iostream>
#include <vector>       // vector
#include <ctime>        // time
#include <algorithm>    // random_shuffle
#include <cstdlib>      // rand, srand

Player::Player()
{
    initDeck();
}

void Player::initDeck()    // creates a new shuffled deck for the player per game
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
    for (unsigned int i = 0; i < hand->size(); i++)
    {
        deck->enqueue(hand->at(i));
    }
}

void Player::pushToSide()
{
    side->push(hand->back());
    hand->pop_back();
}

int Player::handSum()         // Sums all the ints held in hand
{                                           
    int hSum = 0;
    for (unsigned int i = 0; i < hand->size(); i++)
    {
        hSum += hand->at(i);
    }
    return hSum;
}

void Player::peekHand()             // Displays hand 
{                                       
    std::cout << "\nYour hand: " << std::endl;
    for (unsigned int i = 0; i < hand->size(); i++)
    {
        std::cout << hand->at(i) << " | ";
    }
}

void Player::peekSidePile()
{
    std::cout << "\nSide Pile:" << std::endl;
    for (unsigned int i = 0; i < side->size(); i++)
    {
		std::cout << side->look(i) << " | " << std::endl;
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
    for (unsigned int i = 0; i < tmp->size(); i++)
    {
        hand->emplace_back(tmp->at(i));
    }
}

std::vector<int> *Player::getHand()		// returns pointer to player hand
{
    std::vector<int> *tmp = hand;
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

int Player::cardsLeftInDeck()
{
    return deck->size();
}
