#pragma once
#ifndef KeyCard_h
#define KeyCard_h

#include "Card.h"

// KeyCard that inherits from Card Class
class KeyCard : public Card {
public:

    // Constructor with point value
    KeyCard(int point);

    // Applies the special effect of KeyCard
    void applyEffect(Game& game, Player& player) override;

    // Method to print string
    std::string str() const override;

    //Method to show cards' behaviour when banked
    void onBanking(Game& game, Player& player) override;
};

#endif // !KeyCard_h
