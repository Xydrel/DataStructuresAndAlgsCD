/*
   Heap Sort
   Chapter 10
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<iostream>
#include<vector>
#include"Heap.h"

using namespace std;


void HeapSortAscending(vector<int> &array)
{
   Heap<int> heap;
   int i;

   for(i = 0; i < (int)array.size(); i++)
      heap.push(array[i]);

   for(i = (int)array.size() - 1; i >= 0; i--)
      {
         array[i] = heap.peek();
         heap.pop();
      }
}


void HeapSortDescending(vector<int> &array)
{
   Heap<int> heap;
   int i;

   for(i = 0; i < (int)array.size(); i++)
      heap.push(array[i]);

   for(i = 0; i < (int)array.size(); i++)
      {
         array[i] = heap.peek();
         heap.pop();
      }
}


void DisplayVector(vector<int> &array)
{
   for(int i = 0; i < (int)array.size(); i++)
      {
         cout << " " << array[i];
      }

   cout << ".";
}


int main(int args, char **argc)
{
   cout << "Heap Sort" << endl;
   cout << "Chapter 10: Heaps" << endl;
   cout << endl;


   // Create container and populate it.
   vector<int> array;
   
   array.push_back(33);
   array.push_back(43);
   array.push_back(23);
   array.push_back(20);
   array.push_back(10);
   array.push_back(22);
   array.push_back(90);
   array.push_back(95);
   array.push_back(86);


   // Display before sort.
   cout << "Array contents before sort:";
   DisplayVector(array);
   cout << endl;


   // Display after sort (ascending).
   HeapSortAscending(array);

   cout << "Array contents after sort (ascending ):";
   DisplayVector(array);
   cout << endl;


   // Display after sort (descending).
   HeapSortDescending(array);

   cout << "Array contents after sort (descending):";
   DisplayVector(array);
   cout << endl << endl;

   return 1;
}