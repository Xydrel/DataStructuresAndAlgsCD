/*
   Stacks implemented with UnorderedArray in C++
   Chapter 6
   Data Structures for Game Developers
   Created by Allen Sherrod
*/



#include<iostream>
#include"Stack.h"

using namespace std;


int main(int args, char **argc)
{
   cout << "Stacks implemented with UnorderedArray Example" << endl;
   cout << "Chapter 6: Stacks and Queues" << endl;
   cout << endl;


   Stack<int> sList(5);

   sList.push(101);
   sList.push(201);
   sList.push(301);
   sList.push(401);
   sList.push(501);

   sList.pop();

   sList.push(601);

   cout << "Contents of the stack:";

   while(sList.isEmpty() == false)
      {
         cout << " " << sList.top();
         sList.pop();
      }


   cout << "." << endl << endl;

   return 1;
}