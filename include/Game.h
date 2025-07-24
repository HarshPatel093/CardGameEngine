#pragma once
#ifndef game_h
#define game_h

#include <vector>
#include "Card.h"
#include "Player.h"

typedef std::vector<Card*> CardCollection;

// Game class manages the overall game logic
class Game {
private:
    CardCollection deck;
    CardCollection discardedCards;
    Player players[2];
    int currentTurnPlayer;
    int roundNumber;
    int turnNumber;

public:

    // Constructor
    Game();

    // Starts the game
    void startGame();

    // Changes the turn
    void nextTurn();

    // Draw card from the deck
    Card* drawCard();

    // Shuffles the card
    void shuffleCard(CardCollection& cards);

    // Ends the game
    void endGame();

    // Returns a pointer 
    Player* getOpponent(Player* p);

    // Returns a pointer of current player
    Player* getCurrentTurnPlayer();

    // Returns a reference to discard pile
    CardCollection& getDiscardPile();

    // Add a card to discard pile
    void putInDiscardPile(Card* card);

    // Removes a card from Discard pile to play area
    void drawOutFromDiscardPile(Card* card);

    // Returns a pointer to the top card of the deck
    Card* peekTopCardFromDeck(); 

};


#endif // !game_h
