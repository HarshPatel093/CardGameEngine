#include "MermaidCard.h"
#include "Game.h"
#include "Player.h"
#include <iostream>

// MermaidCard Constructor
MermaidCard::MermaidCard(int point)
    : Card(CardType::Mermaid, point) {
}

// Returns a string representation of MermaidCard
std::string MermaidCard::str() const {
    return "Mermaid(" + std::to_string(getPoint()) + ")";
}

// Method for executing mermaid cards' ability
void MermaidCard::applyEffect(Game&, Player&) {
    std::cout << "  No effect but Mermaids are worth more.\n";
}
