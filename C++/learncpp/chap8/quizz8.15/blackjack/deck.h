#ifndef DECK_H
#define DECK_H

#include <array>
#include "card.h"

class Deck
{
private:
    std::array<Card, 52> m_deck;
    int m_cardIndex = 0;

public:
    Deck();
    void printDeck() const;
    void shuffleDeck();
    const Card& dealCard();

private:
    static void swapCard(Card&, Card&);
    static int getRandomNumber(int min, int max);
};

#endif
