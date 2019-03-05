#include "player.h"
#include <vector>       // vector
#include <ctime>        // time
#include <algorithm>    // random_shuffle
#include <cstdlib>      // rand, srand

Player::Player(std::string n)
{
    name = n;
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

    while (!tmp.empty())
    {
        deck->enqueue(tmp.back());
        tmp.pop_back();
    }
}