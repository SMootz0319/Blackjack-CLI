#include <iostream>
#include <array>
#include <ctime>

using namespace std;

int getRandomNumber(int min, int max);

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

struct Card
{
  Rank rank;
  Suit suit;
};

void printCard(const Card card)
{
  char cardCode[2]; // the code for this card
  
  // get card rank
  switch (card.rank)
  {
    case RANK_2:
      cardCode[0] = '2';
      break;
    case RANK_3:
      cardCode[0] = '3';
      break;
    case RANK_4:
      cardCode[0] = '4';
      break;
    case RANK_5:
      cardCode[0] = '5';
      break;
    case RANK_6:
      cardCode[0] = '6';
      break;
    case RANK_7:
      cardCode[0] = '7';
      break;
    case RANK_8:
      cardCode[0] = '8';
      break;
    case RANK_9:
      cardCode[0] = '9';
      break;
    case RANK_10:
      cardCode[0] = 'T';
      break;
    case RANK_J:
      cardCode[0] = 'J';
      break;
    case RANK_Q:
      cardCode[0] = 'Q';
      break;
    case RANK_K:
      cardCode[0] = 'K';
      break;
    case RANK_A:
      cardCode[0] = 'A';
      break;
    default:
      cardCode[0] = 'X';
      break;
  }
  
  // get card suit
  switch(card.suit)
  {
    case SUIT_CLUBS:
      cardCode[1] = 'C';
      break;
    case SUIT_DIAMONDS:
      cardCode[1] = 'D';
      break;
    case SUIT_HEARTS:
      cardCode[1] = 'H';
      break;
    case SUIT_SPADES:
      cardCode[1] = 'S';
      break;
    default:
      cardCode[1] = 'X';
      break;
  }
  
  
  // print cardCode
  cout << cardCode[0];
  cout << cardCode[1];
  //cout << '\n';
  
  
}

// print each card in the deck
void printDeck(const array<Card, 52> &cardDeck)
{
  int spaceCounter = 0;
  for (const auto card : cardDeck)
  {
    printCard(card);
    cout << ' ';
    ++spaceCounter;
    
    if (spaceCounter == 13)
    {
      cout << '\n';
      spaceCounter = 0;
    }
  }
}

void swapCard(Card &card1, Card &card2)
{
  Card _card1 = card1;
  
  card1 = card2;
  card2 = _card1;
  
}

void shuffleDeck(array<Card, 52> &cardDeck)
{
  for (int i = 0; i < 52; ++i)
  {
    swapCard(cardDeck[i], cardDeck[getRandomNumber(0,51)]);
  }
}

int getCardValue(Card card)
{
  switch (card.rank)
  {
    case RANK_2:
      return 2;
    case RANK_3:
      return 3;
    case RANK_4:
      return 4;
    case RANK_5:
      return 5;
    case RANK_6:
      return 6;
    case RANK_7:
      return 7;
    case RANK_8:
      return 8;
    case RANK_9:
      return 9;
    case RANK_10:
    case RANK_J:
    case RANK_Q:
    case RANK_K:
      return 10;
    case RANK_A:
      return 11;
    
  }
}

bool playBlackJack(array<Card, 52> &cardDeck)
{
  Card *cardPointer = &cardDeck[0];
  
  // deal dealer's first card
  int dealersScore = getCardValue(*cardPointer++);
  cout << "Dealers card value: " << dealersScore << '\n' << '\n';
  
  // deal player's two cards
  int playersScore = getCardValue(*cardPointer++);
  playersScore += getCardValue(*cardPointer++);
  cout << "Value of your first two cards: " << playersScore << '\n';
  
  // Run player's turn
  char playerMove = 'h';
  while (playerMove == 'h')
  {
    cout << "Would you like to hit or stand (h/s)?";
    cin >> playerMove;
    
    if (playerMove == 's')
    {
      cout << "Your final score: " << playersScore << '\n';
      break;
    }
    else
    {
      // If the next card in an A, increment the deck and add one to score
      if (cardPointer->rank == RANK_A && playersScore > 10)
      {
        ++cardPointer;
        ++playersScore;
      }
      else
      {
        playersScore += getCardValue(*cardPointer++);
      }
      
      cout << "Your new score: " << playersScore << '\n';
      if (playersScore > 21)
      {
        cout << "You've bust!\n";
        cout << "You've Lost\n";
        return false;;
        break;
      }
    }
  }
  
  // run dealers turn
  while (dealersScore < 17)
  {
  
    if (cardPointer->rank == RANK_A && dealersScore > 10)
    {
      ++cardPointer;
      ++dealersScore;
    }
    else
    {
      dealersScore += getCardValue(*cardPointer++);
    }
    
    cout << "Dealers new score: " << dealersScore << '\n';    
    if (dealersScore > 21)
    {
      cout << "Dealer busts!\n";
      cout << "You've Won!\n";
      return true;
    }
  }
  
  cout << "Dealer stands.\n";
  
  cout << "Player Score:\t" << playersScore << '\n';
  cout << "Dealer's Score:\t" << dealersScore << '\n';
  
  if (playersScore == dealersScore)
  {
    cout << "Push!";
    return true;
  }
  else if (playersScore > dealersScore)
  {
    cout << "You've Won!";
    return true;
  }
  else
  {
    cout << "You've lost.";
    return false;
  }
    
}

int main()
{
  srand(static_cast<unsigned int>(time(0)));
 
  // create a deck of cards
  array <Card, 52> cardDeck;

  int suitIndex = 0;
  int rankIndex = 0;
  for (int i = 0; i < 52; ++i)
  {
    if ( i % 13 == 0 )
    {
      ++suitIndex;
      rankIndex = 0;
    }
    
    cardDeck[i] = {static_cast<Rank>(rankIndex), static_cast<Suit>(suitIndex - 1)};
    
    ++rankIndex;
  }
  
  
  char playAgain = 'y';
  while (playAgain == 'y')
  {
    // shuffle the deck
    cout << "Shuffling...\n";

    shuffleDeck(cardDeck);

    // play game
    bool gameResult = playBlackJack(cardDeck);
    

    cout << "\nWould you like to play again? (y/n)";
    cin >> playAgain;
  }
  
  return 0;
}

































