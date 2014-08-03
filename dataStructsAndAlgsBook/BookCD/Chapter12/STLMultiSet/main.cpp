/*
   STL Multi-Set
   Chapter 12
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<iostream>
#include<set>

using namespace std;


int main(int args, char **argc)
{
   cout << "STL Multi-Set Example" << endl;
   cout << "Chapter 12: Additional STL" << endl;
   cout << endl;


   // Create and insert into the container.
   multiset<int> setContainer;
   multiset<int>::iterator it;

   setContainer.insert(423);
   setContainer.insert(634);
   setContainer.insert(124);
   setContainer.insert(756);


   // Test displaying contents.
   cout << "Displaying all items:" << endl;

   for(it = setContainer.begin(); it != setContainer.end(); it++)
      {
         cout << "   Key/Value: " << (*it) << "." << endl;
      }

   cout << endl;


   // Test removing from the container.
   multiset<int>::iterator itPos = setContainer.find(124);

   if(itPos != setContainer.end())
      {
         setContainer.erase(124);
         cout << "Found and erased Key 124!" << endl << endl;
      }


   // Test displaying contents.
   cout << "Displaying all items:" << endl;

   for(it = setContainer.begin(); it != setContainer.end(); it++)
      {
         cout << "   Key/Value: " << (*it) << "." << endl;
      }

   cout << endl;


   return 1;
}