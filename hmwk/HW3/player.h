#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "sidePile.h"
#include "deck.h"

class Player
{
    private:
        std::vector<int> *hand = new std::vector<int>();
        SidePile *side = new SidePile();
        Deck *deck;

    public:
        //Deck *deck;
        Player();
        void                initDeck();        // initializes first deck
        int                 deckSum();         // DONE: sums the value of the cards in deck for winner
        void                draw();            // DONE: player draws from top of deck puts card in hand
        void                bury();            // DONE: buries card at bottom of deck (note: will always bury entire hand)
        void                peekHand();        // DONE: Prints current hand for player
        void                pushToSide();      // DONE: Places card from hand on top of side pile (note: will only save the card at hand[1])
        void                getFromPile();     // DONE: Moves card from top of side pile back to hand
        bool                hasCards();        // DONE: Checks to see if the player has any cards left in their deck and or pile
        int                 handPos();         // DONE: Finds open spot players hand
        std::vector<int>    getHand();
        void                addToHand(std::vector<int> *tmp);       // TODO: Takes cards from other player and puts in hand
};
#endif
