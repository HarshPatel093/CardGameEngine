#pragma once
#ifndef card_h
#define card_h

#include <string>

class Game;
class Player;

// Enum to represent all card types
enum class CardType {
    Cannon, Chest, Key, Hook, Oracle, Sword, Mermaid, Kraken, Map
};

// Abstract base class  
class Card {
protected:
    CardType type;
    int point;

public:

    // Constructor to initialize a card with its type and point
    Card(CardType type, int point);

    // Virtual deconstructor
    virtual ~Card() = default;

    // Getter for card type
    CardType getType() const;

    // Getter for card point
    int getPoint() const;

    // virtual method to print string
    virtual std::string str() const = 0;

    // virtual method to implement cards' special effect
    virtual void applyEffect(Game& game, Player& player) = 0;

    // virtual method that defines card behaviour when banked
    virtual void onBanking(Game& game, Player& player);
};

#endif // ! card_h