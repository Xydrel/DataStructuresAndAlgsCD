/*
   STL Set
   Chapter 12
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<iostream>
#include<set>

using namespace std;


int main(int args, char **argc)
{
   cout << "STL Set Example" << endl;
   cout << "Chapter 12: Additional STL" << endl;
   cout << endl;


   // Create and insert into the container.
   set<int> setContainer;

   setContainer.insert(300);
   setContainer.insert(150);
   setContainer.insert(400);
   setContainer.insert(375);

   set<int> setCopy(setContainer);


   // Test displaying contents.
   cout << "Displaying all items:" << endl;

   for(set<int>::iterator it = setCopy.begin();
       it != setCopy.end(); it++)
      {
         cout << "   Key/Value: " << (*it) << "." << endl;
      }

   cout << endl;


   // Test removing from the container.
   set<int>::iterator itPos = setContainer.find(150);

   if(itPos != setContainer.end())
      cout << "Found Key 150!" << endl << endl;


   return 1;
}