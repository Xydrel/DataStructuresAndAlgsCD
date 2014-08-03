/*
   STL Vector 3: Deleting Newed Pointers
   Chapter 2
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class ExampleClass
{
   public:
      ExampleClass()
      {
         cout << "Item created!" << endl;
      }

      ~ExampleClass()
      {
         cout << "Item deleted!" << endl;
      }
};


struct DeleteMemObj
{
   template<typename T>
   void operator()(const T* ptr) const
   {
      delete ptr;
      ptr = NULL;
   }
};


int main(int args, char **argc)
{
   cout << "STL Vector Example 3: Deleting Newed Pointers" << endl;
   cout << "Data Structures for Game Developers" << endl;
   cout << "Allen Sherrod" << endl << endl;


   vector<ExampleClass*> array;
   array.reserve(5);

   array.push_back(new ExampleClass);
   array.push_back(new ExampleClass);
   array.push_back(new ExampleClass);
   array.push_back(new ExampleClass);
   array.push_back(new ExampleClass);

   cout << endl;


   for_each(array.begin(), array.end(),
            DeleteMemObj());

   cout << endl;

   cout << "Array items deleted!";

   cout << endl << endl;

   return 1;
}