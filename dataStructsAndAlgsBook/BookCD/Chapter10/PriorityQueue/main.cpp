/*
   Heap used in a Priority Queue
   Chapter 10
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<iostream>
#include"PriorityQueue.h"

using namespace std;


template<typename T>
class less_cmp
{
   public:
      inline bool operator()(T lVal, T rVal)
      {
         return (lVal < rVal);
      }
};


template<typename T>
class greater_cmp
{
   public:
      inline bool operator()(T lVal, T rVal)
      {
         return !(lVal < rVal);
      }
};


int main(int args, char **argc)
{
   cout << "Heap used in a Priority Queue" << endl;
   cout << "Chapter 10: Heaps" << endl;
   cout << endl;


   // Create the container and populate it.
   PriorityQueue<int, less_cmp<int> > pq;
   
   pq.push(33);
   pq.push(43);
   pq.push(23);
   pq.push(20);
   pq.push(10);
   pq.push(22);
   pq.push(90);
   pq.push(95);
   pq.push(86);


   // Display queue.
   cout << "Contents of the priority queue:";

   while(pq.empty() != true)
      {
         cout << " " << pq.peek();
         pq.pop();
      }

   cout << "." << endl << endl;

   return 1;
}