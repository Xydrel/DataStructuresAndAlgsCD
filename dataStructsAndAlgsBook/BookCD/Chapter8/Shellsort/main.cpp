/*
   The Shellsort Algorithm
   Chapter 8
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<iostream>
#include"Arrays.h"

using namespace std;


int main(int args, char *arg[])
{
   cout << "Shellsort Algorithm" << endl;
   cout << "Chapter 8: Advance Sorting" << endl << endl;

   const int size = 10;
   int i = 0;

   UnorderedArray<int> array(size);

   for(i = 0; i < size; i++)
      array.push(rand() % 100);


   cout << "Before shellsort sort:";

   for(i = 0; i < size; i++)
      cout << " " << array[i];

   cout << endl;


   array.Shellsort();


   cout << " After shellsort sort:";

   for(i = 0; i < size; i++)
      cout << " " << array[i];

   cout << endl << endl;

   return 1;
}