#pragma once
#ifndef CannonCard_h
#define CannonCard_h

#include "Card.h"

// CannonCard inhwrits from Card class
class CannonCard : public Card {
public:

    // CannonCard constructor initialized with a point value
    CannonCard(int point); 

    // returns a string
    std::string str() const override;

    // Applies the special effect of CannonCard
    void applyEffect(Game& game, Player& player) override;
};

#endif // !CannonCard_h