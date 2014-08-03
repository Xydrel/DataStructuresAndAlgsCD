/*
   STL Maps
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
   cout << "STL Maps Example" << endl;
   cout << "Chapter 12: Additional STL" << endl;
   cout << endl;


   // Create and insert into the container.
   map<int, string> mapPair;

   mapPair.insert(map<int, string>::value_type(300, "Test 1"));
   mapPair.insert(map<int, string>::value_type(150, "Test 2"));
   mapPair.insert(map<int, string>::value_type(400, "Test 3"));
   mapPair.insert(map<int, string>::value_type(600, "Test 4"));

   mapPair[100] = "One hundred";

   cout << "Diplaying 400: " << mapPair[400].c_str() <<
           endl << endl;


   // Test displaying contents.
   cout << "Displaying all items:" << endl;

   for(map<int, string>::iterator it = mapPair.begin();
       it != mapPair.end(); it++)
      {
         cout << "   Key: " << (*it).first << " Value: " <<
                 (*it).second << "." << endl;
      }

   cout << endl;


   // Test removing from the container.
   map<int, string>::iterator itPos = mapPair.find(150);

   if(itPos != mapPair.end())
      cout << "Found Key 150!" << endl;


   cout << endl;

   return 1;
}