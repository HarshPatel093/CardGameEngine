#pragma once
#ifndef KrakenCard_h
#define KrakenCard_h

#include "Card.h"

// KrakenCard that inherits from Card Class
class KrakenCard : public Card {
public:

    // Constructor with point value
    KrakenCard(int point);

    // Method to print string
    std::string str() const override;

    // Applies the special effect of KrakenCard
    void applyEffect(Game& game, Player& player) override;
};

#endif // !KrakenCard_h
