#ifndef CARD
#define CARD
class Card
{
  public:
    enum Rank
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
      RANK_J,
      RANK_Q,
      RANK_K,
      RANK_A
    };

    enum Suit
    {
      SUIT_CLUBS,
      SUIT_DIAMONDS,
      SUIT_HEARTS,
      SUIT_SPADES
    }; 
    
  private:
    Rank m_rank;
    Suit m_suit;
  
  public:
    Card(Rank rank = RANK_2, Suit suit = SUIT_CLUBS) : m_rank(rank), m_suit(suit) {}
    
    void printCard() const;
    
    int getCardValue() const;
    
    Rank getRank();
};

#endif


