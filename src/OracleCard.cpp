#include "OracleCard.h"
#include "Game.h"
#include "Player.h"
#include <iostream>

// OracleCard Constructor
OracleCard::OracleCard(int point)
    : Card(CardType::Oracle, point) {
}

// Returns a string representation of OracleCard
std::string OracleCard::str() const {
    return "Oracle(" + std::to_string(getPoint()) + ")";
}

// Executes special ability of Oracle card which is peeking a top card of the deck without drawing it
void OracleCard::applyEffect(Game& game, Player& player) {
    Card* nextCardInTheDeck = game.peekTopCardFromDeck();
    if (!nextCardInTheDeck) {
        std::cout << "  No cards left in the deck.\n";
        return;
    }

    std::cout << "  The Oracle sees a " << nextCardInTheDeck->str() << "\n";
}
