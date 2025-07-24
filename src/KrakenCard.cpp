#include "KrakenCard.h"
#include "Game.h"
#include "Player.h"
#include <iostream>

// KrakenCard Constructor
KrakenCard::KrakenCard(int point)
    : Card(CardType::Kraken, point) {
}

// Returns a string representation of KrakenCard
std::string KrakenCard::str() const {
    return "Kraken(" + std::to_string(getPoint()) + ")";
}

// Special effect when Kraken Card is drawn
void KrakenCard::applyEffect(Game& game, Player& player) {

    // 3 Cards are drawn automatically on its' own when Kraken Card is played in the play area
    std::cout << "  Draw 3 cards from the deck and play each:\n";

    for (int i = 0; i < 3; ++i) {
        Card* drawn = game.drawCard();

        if (!drawn) {
            std::cout << "  No more cards in deck.\n";
            break;
        }

        std::cout << "  " << player.getName() << " draws a " << drawn->str() << "\n";

        bool successfullyDrawn = player.playCard(drawn, game);
        if (successfullyDrawn) {
            std::cout << "  " << drawn->str() << " effect executed.\n";
        }

        // Checks if player is busted or not
        if (player.isBusted()) {
            std::cout << "  BUST! " << player.getName() << " loses all cards in play area.\n";
            player.emptyPlayAreaToDiscardPile(game);
            break;
        }
    }
}
