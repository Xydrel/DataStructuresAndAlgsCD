/*
   The Insertion Sort Algorithm
   Chapter 4
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<iostream>
#include"Arrays.h"

using namespace std;


int main(int args, char *arg[])
{
   cout << "Insertion Sort Algorithm" << endl;
   cout << "Chapter 4: Sorting" << endl << endl;

   UnorderedArray<int> array(5);
   array.push(348);
   array.push(112);
   array.push(847);
   array.push(999);
   array.push(264);


   cout << "Before insertion sort:";

   for(int i = 0; i < 5; i++)
      {
         cout << " " << array[i];
      }

   cout << endl;


   array.InsertionSort();


   cout << " After insertion sort:";

   for(int i = 0; i < 5; i++)
      {
         cout << " " << array[i];
      }

   cout << endl << endl;

   return 1;
}