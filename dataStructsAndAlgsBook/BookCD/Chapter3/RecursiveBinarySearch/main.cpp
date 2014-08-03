/*
   Recursive Binary Search
   Chapter 3
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<iostream>
#include"Arrays.h"

using namespace std;


int main(int args, char **argc)
{
   cout << "Recursive Binary Search Example" << endl;
   cout << "Chapter 3: Recursion" << endl << endl;


   OrderedArray<int> array(3);

   array.push(43);
   array.push(8);
   array.push(23);
   array.push(94);
   array.push(17);
   array.push(83);
   array.push(44);
   array.push(28);


   cout << "Ordered array contents:";

   for(int i = 0; i < array.GetSize(); i++)
      {
         cout << " " << array[i];
      }

   cout << "." << endl;


   cout << "Search for 43 was found at index: ";
   cout << array.search(43) << ".";


   cout << endl << endl;

   return 1;
}