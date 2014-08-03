/*
   Triangular Numbers
   Chapter 3
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<iostream>
#include<cassert>

using namespace std;


int TriNumLoop(int term)
{
   int value = 0;

   for(; term > 0; term--)
      {
         value += term;
      }

   return value;
}


int TriNumRecursion(int term)
{
   assert(term >= 1);

   if(term == 1)
      return 1;

   return(TriNumRecursion(term - 1) + term);
}


int main(int args, char **argc)
{
   cout << "Triangular Numbers Example" << endl;
   cout << "Chapter 3: Recursion" << endl << endl;

   cout << "The value of the 18th term using a loop: ";
   cout << TriNumLoop(18);
   cout << "." << endl;

   cout << "The value of the 25th term using recursion: ";
   cout << TriNumRecursion(25);
   cout << "." << endl;

   cout << endl;

   return 1;
}