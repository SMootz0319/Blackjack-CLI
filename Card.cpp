#include <iostream>
#include "Card.h"
using namespace std;
    
void Card::printCard() const
{
  char cardCode[2]; // the code for this card
      
  // get card rank
  switch (m_rank)
  {
    case RANK_2: cardCode[0] = '2'; break;
    case RANK_3: cardCode[0] = '3'; break;
    case RANK_4: cardCode[0] = '4'; break;
    case RANK_5: cardCode[0] = '5'; break;
    case RANK_6: cardCode[0] = '6'; break;
    case RANK_7: cardCode[0] = '7'; break;
    case RANK_8: cardCode[0] = '8'; break;
    case RANK_9: cardCode[0] = '9'; break;
    case RANK_10:cardCode[0] = 'T'; break;
    case RANK_J: cardCode[0] = 'J'; break;
    case RANK_Q: cardCode[0] = 'Q'; break;
    case RANK_K: cardCode[0] = 'K'; break;
    case RANK_A: cardCode[0] = 'A'; break;
    default:     cardCode[0] = 'X'; break;
  }
  
  // get card suit
  switch(m_suit)
  {
    case SUIT_CLUBS:    cardCode[1] = 'C'; break;
    case SUIT_DIAMONDS: cardCode[1] = 'D'; break;
    case SUIT_HEARTS:   cardCode[1] = 'H'; break;
    case SUIT_SPADES:   cardCode[1] = 'S'; break;
    default:            cardCode[1] = 'X'; break;
  }
  
  
  // print cardCode
  cout << cardCode[0];
  cout << cardCode[1];    
}

int Card::getCardValue() const
{
  switch (m_rank)
  {
    case RANK_2:  return 2;
    case RANK_3:  return 3;
    case RANK_4:  return 4;
    case RANK_5:  return 5;
    case RANK_6:  return 6;
    case RANK_7:  return 7;
    case RANK_8:  return 8;
    case RANK_9:  return 9;
    case RANK_10:
    case RANK_J:
    case RANK_Q:
    case RANK_K:  return 10;
    case RANK_A:  return 11;
    
  }
}

Card::Rank Card::getRank() { return m_rank; }

