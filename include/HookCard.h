#pragma once
#ifndef HookCard_h
#define HookCard_h

#include "Card.h"

// HookCard inherits from Card class
class HookCard : public Card {
public:

    // Constructor with point value
    HookCard(int point);

    // Method to print string
    std::string str() const override;
    
    // Applies the special effect of the Hookcard
    void applyEffect(Game& game, Player& player) override;
};
#endif // !HookCard_h
