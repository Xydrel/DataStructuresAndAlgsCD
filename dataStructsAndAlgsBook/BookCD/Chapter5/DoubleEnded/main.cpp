/*
   Double-Ended Link Lists in C++
   Chapter 5
   Data Structures for Game Developers
   Created by Allen Sherrod
*/



#include<iostream>
#include"LinkList.h"

using namespace std;


int main(int args, char **argc)
{
   cout << "Double-Ended Link List Example" << endl;
   cout << "Chapter 5: Link Lists" << endl;
   cout << endl;


   LinkList<int> lList;

   lList.Push(101);
   lList.Push_Front(201);
   lList.Push(301);
   lList.Push_Front(401);
   lList.Push(501);

   lList.Pop();
   lList.Push(601);
   lList.Pop_Front();


   LinkIterator<int> it;

   cout << "Contents of the link list:";

   for(it = lList.Begin(); it != lList.End(); it++)
      {
         cout << " " << *it;
      }


   cout << "." << endl << endl;

   return 1;
}