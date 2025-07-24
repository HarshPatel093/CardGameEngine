#include "ChestCard.h"
#include "Game.h"
#include "Player.h"
#include "Card.h"
#include <iostream>

// Chest Constructor
ChestCard::ChestCard(int point)
    : Card(CardType::Chest, point) {
}

// Returns a string representation of chest class
std::string ChestCard::str() const {
    return "Chest(" + std::to_string(getPoint()) + ")";
}

// Special effect when drawn chest card
void ChestCard::applyEffect(Game& game, Player& player) {
    std::cout << "  No immediate effect. If banked with a key, draw as many bonus cards from the Discard pile as you moved into your Bank.\n";
}

// Trigger when chest is banked
void ChestCard::onBanking(Game& game, Player& player) {
    bool keyPresent = false;

    // Check if a Key card is in the current play area
    for (Card* card : player.getPlayArea()) {
        if (card->getType() == CardType::Key) {
            keyPresent = true;
            break;
        }
    }
    // Check if a Key card is present in the bank
    if (!keyPresent) {
        for (Card* card : player.getBank()) {
            if (card->getType() == CardType::Key) {
                keyPresent = true;
                break;
            }
        }
    }

    if (!keyPresent) {
        return;
    }

    int cardsToDraw = player.getPlayArea().size();

    // Draw card from discard pile
    std::vector<Card*> retrievedCardsFromDiscard;
    for (int i = 0; i < cardsToDraw && !game.getDiscardPile().empty(); ++i) {
        Card* card = game.getDiscardPile().back();
        game.getDiscardPile().pop_back();
        retrievedCardsFromDiscard.push_back(card);
    }

    // Shows which are selected and add them to the bank
    if (!retrievedCardsFromDiscard.empty()) {
        std::cout << "  Chest and Key activated. Added ";
        for (size_t i = 0; i < retrievedCardsFromDiscard.size(); ++i) {
            std::cout << retrievedCardsFromDiscard[i]->str();
            if (i < retrievedCardsFromDiscard.size() - 1)
                std::cout << ", ";
            player.getBank().push_back(retrievedCardsFromDiscard[i]);
        }
        std::cout << " to your bank.\n";
    }
}
