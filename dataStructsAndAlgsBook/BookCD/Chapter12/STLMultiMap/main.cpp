/*
   STL Multi-Maps
   Chapter 12
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<iostream>
#include<map>
#include<string>
#include<algorithm>

using namespace std;


int main(int args, char **argc)
{
   cout << "STL Multi-Maps Example" << endl;
   cout << "Chapter 12: Additional STL" << endl;
   cout << endl;


   // Create and insert into the container.
   multimap<int, string> mapPair;

   mapPair.insert(map<int, string>::value_type(300, "Test 1"));
   mapPair.insert(map<int, string>::value_type(150, "Test 2"));
   mapPair.insert(map<int, string>::value_type(100, "Test 3"));
   mapPair.insert(map<int, string>::value_type(275, "Test 4"));
   mapPair.insert(map<int, string>::value_type(150, "Test 5"));


   // Test displaying contents.
   cout << "Displaying all items:" << endl;

   multimap<int, string>::iterator it;

   for(it = mapPair.begin(); it != mapPair.end(); it++)
      {
         cout << "   Key: " << (*it).first << " Value: " <<
                 (*it).second << "." << endl;
      }

   cout << endl;


   // Searching for and displaying all values that share a key.
   pair<multimap<int, string>::iterator,
        multimap<int, string>::iterator> range;

   range = mapPair.equal_range(150);

   cout << "Displaying all items in a range:" << endl;

   for(it = range.first; it != range.second; it++)
      {
         cout << "   Key: " << (*it).first << " Value: " <<
                 (*it).second << "." << endl;
      }

   cout << endl;


   // Test removing from the container.
   multimap<int, string>::iterator itPos = mapPair.find(150);

   if(itPos != mapPair.end())
      cout << "Found Key 100!" << endl;


   cout << endl;

   return 1;
}