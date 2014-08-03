/*
   Strings
   Chapter 12
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<iostream>
#include<string>
#include<algorithm>
#include<iterator>

using namespace std;


int main(int args, char **argc)
{
   cout << "Strings Example" << endl;
   cout << "Chapter 12: Additional STL" << endl;
   cout << endl;


   string str("Hello World");

   cout << "               String contents: " << str << endl;

   str.clear();
   cout << "   String contents after clear: " << str << endl;

   str = "Goodbye World";
   cout << "     Assigning string contents: " << str << endl;


   str.push_back('!');

   cout << "String contents with iterators: ";

   ostream_iterator<char> output(cout, "");
   copy(str.begin(), str.end(), output);
   cout << endl;


   cout << "              Reverse contents: ";

   copy(str.rbegin(), str.rend(), output);
   cout << endl << endl;


   cout << "Enter in a string and press enter: ";
   getline(cin, str);
   cout << endl;

   cout << "You've entered: " << str << endl << endl;

   return 1;
}