#include "HookCard.h"
#include <iostream>
#include "Game.h"
#include "Player.h"
#include <map>

// Hook Constructor 
HookCard::HookCard(int point)
    : Card(CardType::Hook, point) {
}

// Returns a string representation of HookCard
std::string HookCard::str() const {
    return "Hook(" + std::to_string(getPoint()) + ")";
}

// Special effect when drawn Hook card
void HookCard::applyEffect(Game& game, Player& player) {
    if (player.getBank().empty()) {
        std::cout << "  No cards in your Bank. Play continues.\n";
        return;
    }
    // Store the highest point card in each suit
    std::map<CardType, Card*> highestPointCardInEachSuit;

    for (Card* card : player.getBank()) {
        CardType type = card->getType();
        if (!highestPointCardInEachSuit.count(type) || card->getPoint() > highestPointCardInEachSuit[type]->getPoint()) {
            highestPointCardInEachSuit[type] = card;
        }
    }

    std::vector<Card*> choices;
    for (const auto& entry : highestPointCardInEachSuit) {
        choices.push_back(entry.second);
    }
    // Shows the player all the highest value card from his own bank
    std::cout << "  Select a highest-value card from any of the suits in your Bank:\n";
    for (int i = 0; i < choices.size(); ++i) {
        std::cout << "  (" << i + 1 << ") " << choices[i]->str() << "\n";
    }
    
    // Get players' choice
    std::cout << "  Which card do you pick? ";
    int selectedCard;
    std::cin >> selectedCard;

    if (selectedCard < 1 || selectedCard > choices.size()) {
        std::cout << "  Invalid choice. Hook effect skipped.\n";
        return;
    }

    Card* selected = choices[selectedCard - 1];

    auto& bank = player.getBank();
    auto it = std::find(bank.begin(), bank.end(), selected);
    if (it != bank.end()) {
        bank.erase(it);
    }

    player.playCard(selected, game);
}
