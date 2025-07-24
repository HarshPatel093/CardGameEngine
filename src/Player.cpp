#include "Player.h"
#include "Card.h"
#include "Game.h"
#include <iostream>
#include <set>

// Default Constructor
Player::Player() : name("Unknown") {}

// Constructor with name initialization
Player::Player(const std::string& name) : name(name) {}

// Getter for players' name
std::string Player::getName() const {
    return name;
}

// Calculates and return total score of player
int Player::calculateScore() {
    int point = 0;
    for (Card* card : bank) {
        point += card->getPoint();
    }
    return point;
}

// add a drawn card to the play area and executes its' ability
bool Player::playCard(Card* card, Game& game) {
    playArea.push_back(card);
    card->applyEffect(game, *this);

    if (isBusted()) {
        std::cout << "BUSTED!\n";
        emptyPlayAreaToDiscardPile(game);
        game.nextTurn();  
        return false;      
    }

    return true;
}

// Displays the card in the play area
void Player::showDrawnCards() {
    for (Card* card : playArea) {
        std::cout << card->str() << "\n";
    }
}

// Displays the card in the bank
void Player::showBankedCards() {
    for (Card* card : bank) {
        std::cout << card->str() << "\n";
    }
}

// Checks if the player is busted or not
bool Player::isBusted() {
    std::set<CardType> seen;

    for (Card* card : playArea) {
        CardType type = card->getType();
        if (seen.count(type)) {
            return true;  
        }
        seen.insert(type);
    }

    return false;
}

// Moves all the card from the play area to the discard pile
void Player::emptyPlayAreaToDiscardPile(Game& game) {
    for (Card* card : playArea) {
        game.putInDiscardPile(card);
    }
        playArea.clear();
    }

// Move all the card from the play area to the bank
void Player::addCardsToBank(Game & game) {
     for (Card* card : playArea) {
            card->onBanking(game, *this);  
            bank.push_back(card);          
     }
        playArea.clear();  
}

// Returns reference to banked cards
cardCollection& Player::getBank() {
        return bank;
}

// Returns reference to the play area
cardCollection& Player::getPlayArea() {
    return playArea;
}
