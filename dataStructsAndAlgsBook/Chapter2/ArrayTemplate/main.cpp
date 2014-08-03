/*
   Array Data Structure
   Chapter 2
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<iostream>
#include"Arrays.h"

using std::cout;
using std::endl;


void UnorderedArrayTest()
{
   UnorderedArray<int> array(3);

   array.push(3);
   array.push(53);
   array.push(83);
   array.push(23);
   array.push(82);

   array[2] = 112;

   array.pop();
   array.remove(2);

   cout << "Unordered array contents: ";

   for(int i = 0; i < array.GetSize(); i++)
      {
         cout << array[i] << " ";
      }

   cout << endl;

   cout << "Search for 53 was found at index: ";
   cout << array.search(53);

   cout << endl << endl;
}


void OrderedArrayTest()
{
   OrderedArray<int> array(3);

   array.push(43);
   array.push(8);
   array.push(23);
   array.push(94);
   array.push(17);

   array.pop();
   array.remove(2);

   cout << "Ordered array contents: ";

   for(int i = 0; i < array.GetSize(); i++)
      {
         cout << array[i] << " ";
      }

   cout << endl;

   cout << "Search for 12 was found at index: ";
   cout << array.search(12);

   cout << endl << endl;
}


int main(int args, char **argc)
{
   UnorderedArrayTest();
   OrderedArrayTest();

   return 1;
}