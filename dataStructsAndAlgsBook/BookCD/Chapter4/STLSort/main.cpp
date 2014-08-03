/*
   The STL Sorting Algorithm
   Chapter 4
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<iterator>

using namespace std;


inline bool CompareNoCase(char lVal, char rVal)
{
   return tolower(lVal) < tolower(rVal);
}


int main(int args, char *arg[])
{
   cout << "STL Sorting Algorithm" << endl;
   cout << "Chapter 4: Sorting" << endl << endl;

   char str1[] = "lekiamhjdqn";
   char str2[] = "peuyxknasdb";
   vector<int> int1;
   
   int1.push_back(58);
   int1.push_back(23);
   int1.push_back(1);
   int1.push_back(53);
   int1.push_back(33);
   int1.push_back(84);
   int1.push_back(12);

   cout << "Original str1 data: " << str1 << "." << endl;
   sort(str1, str1 + (sizeof(str1) - 1), CompareNoCase);
   cout << "  Sorted str1 data: " << str1 << "." << endl;

   cout << endl;

   cout << "Original str2 data: " << str2 << "." << endl;
   stable_sort(str2, str2 + (sizeof(str2) - 1), CompareNoCase);
   cout << "  Sorted str2 data: " << str2 << "." << endl;

   cout << endl;

   ostream_iterator<int> output(cout, " ");

   cout << "Original int1 data: ";
   copy(int1.begin(), int1.end(), output);
   cout << endl;

   partial_sort(int1.begin(), int1.begin() + int1.size(),
                int1.end(), less<int>());

   cout << "  Sorted int1 data: ";
   copy(int1.begin(), int1.end(), output);
   cout << endl << endl;

   return 1;
}