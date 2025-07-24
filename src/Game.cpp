#include "Game.h"
#include <iostream>
#include "Card.h"
#include "MapCard.h"
#include "HookCard.h"
#include "ChestCard.h"
#include "KeyCard.h"
#include "KrakenCard.h"
#include "OracleCard.h"
#include "MermaidCard.h"
#include "SwordCard.h"
#include "CannonCard.h"
#include <algorithm>
#include <random>     


// Constructor
Game::Game() : currentTurnPlayer(0), roundNumber(1), turnNumber(1) {
    std::string names[] = { "Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue", "Sasha", "Tina", "Marge" };

    // Seed random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    players[0] = Player(names[rand() % 10]);
    int secondName;
    do {
        secondName = rand() % 10;
    } while (names[secondName] == players[0].getName());

    players[1] = Player(names[secondName]);

    // Card types
    std::vector<CardType> suits = {
         CardType::Map, CardType::Cannon, CardType::Chest,
         CardType::Hook, CardType::Key, CardType::Kraken,
         CardType::Mermaid, CardType::Oracle, CardType::Sword
    };

    std::vector<int> points = { 2, 3, 4, 5, 6, 7 };

    for (CardType suit : suits) {
        for (int pt : points) {
            if (suit == CardType::Mermaid && (pt < 4 || pt > 9)) continue;

            Card* card = nullptr;
            switch (suit) {
            case CardType::Map: card = new MapCard(pt); break;
            case CardType::Cannon: card = new CannonCard(pt); break;
            case CardType::Chest: card = new ChestCard(pt); break;
            case CardType::Hook: card = new HookCard(pt); break;
            case CardType::Key: card = new KeyCard(pt); break;
            case CardType::Kraken: card = new KrakenCard(pt); break;
            case CardType::Mermaid: card = new MermaidCard(pt); break;
            case CardType::Oracle: card = new OracleCard(pt); break;
            case CardType::Sword: card = new SwordCard(pt); break;
            default: break; 
            }

            if (card != nullptr) {
                deck.push_back(card);
            }
        }
    }

    // shuffle deck at the beginning after deck creation
    shuffleCard(deck);
}

// Main gameplay method
void Game::startGame() {

    if (deck.empty()) {
        std::cout << "Deck is empty. Game over!\n";
        endGame();
        return;
    }

    roundNumber = (turnNumber + 1) / 2;

    std::cout << "--- Round " << roundNumber << ", Turn " << turnNumber << " ---\n";
    std::cout << getCurrentTurnPlayer()->getName() << "'s turn.\n";
    std::cout << getCurrentTurnPlayer()->getName() << "'s Bank:\n";
    getCurrentTurnPlayer()->showBankedCards();
    std::cout << "| Score: " << getCurrentTurnPlayer()->calculateScore() << "\n";

    while (true) {
        Card* card = drawCard();
        if (card) {
            std::cout << getCurrentTurnPlayer()->getName() << " draws a " << card->str() << "\n";
            bool success = getCurrentTurnPlayer()->playCard(card, *this);

            if (success) {
                std::cout << getCurrentTurnPlayer()->getName() << "'s Play Area:\n";
                getCurrentTurnPlayer()->showDrawnCards();
            }
        }

        // Check for bust
        if (getCurrentTurnPlayer()->isBusted()) {
            std::cout << "BUSTED!\n";
            getCurrentTurnPlayer()->emptyPlayAreaToDiscardPile(*this);
            nextTurn();
            return;
        }

        // Asks if player wants to draw a card again
        std::string choice;
        std::cout << "\nDraw again? (y/n): ";
        std::cin >> choice;

        // if player denies to play, next players' turn
        if (choice != "y" && choice != "Y") {
            getCurrentTurnPlayer()->addCardsToBank(*this);
            std::cout << getCurrentTurnPlayer()->getName() << "'s Bank:\n";
            getCurrentTurnPlayer()->showBankedCards();
            std::cout << "| Score: " << getCurrentTurnPlayer()->calculateScore() << "\n";
            nextTurn();
            break;
        }
    }
}

// Draw a card from the deck
Card* Game::drawCard() {
    if (deck.empty()) return nullptr;

    Card* top = deck.back();
    deck.pop_back();
    return top;
}


// Add a card to discard pile
void Game::putInDiscardPile(Card* card) {
    discardedCards.push_back(card);
}

// Get current player
Player* Game::getCurrentTurnPlayer() {
    return &players[currentTurnPlayer];
}

// Getter for accessing discard pile
CardCollection& Game::getDiscardPile() {
    return discardedCards;
}

// Move to the next players' turn
void Game::nextTurn() {
    currentTurnPlayer = (currentTurnPlayer + 1) % 2;
    turnNumber++;
    startGame();
}

// End game and shows result
void Game::endGame() {
    std::cout << "\nFinal Scores:\n";
    for (int i = 0; i < 2; ++i) {
        std::cout << players[i].getName() << ": " << players[i].calculateScore() << "\n";
    }

    int score0 = players[0].calculateScore();
    int score1 = players[1].calculateScore();

    if (score0 > score1) {
        std::cout << players[0].getName() << " wins!\n";
    }
    else if (score1 > score0) {
        std::cout << players[1].getName() << " wins!\n";
    }
    else {
        std::cout << "It's a tie!\n";
    }
}

//  Peek at the top card in the deck without drawing
Card* Game::peekTopCardFromDeck() {
    if (deck.empty()) return nullptr;
    return deck.back();
}

// Get the opponent player pointer
Player* Game::getOpponent(Player* p) {
    return (&players[0] == p) ? &players[1] : &players[0];
}

// Shuffle the given deck with random pointer
void Game::shuffleCard(CardCollection& cards) {
    CardCollection shuffleDeck{ cards.begin(), cards.end() };
    std::shuffle(shuffleDeck.begin(), shuffleDeck.end(), std::mt19937{ std::random_device{}() });
    std::copy(shuffleDeck.begin(), shuffleDeck.end(), cards.begin());
}

// Removes the selected card from the discard pile to either play area or players' bank
void Game::drawOutFromDiscardPile(Card* card) {
    auto it = std::find(discardedCards.begin(), discardedCards.end(), card);
    if (it != discardedCards.end()) {
        discardedCards.erase(it);
    }
}