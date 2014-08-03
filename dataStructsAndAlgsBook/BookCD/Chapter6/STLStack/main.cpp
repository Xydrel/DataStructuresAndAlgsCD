/*
   STL Stacks in C++
   Chapter 6
   Data Structures for Game Developers
   Created by Allen Sherrod
*/



#include<iostream>
#include<stack>
#include<vector>
#include<list>

using namespace std;


template<typename T>
void DisplayStack(T &stack)
{
   cout << "(Size - " << stack.size() << ") :";

   while(stack.empty() == false)
      {
         cout << " " << stack.top();
         stack.pop();
      }

   cout << "." << endl;
}


int main(int args, char **argc)
{
   cout << "STL Stacks Example" << endl;
   cout << "Chapter 6: Stacks and Queues" << endl;
   cout << endl;


   stack<int> intStack;
   stack<int, vector<int> > vecStack;
   stack<int, list<int> > listStack;

   for(int i = 0; i < 5; i++)
      {
         intStack.push(11 + i);
         vecStack.push(22 + i);
         listStack.push(33 + i);
      }


   // Display normal (deque) integer stack.
   cout << "       Contents of the int stack ";
   DisplayStack(intStack);


   // Display vector integer stack.
   cout << "Contents of the int vector stack ";
   DisplayStack(vecStack);


   // Display link list integer stack.
   cout << "  Contents of the int list stack ";
   DisplayStack(listStack);

   cout << endl;


   // Calling empty() to test if container is empty.
   if(intStack.empty() == true)
      cout << "The int stack is empty." << endl;
   else
      cout << "The int stack is NOT empty." << endl;

   // Calling empty() to test if container is empty.
   if(vecStack.empty() == true)
      cout << "The vec int stack is empty." << endl;
   else
      cout << "The vec int stack is NOT empty." << endl;

   // Calling empty() to test if container is empty.
   if(listStack.empty() == true)
      cout << "The list int stack is empty." << endl;
   else
      cout << "The list int stack is NOT empty." << endl;

   cout << endl;

   return 1;
}