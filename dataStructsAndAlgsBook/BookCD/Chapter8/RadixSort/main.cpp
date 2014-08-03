/*
   Radix Sort in C++
   Chapter 8
   Data Structures for Game Developers
   Created by Allen Sherrod
*/



#include<iostream>
#include<deque>

using namespace std;


#define BASE            10
#define MAX_POSITIONS   2


void RadixSort(int *array, int size)
{
   // Base index, radix index, counter.
   int b = 0, r = 0, i = 0;

   // Container conter, base factor.
   int index = 0, factor = 0;

   // List of containers for the sort.
   deque<int> qList[BASE];

   // Place in containers then take them off for every base.
   for(b = 1, factor = 1; b <= MAX_POSITIONS; factor *= BASE, b++)
      {
         for(r = 0; r < size; r++)
            {
               index = (array[r] / factor) % BASE;
               qList[index].push_back(array[r]);
            }

         for(r = 0, i = 0; r < BASE; r++)
            {
               while(qList[r].empty() != true)
                  {
                     array[i++] = qList[r].front();
                     qList[r].pop_front();
                  }
            }
      }
}


int main(int args, char **argc)
{
   cout << "Radix Sort Example" << endl;
   cout << "Chapter 8: Advanced Sorting" << endl;
   cout << endl;

   const int size = 10;
   int array[size];
   int i = 0;


   // Populate array.
   for(i = 0; i < size; i++)
      array[i] = 10 + rand() % 89;


   // Display array contents.
   cout << "Array contents before sort: ";

   for(i = 0; i < size; i++)
      cout << " " << array[i];

   cout << endl;


   // Radix sorting.
   RadixSort(array, size);


   // Display array contents.
   cout << " Array contents after sort: ";

   for(i = 0; i < size; i++)
      cout << " " << array[i];

   cout << endl << endl;

   return 1;
}