#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

enum CardSuit
{
    SUIT_CLUB,
    SUIT_DIAMOND,
    SUIT_HEART,
    SUIT_SPADE,
    MAX_SUITS
};

enum CardRank
{
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8,
    RANK_9,
    RANK_10,
    RANK_JACK,
    RANK_QUEEN,
    RANK_KING,
    RANK_ACE,
    MAX_RANKS
};

struct Card
{
    CardSuit suit;
    CardRank rank;
};

void swapCard(Card &a, Card &b)
{
    Card temp(a);
    a = b;
    b = temp;
}

int getRandomNumber(int min, int max)
{
    // static used for efficiency, so we only calculate this value once
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // evenly distribute the random number across our range
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void shuffleDeck(std::array<Card, 52> &deck)
{
    for (size_t i = 0; i < deck.size(); i++) {
        int swapIndex = getRandomNumber(0, 51);
        swapCard(deck[i], deck[swapIndex]);
    }
}

void printCard(const Card &card)
{
    switch (card.rank) {
        case RANK_2:
            std::cout << "2";
            break;
        case RANK_3:
            std::cout << "3";
            break;
        case RANK_4:
            std::cout << "4";
            break;
        case RANK_5:
            std::cout << "5";
            break;
        case RANK_6:
            std::cout << "6";
            break;
        case RANK_7:
            std::cout << "7";
            break;
        case RANK_8:
            std::cout << "8";
            break;
        case RANK_9:
            std::cout << "9";
            break;
        case RANK_10:
            std::cout << "2";
            break;
        case RANK_JACK:
            std::cout << "J";
            break;
        case RANK_QUEEN:
            std::cout << "Q";
            break;
        case RANK_KING:
            std::cout << "K";
            break;
        case RANK_ACE:
            std::cout << "A";
            break;
        default:
            std::cout << "printCard(): Unhandled card rank.\n";
            break;
    }
    switch (card.suit) {
        case SUIT_CLUB:
            std::cout << "C";
            break;
        case SUIT_DIAMOND:
            std::cout << "D";
            break;
        case SUIT_HEART:
            std::cout << "H";
            break;
        case SUIT_SPADE:
            std::cout << "S";
            break;
        default:
            std::cout << "printCard(): Unhandled card suit.\n";
            break;
    }
}

void printDeck(const std::array<Card, 52> &deck)
{
    for (const auto &card : deck)
    {
        printCard(card);
        std::cout << " ";
    }

    std::cout << "\n";
}

int getCardValue(Card card)
{
    switch (card.rank)
    {
        case RANK_2:    return 2;
        case RANK_3:    return 3;
        case RANK_4:    return 4;
        case RANK_5:    return 5;
        case RANK_6:    return 6;
        case RANK_7:    return 7;
        case RANK_8:    return 8;
        case RANK_9:    return 9;

        case RANK_10:
        case RANK_JACK:
        case RANK_QUEEN:
        case RANK_KING: return 10;

        case RANK_ACE:  return 11;

        default:
            std::cout << "getCardValue(): Unhandled card rank.\n";
            return -1;
    }
}

char getPlayerChoice()
{
    std::cout << "(h) to hit / (s) to stand: ";

    char choice;
    do {
        std::cin >> choice;
    } while(choice != 'h' && choice != 's');

    std::cout << "\n";

    return choice;
}

bool playBlackJack(std::array<Card, 52> &deck)
{
    // Pointer tracking the next card to be dealt
    const Card *cardPtr(&deck[0]);

    int pScore = 0; // Player score
    int dScore = 0; // Dealer score

    // The dealer gets the first card
    dScore += getCardValue(*cardPtr++);
    std::cout << "The dealer is showing: " << dScore << "\n\n";

    // The player gets the two next cards
    pScore += getCardValue(*cardPtr++);
    pScore += getCardValue(*cardPtr++);

    // Player's turn
    while (1)
    {
        std::cout << "Your current total is: " << pScore << ".";

        if (pScore > 21)
            return false;

        std::cout << " What will you do?\n\n";

        if (getPlayerChoice() == 's')
            break;

        pScore += getCardValue(*cardPtr++);
    }

    // Dealer's turn
    do {
        dScore += getCardValue(*cardPtr++);
        std::cout << "The dealer is showing: " << dScore << "\n";
    } while(dScore<17);

    if (dScore > 21 || pScore > dScore)
        return true;

    return false;
}

int main(int argc, char const *argv[]) {

    srand(static_cast<unsigned int>(time(0)));

    std::array<Card, 52> deck;

    int card = 0;
    for (size_t suit = 0; suit < MAX_SUITS; suit++) {
        for (size_t rank = 0; rank < MAX_RANKS; rank++) {
            deck[card].suit = static_cast<CardSuit>(suit);
            deck[card].rank = static_cast<CardRank>(rank);
            ++card;
        }
    }

    shuffleDeck(deck);

    if (playBlackJack(deck))
        std::cout << "\nYou win!\n";
    else
        std::cout << "\nYou lose...\n";

    return 0;
}
