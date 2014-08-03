/*
   STL Link List
   Chapter 2
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<iostream>
#include<list>
#include<algorithm>
#include<numeric>

using namespace std;


void PrintList(list<int> &lList)
{
   cout << "Contents (" << "Size: "
        << (int)lList.size() << ") - ";

   ostream_iterator<int> output(cout, " ");
   copy(lList.begin(), lList.end(), output);

   cout << endl;
}


void PrintListReverse(list<int> &lList)
{
   cout << "Contents (" << "Size: "
        << (int)lList.size() << ") - ";

   ostream_iterator<int> output(cout, " ");
   copy(lList.rbegin(), lList.rend(), output);

   cout << endl;
}


int main(int args, char **argc)
{
   cout << "STL Link List Example" << endl;
   cout << "Data Structures for Game Developers" << endl;
   cout << "Allen Sherrod" << endl << endl;

   list<int> lList;

   // Add items then print.
   lList.push_back(60);
   lList.push_back(20);
   lList.push_back(40);
   lList.push_back(90);
   lList.push_back(10);


   // Calling the copy algorithm.
   list<int> lList2;

   for(int i = 0; i < 5; i++)
      lList2.push_back(0);

   copy(lList.begin(), lList.end(), lList2.begin());


   // Display list.
   cout << "  Inserted into list:  ";
   PrintList(lList);

   // Display list in reverse.
   cout << "    Reverse contents:  ";
   PrintListReverse(lList);

   // Sort the list.
   lList.sort();

   cout << "    Sorting the list:  ";
   PrintList(lList);

   // Reverse the list.
   lList.reverse();

   cout << "    Reverse the list:  ";
   PrintList(lList);


   // Push and pop from the front.
   lList.push_front(60);
   lList.push_front(70);
   lList.pop_front();
   lList.push_front(80);

   cout << "      Push/Pop Front:  ";
   PrintList(lList);


   // Run the accumulate algorithm.
   cout << "          Accumulate:  "
        << accumulate(lList.begin(), lList.end(), 0)
        << endl;


   // Pop off the container.
   lList.pop_back();
   lList.pop_back();

   cout << "Popped two from list:  ";
   PrintList(lList);


   // Clear the container.
   lList.clear();

   cout << "        Cleared list:  ";
   PrintList(lList);

   cout << endl;


   // Test if the container is empty.
   if(lList.empty() == true)
      cout << "List is empty.";
   else
      cout << "List is NOT empty.";


   cout << endl << endl;

   return 1;
}