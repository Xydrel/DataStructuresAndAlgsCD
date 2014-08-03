/*
   STL Val Array Data Structure
   Chapter 2
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<iostream>
#include<valarray>

using namespace std;


void PrintValArray(const valarray<int> &valArray)
{
   cout << "Contents of valArray: ";

   for(int i = 0; i < 10; i++)
      {
         cout << valArray[i] << " ";
      }

   cout << endl << endl;
}


int main(int args, char **argc)
{
   cout << "STL Val Array Example" << endl;
   cout << "Data Structures for Game Developers" << endl;
   cout << "Allen Sherrod" << endl << endl;


   valarray<int> valArray(10);

   for(int i = 0; i < 10; i++)
      {
         valArray[i] = i;
      }

   PrintValArray(valArray);


   valarray<int>::value_type rVal = 5;

   cout << "The value of rVal before multiplication: "
        << rVal << endl << endl;

   valArray *= rVal;

   PrintValArray(valArray);

   return 1;
}