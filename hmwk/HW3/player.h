#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "sidePile.h"
#include "deck.h"

class Player
{
    private:
        std::vector<int> *hand = new std::vector<int>(3);
        SidePile *side = new SidePile();
        Deck *deck;

    public:
        Deck *deck;
        Player();
        void    initDeck();        // initializes first deck
        int     deckSum();         // TODO: sums the value of the cards in deck for winner
        int     draw();            // DONE: player draws from top of deck
        void    bury();            // DONE: buries card at bottom of deck (note: will always bury entire hand)
        void    peekHand();        // Lando::TODO: Prints current hand for player
        void    saveCard();        // DONE: Places card from hand on top of side pile (note: will only save the card at hand[1])
        void    getFromPile();     // TODO: Moves card from top of side pile back to hand
        bool    hasCards();        // TOOD: Checks to see if the player has any cards left in their deck and or pile
};
#endif
