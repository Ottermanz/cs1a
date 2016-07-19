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

int main () {

  // variables
  int card = 0; // card value
  int comb = 0; // combination (comb is added with comb += card)
  double quit = 0.0; 
  char ace; // determines what number they want their ace to be if they get a value of 1
  char choice; // choice of either y (Yes) or n (No)

  // Header/Introduction
  cout << "*************************** \n";
  cout << "** Welcome to Blackjack! ** \n";
  cout << "*************************** \n" << endl;
  
  // first card randomization

  card = rand()%13+1;
  comb = card; 

  // first input  

  cout << "Your first card is: " << card << endl << endl;

  cout << "Do you want another card? \n";
  cout << "Type y for Yes, n for No: ";
  cin.get(choice);
  
  if (choice == 'n') // if they chose no...
  { 
    cout << "\n You decided to hold your cards"; 
  }

  if (choice == 'y') // if they chose yes...
  {
    while (quit != -1) 
    { 

      // random time!
      srand(time(NULL));
      card = rand()%13+1;
      comb += card;
      
      // if statement to determine if they want their ace to count as a 1 or an 11
      if (card == 1)
      { 
        cout << "\n You got an ace! Do you want it to be either a 1 or an 11 (a=1/b=11): ";
        cin.get(ace);

        if (ace == 'a') 
        {
          card = 1; // ace = 1
          comb++; 
        } 

        if (ace == 'b') 
        {
          card = 11; // ace = 11
          comb += 11; 
        }
      } // end of ACE statement
      
      // quit conditionals

      if (comb > 21) // if the total is greater than 21 then exit the loop and game over
      { quit = -1; }
      
      if (choice == 'n') // if they dont want another card, then dont give it to them, hippie. get a job.
      { 
        cout << "You decided to hold your cards \n";
        quit = -1; 
      }


      cout << "\n Your next card is: " << card << endl;
      cout << "Your combined total is: " << comb << endl << endl;
      
      cout << "Do you want another card? \n";
      cout << "Type y for Yes, n for No: ";
      cin.get(choice); 
      
    }
  }    
  
  
  
  if (comb > 21)
  { cout << "\n Sorry... you lose! \n"; }
  
  
  
  
  
  
  return 0;
}
