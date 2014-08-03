/*
   Hash Tables - Separate Chaining
   Chapter 7
   Data Structures for Game Developers
   Created by Allen Sherrod
*/



#include<iostream>
#include"HashTable.h"

using namespace std;


int main(int args, char **argc)
{
   cout << "Hash Tables - Separate Chaining Example" << endl;
   cout << "Chapter 7: Hash Tables" << endl;
   cout << endl;


   HashTable<int> hashTable(21);
   int item = 0;

   item = 142; hashTable.Insert(31, item);
   item = 756; hashTable.Insert(42, item);
   item = 432; hashTable.Insert(24, item);
   item = 124; hashTable.Insert(51, item);
   item = 786; hashTable.Insert(12, item);


   // Search for inserted items.
   if(hashTable.Find(31, &item))
      cout << "Item: 31 has a value of " << item << "." << endl;
   else
      cout << "Item: 31 not found." << endl;

   if(hashTable.Find(84, &item))
      cout << "Item: 84 has a value of " << item << "." << endl;
   else
      cout << "Item: 84 not found." << endl;

   if(hashTable.Find(99, &item))
      cout << "Item: 99has a value of " << item << "." << endl;
   else
      cout << "Item: 99 not found." << endl;

   if(hashTable.Find(51, &item))
      cout << "Item: 51 has a value of " << item << "." << endl;
   else
      cout << "Item: 51 not found." << endl;

   if(hashTable.Find(12, &item))
      cout << "Item: 12 has a value of " << item << "." << endl;
   else
      cout << "Item: 12 not found." << endl;

   cout << "\n";


   return 1;
}