#pragma once
#ifndef MermaidCard_h
#define MermaidCard_h

#include "Card.h"

// MermaidCard that inherits from Card Class
class MermaidCard : public Card {
public:

    // Constructor with point value
    MermaidCard(int point);

    // Method to print string
    std::string str() const override;

    // Applies the special effect of MermaidCard
    void applyEffect(Game& game, Player& player) override;
};

#endif // !MermaidCard_h
