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
        Player();
        void                initDeck();                         // DONE: initializes deck with 52 cards. (4 sets of cards numbered 1 - 13)
        int                 handSum();                          // DONE: sums the value of the cards in hand for winner
        void                draw();                             // DONE: player draws from top of deck puts card in hand
        void                bury();                             // DONE: buries card at bottom of deck (note: will always bury entire hand)
        void                peekHand();                         // DONE: Prints current hand for player
        void                peekSidePile();                     // DONE: prints players side pile
        void                pushToSide();                       // DONE: Places last card from hand on top of side pile
        void                getFromPile();                      // DONE: Moves card from top of side pile back to hand
        bool                hasCards();                         // DONE: Checks to see if the player has any cards left in their deck and or pile
        std::vector<int>    *getHand();                         // DONE: Returns pointer to your hand. (Note does not clear hand)
        void                addToHand(std::vector<int> *tmp);   // DONE: Takes cards from other player and puts in hand
        bool                isSidePileEmpty();                  // DONE: Checks to see if the side pile is empty
        bool                isSidePileFull();                   // DONE: Checks to see if the side pile is full
        void                clearHand();                        // DONE: Clears the hand. (Note: needs to be called at the beginning of every round)
        int                 cardsLeftInDeck();                  // DONE: returns the number of cards left in players deck
};
#endif
