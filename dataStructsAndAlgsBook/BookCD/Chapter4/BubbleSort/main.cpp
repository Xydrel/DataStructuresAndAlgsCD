/*
   The Bubble Sort Algorithm
   Chapter 4
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<iostream>
#include"Arrays.h"

using namespace std;


int main(int args, char *arg[])
{
   cout << "Bubble Sort Algorithm" << endl;
   cout << "Chapter 4: Sorting" << endl << endl;

   UnorderedArray<int> array(5);
   array.push(80);
   array.push(64);
   array.push(99);
   array.push(76);
   array.push(5);


   cout << "Before sort:";

   for(int i = 0; i < 5; i++)
      {
         cout << " " << array[i];
      }

   cout << endl;


   array.BubbleSort();


   cout << " After sort:";

   for(int i = 0; i < 5; i++)
      {
         cout << " " << array[i];
      }

   cout << endl << endl;

   return 1;
}