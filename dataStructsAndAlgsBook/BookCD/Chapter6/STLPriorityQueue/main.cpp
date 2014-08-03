/*
   STL Priority Queue in C++
   Chapter 6
   Data Structures for Game Developers
   Created by Allen Sherrod
*/



#include<iostream>
#include<queue>

using namespace std;


int main(int args, char **argc)
{
   cout << "STL Priority Queue Example" << endl;
   cout << "Chapter 6: Stacks and Queues" << endl;
   cout << endl;

   priority_queue<int> priQueue;

   for(int i = 0; i < 5; i++)
      priQueue.push(88 + i);


   // Display priority queue.
   cout << "Priority Queue (int) Contents (" << "Size: "
        << (int)priQueue.size() << ") -";

   int size = (int)priQueue.size();

   for(int i = 0; i < size; i++)
      {
         cout << " " << priQueue.top();
         priQueue.pop();
      }

   cout << "." << endl;


   // Empty test.
   if(priQueue.empty() == true)
      cout << "Priority Queue (int) is empty.";
   else
      cout << "Priority Queue (int) is NOT empty.";


   cout << endl << endl;

   return 1;
}