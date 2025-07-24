#include "SwordCard.h"
#include "Game.h"
#include "Player.h"
#include <iostream>

// SwordCard Constructor
SwordCard::SwordCard(int point)
    : Card(CardType::Sword, point) {
}

// Returns a string representation of HookCard
std::string SwordCard::str() const {
    return "Sword(" + std::to_string(getPoint()) + ")";
}

// Executes special ability of Sword Card
void SwordCard::applyEffect(Game& game, Player& player) {
    Player* opponent = game.getOpponent(&player);
    auto& opponentBank = opponent->getBank();

    if (opponentBank.empty()) {
        std::cout << " No cards in other player's Bank. Play continues.\n";
        return;
    }

    // Shows all the card of opponent's bank to steal
    std::cout << "  Steal the top card of any suit from the other player's Bank into your Play Area:\n";
    for (int i = 0; i < opponentBank.size(); ++i) {
        std::cout << "  (" << i + 1 << ") " << opponentBank[i]->str() << "\n";
    }

    // Get players' choice
    std::cout << "  Which card do you pick? ";
    int cardChoosen;
    std::cin >> cardChoosen;

    if (cardChoosen < 1 || cardChoosen > opponentBank.size()) {
        std::cout << "  Invalid choice. Sword effect skipped.\n";
        return;
    }

    Card* selectedCardFromOpponentBank = opponentBank[cardChoosen - 1];

    opponentBank.erase(opponentBank.begin() + (cardChoosen - 1));

    std::cout << "  " << player.getName() << " draws a " << selectedCardFromOpponentBank->str() << "\n";
    player.playCard(selectedCardFromOpponentBank, game);
}
