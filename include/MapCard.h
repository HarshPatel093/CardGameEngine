#pragma once
#ifndef MapCard_h
#define MapCard_h

#include "Card.h"

// MapCard that inherits Card Class
class MapCard : public Card {

public:

    // Constructor with point value
    MapCard(int point);

    // Method to print string
    std::string str() const override;

    // Applies the special effect of MapCard
    void applyEffect(Game& game, Player& player) override;
};

#endif // !MapCard_h
