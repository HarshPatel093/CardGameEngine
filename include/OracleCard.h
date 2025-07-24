#pragma once
#ifndef OracleCard_h
#define OracleCard_h

#include "Card.h"

// OracleCard that inhertis from Card Class
class OracleCard : public Card {
public:

    // Constructor with point value
    OracleCard(int point);

    // Method that print string
    std::string str() const override;

    // Applies the special effect of OracleCard
    void applyEffect(Game& game, Player& player) override;
};

#endif // !OracleCard_h
