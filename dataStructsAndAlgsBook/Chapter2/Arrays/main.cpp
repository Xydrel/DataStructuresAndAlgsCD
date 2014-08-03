/*
   Arrays in C++
   Chapter 2
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<iostream>


int main(int args, char **argc)
{
   std::cout << "1D Array Example" << std::endl;
   std::cout << "Chapter 2: Arrays in C++" << std::endl;
   std::cout << std::endl;

   const int size = 5;
   int array[size] = { 10, 32, 53, 91, 21 };

   std::cout << " Static array contents (" << size << "): ";

   for(int i = 0; i < size; i++)
      {
         std::cout << array[i] << " ";
      }

   std::cout << std::endl;


   int *array2 = new int[size];

   array2[0] = 99;
   array2[1] = 67;
   array2[2] = 23;
   array2[3] = 49;
   array2[4] = 12;

   std::cout << "Dynamic array contents (" << size << "): ";

   for(int i = 0; i < size; i++)
      {
         std::cout << array2[i] << " ";
      }

   delete array2;

   std::cout << std::endl << std::endl;

   return 1;
}