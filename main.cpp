#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Card.h"
#include "Deck.h"

using namespace std;

bool playBlackJack(Deck deck)
{
  //Card *cardPointer = &cardDeck[0];
  
  // deal dealer's first card
  int dealersScore = deck.dealCard().getCardValue();
  cout << "Dealers card value: " << dealersScore << '\n' << '\n';
  
  // deal player's two cards
  int playersScore = deck.dealCard().getCardValue();
  playersScore += deck.dealCard().getCardValue();
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
      Card card = deck.dealCard();
      if (card.getRank() == Card::RANK_A && playersScore > 10)
      {
        ++playersScore;
      }
      else
      {
        playersScore += card.getCardValue();
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
    Card card = deck.dealCard();
    if (card.getRank() == Card::RANK_A && dealersScore > 10)
    {
      ++dealersScore;
    }
    else
    {
      dealersScore += card.getCardValue();
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
  /*
  const Card cardQueenHearts(Card::RANK_Q, Card::SUIT_HEARTS);
  cardQueenHearts.printCard();
  
  cout << " has the value " << cardQueenHearts.getCardValue() << '\n';


  

  //deck.printDeck();
  deck.shuffle();
  deck.printDeck();
  
  cout << "The first card has value: " << deck.dealCard().getCardValue() << '\n';
  cout << "The second card has value: " << deck.dealCard().getCardValue() << '\n';
  */

  srand(static_cast<unsigned int>(time(0)));
  Deck deck;
  
  char playAgain = 'y';
  while (playAgain == 'y')
  {
    // shuffle the deck
    cout << "Shuffling...\n";

    deck.shuffle();

    // play game
    bool gameResult = playBlackJack(deck);
    

    cout << "\nWould you like to play again? (y/n)";
    cin >> playAgain;
  }
  
  return 0;
}


































