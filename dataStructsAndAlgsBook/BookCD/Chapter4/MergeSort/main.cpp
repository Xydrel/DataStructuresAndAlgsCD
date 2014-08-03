/*
   The Merge Sort Algorithm
   Chapter 4
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<iostream>
#include"Arrays.h"

using namespace std;


int main(int args, char *arg[])
{
   cout << "Merge Sort Algorithm" << endl;
   cout << "Chapter 4: Sorting" << endl << endl;

   UnorderedArray<int> array(5);
   array.push(645);
   array.push(294);
   array.push(777);
   array.push(789);
   array.push(119);
   array.push(100);
   array.push(823);


   cout << "Before merge sort:";

   for(int i = 0; i < 5; i++)
      {
         cout << " " << array[i];
      }

   cout << endl;


   array.MergeSort();


   cout << " After merge sort:";

   for(int i = 0; i < 5; i++)
      {
         cout << " " << array[i];
      }

   cout << endl << endl;

   return 1;
}