#include <iostream>
#include "Deck.h"
#include "RandomNumber.h"
#include "Card.h"

 
Deck::Deck()
{
  int suitIndex = 0;
  int rankIndex = 0;
  for (int i = 0; i < 52; ++i)
  {
    if ( i % 13 == 0 )
    {
      ++suitIndex;
      rankIndex = 0;
    }
    
    m_deck[i] = {static_cast<Card::Rank>(rankIndex), static_cast<Card::Suit>(suitIndex - 1)};
    
    ++rankIndex;
  }
}

// print each card in the deck
void Deck::printDeck() const
{
  int spaceCounter = 0;
  for (const auto card : m_deck)
  {
    card.printCard();
    cout << ' ';
    ++spaceCounter;
    
    if (spaceCounter == 13)
    {
      cout << '\n';
      spaceCounter = 0;
    }
  }
  
  cout << '\n';
}

void Deck::shuffle()
{
  for (int i = 0; i < 52; ++i)
  {
    swapCard(m_deck[i], m_deck[getRandomNumber(0,51)]);
  }
  
  m_cardIndex = 0;
}



