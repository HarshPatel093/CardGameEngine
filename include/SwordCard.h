#pragma once
#ifndef SwordCard_h
#define SwordCard_h

#include "Card.h"

// SwordCard inherits from Card Class
class SwordCard : public Card {

public:

    // Constructor with point value
    SwordCard(int point);

    // Method that prints string
    std::string str() const override;
  
    // Applies the special effect of SwordCard
    void applyEffect(Game& game, Player& player) override;
};

#endif // !SwordCard_h
