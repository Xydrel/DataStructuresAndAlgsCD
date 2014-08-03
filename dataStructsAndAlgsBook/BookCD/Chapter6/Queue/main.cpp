/*
   Queue Data Structures in C++
   Chapter 6
   Data Structures for Game Developers
   Created by Allen Sherrod
*/



#include<iostream>
#include"Queue.h"

using namespace std;


int main(int args, char **argc)
{
   cout << "Queue Data Structures Example" << endl;
   cout << "Chapter 6: Stacks and Queues" << endl;
   cout << endl;


   // Create and populate queue.
   const int size = 5;
   Queue<int> intQueue(size);

   for(int i = 0; i < size; i++)
      intQueue.push(10 + i);


   // Display integer queue.
   cout << "Queue Contents (Size - "
        << intQueue.GetSize() << ") :";

   while(intQueue.isEmpty() == false)
      {
         cout << " " << intQueue.front();
         intQueue.pop();
      }

   cout << "." << endl << endl;


   // Calling isEmpty() to test if container is empty.
   if(intQueue.isEmpty() == true)
      cout << "The int queue is empty." << endl << endl;
   else
      cout << "The int queue is NOT empty." << endl << endl;

   return 1;
}