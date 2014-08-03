/*
   STL Queue in C++
   Chapter 6
   Data Structures for Game Developers
   Created by Allen Sherrod
*/



#include<iostream>
#include<queue>
#include<list>

using namespace std;


template<typename T>
void DisplayQueue(T &que)
{
   cout << "(Size - " << que.size() << ") :";

   while(que.empty() == false)
      {
         cout << " " << que.front();
         que.pop();
      }

   cout << "." << endl;
}


int main(int args, char **argc)
{
   cout << "STL Queue Example" << endl;
   cout << "Chapter 6: Stacks and Queues" << endl;
   cout << endl;


   queue<int> intQueue;
   queue<int, list<int> > listQueue;

   for(int i = 0; i < 5; i++)
      {
         intQueue.push(44 + i);
         listQueue.push(55 + i);
      }


   // Display normal (deque) integer queue.
   cout << "       Contents of the int queue ";
   DisplayQueue(intQueue);


   // Display link list integer queue.
   cout << "  Contents of the int list queue ";
   DisplayQueue(listQueue);

   cout << endl;


   // Calling empty() to test if container is empty.
   if(intQueue.empty() == true)
      cout << "The int queue is empty." << endl;
   else
      cout << "The int queue is NOT empty." << endl;

   // Calling empty() to test if container is empty.
   if(listQueue.empty() == true)
      cout << "The list int queue is empty." << endl;
   else
      cout << "The list int queue is NOT empty." << endl;

   cout << endl;

   return 1;
}