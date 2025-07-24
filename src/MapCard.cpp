#include "MapCard.h"
#include <iostream>
#include "Game.h"
#include "Player.h"

MapCard::MapCard(int point)
    : Card(CardType::Map, point) {
}

std::string MapCard::str() const {
    return "Map(" + std::to_string(getPoint()) + ")";
}

void MapCard::applyEffect(Game& game, Player& player) {
    if (game.getDiscardPile().empty()) {
        std::cout << "  No cards in the discard. Play continues.\n";
        return;
    }

    std::cout << "  Draw 3 cards from the discard and pick one to add to the play area:\n";

    std::vector<Card*> drawnCardsFromDiscardPile;
    int totalDraw = std::min(3, static_cast<int>(game.getDiscardPile().size()));

    for (int i = 0; i < totalDraw; ++i) {
        Card* card = game.getDiscardPile().back();
        game.getDiscardPile().pop_back();
        drawnCardsFromDiscardPile.push_back(card);
    }

    for (int i = 0; i < drawnCardsFromDiscardPile.size(); ++i) {
        std::cout << "  (" << i + 1 << ") " << drawnCardsFromDiscardPile[i]->str() << "\n";
    }

    std::cout << "  Which card do you pick? ";
    int choice;
    std::cin >> choice;

    if (choice < 1 || choice > drawnCardsFromDiscardPile.size()) {
        std::cout << "  Invalid choice. No card selected.\n";
        for (Card* card : drawnCardsFromDiscardPile) {
            game.putInDiscardPile(card);
        }
        return;
    }

    Card* selectedCard = drawnCardsFromDiscardPile[choice - 1];
    player.playCard(selectedCard, game);

    for (int i = 0; i < drawnCardsFromDiscardPile.size(); ++i) {
        if (i != (choice - 1)) {
            game.putInDiscardPile(drawnCardsFromDiscardPile[i]);
        }
    }
}
