/*
   STL Vector 2: Iterators
   Chapter 2
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;


void PrintVector(vector<int> &array)
{
   cout << "Contents (" << "Size: " << (int)array.size() <<
           " Max: " << (int)array.capacity() << ") - ";

   ostream_iterator<int> output(cout, " ");
   copy(array.begin(), array.end(), output);

   cout << endl;
}


int main(int args, char **argc)
{
   cout << "STL Vector Example 2: Iterators" << endl;
   cout << "Data Structures for Game Developers" << endl;
   cout << "Allen Sherrod" << endl << endl;


   vector<int> array;
   array.reserve(5);

   // Add items then print.
   array.push_back(10);
   array.push_back(20);
   array.push_back(30);
   array.push_back(40);
   array.push_back(50);


   // Calling the copy algorithm.
   vector<int> array2;
   for(int i = 0; i < 5; i++)
      array2.push_back(0);

   copy(array.begin(), array.end(), array2.begin());
   

   cout << "  Inserted into vector:  ";
   PrintVector(array);


   // Run the accumulate algorithm.
   cout << "            Accumulate:  "
        << accumulate(array.begin(), array.end(), 0)
        << endl;


   // Pop off the container.
   array.pop_back();
   array.pop_back();

   cout << "Popped two from vector:  ";
   PrintVector(array);


   // Clear the container.
   array.clear();

   cout << "        Cleared vector:  ";
   PrintVector(array);

   cout << endl;

   // Test if the container is empty.
   if(array.empty() == true)
      cout << "Vector is empty.";
   else
      cout << "Vector is NOT empty.";


   cout << endl << endl;

   return 1;
}