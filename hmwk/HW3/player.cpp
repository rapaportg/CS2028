#include "player.h"

Player::Player(string n)
{
    name = n;
}

Player::setDeck(Deck *tmp)
{
    deck = tmp;
}
