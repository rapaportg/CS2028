#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "sidePile.h"
#include "deck.h"

class Player
{
    private:
        std::string name;
        std::vector<int> *hand = new std::vector<int>(3);
        SidePile *side = new SidePile();
        Deck *deck;

    public:
        Player(std::string);
        void    initDeck();        // initializes first deck
        int     deckSum();         // TODO
        int     draw();            // TODO: player draws from top of deck
        void    bury();            // TODO: buries card at bottom of deck
        void    peekHand();        // Lando::TODO: Prints current hand for playervoid Deck::enqueue(int card) // insert front of link list
        void    saveCard();        // TODO: Places card from hand on top of side pile
        void    getFromPile();     // TODO: Moves card from top of side pile back to hand
};
#endif
