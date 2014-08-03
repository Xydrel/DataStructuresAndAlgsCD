/*
   Recursion
   Chapter 3
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<iostream>
#include<cassert>

using namespace std;


void PrintNumReverse(int x)
{
   if(x <= 0)
      return;

   cout << " " << x;

   PrintNumReverse(x - 1);
}


int main(int args, char **argc)
{
   cout << "Recursion Example" << endl;
   cout << "Chapter 3: Recursion" << endl << endl;

   cout << "Example of a recursive call:";

   PrintNumReverse(10);

   cout << "." << endl << endl;

   return 1;
}