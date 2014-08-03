/*
   STL Deque in C++
   Chapter 6
   Data Structures for Game Developers
   Created by Allen Sherrod
*/



#include<iostream>
#include<deque>
#include<algorithm>
#include<numeric>

using namespace std;


void PrintDeque(deque<int> &deq)
{
   cout << "Contents (" << "Size: " << (int)deq.size() << ") - ";

   ostream_iterator<int> output(cout, " ");
   copy(deq.begin(), deq.end(), output);

   cout << endl;
}


void PrintDequeReverse(deque<int> &deq)
{
   cout << "Contents (" << "Size: " << (int)deq.size() << ") - ";

   ostream_iterator<int> output(cout, " ");
   copy(deq.rbegin(), deq.rend(), output);

   cout << endl;
}


int main(int args, char **argc)
{
   cout << "STL Deque Example" << endl;
   cout << "Chapter 6: Stacks and Queues" << endl;
   cout << endl;

   deque<int> intDeque;

   for(int i = 0; i < 5; i++)
      intDeque.push_back(66 + i);


   // Display deque.
   cout << "  Inserted into deque: ";
   PrintDeque(intDeque);

   cout << "       Reversed deque: ";
   PrintDequeReverse(intDeque);


   // Display item at the front of deque.
   cout << "        Deque Front(): "
        << intDeque.front() << "." << endl;

   // Display item at the front of deque.
   cout << "         Deque Back(): "
        << intDeque.back() << "." << endl;


   // Pop off the container.
   intDeque.pop_back();
   intDeque.pop_back();

   cout << "Popped two from deque: ";
   PrintDeque(intDeque);


   // Clear the container.
   intDeque.clear();

   cout << "        Cleared deque: ";
   PrintDeque(intDeque);

   cout << endl;


   // Test if the container is empty.
   if(intDeque.empty() == true)
      cout << "Deque is empty.";
   else
      cout << "Deque is NOT empty.";


   cout << endl << endl;

   return 1;
}