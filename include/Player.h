#pragma once
#ifndef  player_h
#define player_h

#include <string>
#include <vector>
#include "Card.h"

typedef std::vector<Card*> cardCollection;

class Game;
class Card;

// Player class
class Player {
private:
    std::string name;
    cardCollection playArea;
    cardCollection bank;

public:

    // Constructor 
    Player();

    // Constructor with name initialization
    Player(const std::string& name);

    // Adds a drawn card to play area and use its ability
    bool playCard(Card* card, Game& game);

    // Checks if players' card is busted or not
    bool isBusted();

    // Adds Cards to the bank
    void addCardsToBank(Game& game);

    // Shows drawn cards from the deck
    void showDrawnCards();

    // Shows all the banked cards
    void showBankedCards();

    // Calculates players' score
    int calculateScore();

    // getter to get players' name
    std::string getName() const;

    // Moves all card to discard pile from play area
    void emptyPlayAreaToDiscardPile(Game& game);

    // Getter to show card players' card from the bank
    cardCollection& getBank();

    // Getter to show play area
    cardCollection& getPlayArea();
};

#endif // ! player_h
