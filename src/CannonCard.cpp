#include "CannonCard.h"
#include "Game.h"
#include "Player.h"
#include <iostream>
#include <map>

// Constructor for CannonCard
CannonCard::CannonCard(int point)
    : Card(CardType::Cannon, point) {
}

// Returns the string representation of the Cannon card
std::string CannonCard::str() const {
    return "Cannon(" + std::to_string(getPoint()) + ")";
}

// Applies the ability of Cannon Card
void CannonCard::applyEffect(Game& game, Player& player) {
    Player* opponent = game.getOpponent(&player);
    auto& opponentBank = opponent->getBank();

    // if opponents' bank is empty there's nothing to shoot
    if (opponentBank.empty()) {
        std::cout << "  No cards in opponent's Bank. Play continues.\n";
        return;
    }

    // Store the highest point card in each suit
    std::map<CardType, Card*> highesPointCardInEachSuit;

    for (Card* card : opponentBank) {
        CardType type = card->getType();
        if (!highesPointCardInEachSuit.count(type) || card->getPoint() > highesPointCardInEachSuit[type]->getPoint()) {
            highesPointCardInEachSuit[type] = card;
        }
    }

    std::vector<Card*> CardChoices;
    for (auto& pair : highesPointCardInEachSuit) {
        CardChoices.push_back(pair.second);
    }

    // Shows the player selected cards from opponents' bank
    std::cout << "   Shoot the top card of any suit from the other player's Bank into the Discard Pile:\n";
    for (int i = 0; i < CardChoices.size(); ++i) {
        std::cout << "  (" << i + 1 << ") " << CardChoices[i]->str() << "\n";
    }

    // Get players' choice
    std::cout << "  Which card do you pick? ";
    int choice;
    std::cin >> choice;

    if (choice < 1 || choice > CardChoices.size()) {
        std::cout << "  Invalid choice. Cannon effect skipped.\n";
        return;
    }

    // Remove selected card from opponent's bank and move it to discard pile
    Card* selectedCard = CardChoices[choice - 1];
    auto& bank = opponent->getBank();
    auto it = std::find(bank.begin(), bank.end(), selectedCard);
    if (it != bank.end()) {
        bank.erase(it);
    }

    game.putInDiscardPile(selectedCard);
    std::cout << "  " << player.getName() << " You shoot the  " << selectedCard->str() << " out of the other player's Bank.\n";
}