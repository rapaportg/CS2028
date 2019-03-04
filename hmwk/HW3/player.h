#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "sidePile.h"
#include "deck.h"
#include "stack.h"

class Player
{
    private:
        string name;
        Stack<int> *hand = new Stack<int>(3);
        Deck *deck;


    public:
        sidePile *side = new sidePile();

        Player(string);
        void setDeck(Deck tmp);
        int deckSum(); // TODO
        int draw(); // TODO: player draws from top of deck
        void bury(); // TODO: buries card at bottom of deck
        void peekHand(); //TODO: Prints current hand for player




}