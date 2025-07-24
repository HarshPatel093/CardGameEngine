#include "KeyCard.h"
#include "Game.h"
#include "Player.h"
#include <iostream>

// KeyCard Constructor
KeyCard::KeyCard(int point)
    : Card(CardType::Key, point) {
}

// Returns a string representation of KeyCard
std::string KeyCard::str() const {
    return "Key(" + std::to_string(getPoint()) + ")";
}

// Special effect when drawn Key card
void KeyCard::applyEffect(Game&, Player&) {
    std::cout << "  No immediate effect. If banked with a chest, draw as many bonus cards from the Discard pile as you moved into your Bank.\n";
}

// Triggers when Key is banked
void KeyCard::onBanking(Game&, Player&) {
}