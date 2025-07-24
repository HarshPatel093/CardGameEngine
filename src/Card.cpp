#include "Card.h"

// Card Constructor
Card::Card(CardType type, int point)
    : type(type), point(point) {
}

// Returns the card type
CardType Card::getType() const { return type; }

// Returns the point value of the card
int Card::getPoint() const { return point; }

void Card::onBanking(Game& game, Player& player) {
}
