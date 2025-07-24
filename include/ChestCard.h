#pragma once
#ifndef ChestCard_h
#define ChestCard_h

#include "Card.h"

// ChestCard inherits from Card class
class ChestCard : public Card {
public:

    // Constructor intialized with point value when ChestCard is called
    ChestCard(int point);

    // Method to implement ChestCards' special ability
    void applyEffect(Game& game, Player& player) override;

    // Method to print string
    std::string str() const override;

    //Method to show cards' behaviour when banked
    void onBanking(Game& game, Player& player) override;
};

#endif // !ChestCard_h
