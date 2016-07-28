/****************************************************
* hw04.cpp - Program for Blackjack!
*
* author: Lee Evans
* 
* modifications:
* 7/18/16 LE initial version
****************************************************/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
using namespace std;

int aceCard (int x);

int aceCard (int x) {
  char b;
  int y;
  cout << "Your first card is 1\n" << endl;
  cout << "You got an ace. Do you want it to be 1 or 11 [a=1/b=11]: ";
  cin.get(b);
  cin.ignore(1000, '\n');

  if (b == 'a')
  { cout << "\nYou chose 1 \n";
    y = 1;
  }
  
  if (b == 'b')
  { cout << "\nYou chose 11 \n";
    y = 11;
  }

  return (y);
}
  
int main () {
  
  // user variables
  int card = 0; // card value
  int comb = 0; // combination (comb is added with comb += card)
  double quit = 0.0; 

  // dealer variables
  double dQuit = 0.0;
  int dComb = 0;
  int dCard = 0;

  // misc variables
  char ace; // determines what number they want their ace to be if they get a value of 1
  char choice; // choice of either y (Yes) or n (No)
  char fchoice; // first choice
  
  // Header/Introduction
  cout << "*************************** \n";
  cout << "** Welcome to Blackjack! ** \n";
  cout << "*************************** \n" << endl; 
  
  // first card randomization
  srand(time(NULL));
  card = rand()%13+1;
  
  if (card > 10)
  { card = 10; }
  
  if (card == 1) {
  aceCard (card);
  }

  // if (card == 1)
  // { cout << "Your first card is 1\n";
  //  cout << "\nYou got an ace. Do you want it to be 1 or 11 [a=1/b=11]"; 
  //  cin.get(ace);
  //  cin.ignore(1000, '\n');
  //  
  //  if (ace == 'a')
  //  { cout << "You chose 1 \n";
  //    card = 1;
  //  }
  //  if (ace == 'b')
  //  { cout << "You chose 11 \n";
  //    card = 11;
  //  }
  //}
  
  comb += card; 
  
  // first input
  
  cout << "Your first card is: " << card << endl << "\n";
  
  cout << "Do you want another card?\n";
  cout << "Type y for Yes, n for No: ";
  cin.get(fchoice);
  cin.ignore(1000, '\n');
  
  if (fchoice == 'n') // if they chose no...
  { 
    cout << "\n You decided to hold your cards"; 
  }
  
  else if (fchoice == 'y') {
    while (quit != -1) 
    { 
  
      // random time!
      card = rand()%13+1;
            
      if (card > 10)
      { card = 10; }
      
      if (card == 1) {
      aceCard (card);
      }
      
      cout << "\nYour new card is: " << card << endl;
  
  
      comb += card;
      cout << "Your total is: " << comb << endl;
  
      if (comb > 21)
      { quit = -1; }
      
      else if (comb <= 21) {
        cout << "\nDo you want another card? \n";
        cout << "Type y for Yes, n for No: ";
        cin.get(choice);
        cin.ignore(1000, '\n');
  
      if (choice == 'n')
      { quit = -1; }
  
      }
    }
  }
  
  if (comb > 21)
  { cout << "You busted! Dealer wins!\n"; }
  
  if (comb <= 21)
  { cout << "\nYour deck adds up to: " << comb << endl << endl; 
    
    cout << "** Dealer's Turn! **\n" << endl;
    
    // Dealer random card
    dCard = rand()%13+1;
    
    if (dCard > 10)
    { dCard = 10; }
    
    dComb += dCard;

    // Dealer draws a card
    cout << "Dealer draws a card.\n";
    cout << "Dealer's card is: " << dCard << endl;
    cout << "Dealer's value is " << dComb << ", you have " << comb << endl;
    
    // Dealer win condition
    if (dComb >= comb) 
    { cout << "\nDealer wins!"; }
    
    // Dealer is lower than the player
    if (dComb < comb) {
      while (dQuit != -1) {
        
        // Random number generator again
        dCard = rand()%13+1;

        if (dCard > 10)
        { dCard = 10; }
  
        dComb += dCard;
      
        // Dealer draws another card
        cout << "\nDealer draws another card.\n";
        cout << "Dealer's card is: " << dCard << endl;
        cout << "Dealer's value is " << dComb << ", you have " << comb << endl;
      
        // Quit conditions
        if (dComb > 21)
        { 
          cout << "\nDealer busts! You win!\n";
          dQuit = -1;
        }
        
        else if (dComb >= comb && dComb <= 21)
        { 
          cout << "\nDealer wins! You lose!\n";
          dQuit = -1;
        }
        else
        { dQuit = 0; }
      }  
    }
  }
  
  return 0;
  
}
