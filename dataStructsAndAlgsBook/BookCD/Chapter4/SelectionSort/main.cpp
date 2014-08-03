/*
   The Selection Sort Algorithm
   Chapter 4
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<iostream>
#include"Arrays.h"

using namespace std;


int main(int args, char *arg[])
{
   cout << "Selection Sort Algorithm" << endl;
   cout << "Chapter 4: Sorting" << endl << endl;

   UnorderedArray<int> array(5);
   array.push(136);
   array.push(489);
   array.push(28);
   array.push(1);
   array.push(393);


   cout << "Before selection sort:";

   for(int i = 0; i < 5; i++)
      {
         cout << " " << array[i];
      }

   cout << endl;


   array.SelectionSort();


   cout << " After selection sort:";

   for(int i = 0; i < 5; i++)
      {
         cout << " " << array[i];
      }

   cout << endl << endl;

   return 1;
}