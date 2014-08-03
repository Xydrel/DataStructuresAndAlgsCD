/*
   Factorials
   Chapter 3
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<iostream>
#include<cassert>

using namespace std;


int factorial(int x)
{
	assert(x >= 0);

   if(x == 0)
      return 1;

   return(factorial(x - 1) * x);
}


int doubleFactorial(int x)
{
	assert(x >= 0);

   if(x == 0)
      return 1;

   return(factorial(x - 2) * x);
}


int main(int args, char **argc)
{
   cout << "Factorials" << endl;
   cout << "Chapter 3: Recursion" << endl << endl;

   cout << "The factorial of 3: ";
   cout << factorial(3);
   cout << "." << endl;

   cout << "The double factorial of 4: ";
   cout << doubleFactorial(4);
   cout << "." << endl;

   cout << endl;

   return 1;
}