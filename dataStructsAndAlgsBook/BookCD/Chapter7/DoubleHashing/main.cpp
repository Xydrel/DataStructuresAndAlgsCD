/*
   Hash Tables - Double Hashing
   Chapter 7
   Data Structures for Game Developers
   Created by Allen Sherrod
*/



#include<iostream>
#include"HashTable.h"

using namespace std;


int main(int args, char **argc)
{
   cout << "Hash Tables - Double Hashing Example" << endl;
   cout << "Chapter 7: Hash Tables" << endl;
   cout << endl;


   // Create table and fill it in.
   HashTable<int> hashTable(20);
   int item = 0;

   item = 835; hashTable.Insert(57, item);
   item = 247; hashTable.Insert(68, item);
   item = 456; hashTable.Insert(37, item);
   item = 235; hashTable.Insert(82, item);
   item = 644; hashTable.Insert(11, item);


   // Search for inserted items.
   if(hashTable.Find(87, &item))
      cout << "Item: 87 has a value of " << item << "." << endl;
   else
      cout << "Item: 87 not found." << endl;

   if(hashTable.Find(112, &item))
      cout << "Item: 112 has a value of " << item << "." << endl;
   else
      cout << "Item: 112 not found." << endl;

   if(hashTable.Find(82, &item))
      cout << "Item: 82 has a value of " << item << "." << endl;
   else
      cout << "Item: 82 not found." << endl;

   if(hashTable.Find(37, &item))
      cout << "Item: 37 has a value of " << item << "." << endl;
   else
      cout << "Item: 37 not found." << endl;

   cout << endl;


   return 1;
}