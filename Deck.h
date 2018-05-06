#ifndef CARD
#include "Card.h"
#endif

#ifndef DECK
#define DECK
#include <array>
#include <cassert>

using namespace std;

class Deck
{
  private:
    array<Card, 52> m_deck;
    
    int m_cardIndex = 0;
    
    void swapCard(Card &card1, Card &card2)
    {
      Card _card1 = card1;
      
      card1 = card2;
      card2 = _card1;
    }
  
  public:
    Deck();
    
    // print each card in the deck
    void printDeck() const;
    
    void shuffle();
    
    const Card& dealCard();
};
#endif
