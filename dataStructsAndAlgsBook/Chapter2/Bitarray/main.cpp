/*
   Bit Array Data Structure
   Chapter 2
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<iostream>
#include"BitArray.h"

using std::cout;
using std::endl;


int main(int args, char **argc)
{
   BitArray bitArray(16);

   cout << "Bit Array Example" << endl;
   cout << "Data Structures for Game Developers" << endl;
   cout << "Allen Sherrod" << endl << endl;


   cout << "Initial bit values for 2, 3 and 14." << endl << endl;

   cout << "Bit  2 = " << bitArray[ 2] << "." << endl;
   cout << "Bit  3 = " << bitArray[ 3] << "." << endl;
   cout << "Bit 14 = " << bitArray[14] << "." << endl << endl;


   cout << "Set bits 2 and 14." << endl << endl;

   bitArray.SetBit(2);
   bitArray.SetBit(14);

   cout << "Bit  2 = " << bitArray[ 2] << "." << endl;
   cout << "Bit  3 = " << bitArray[ 3] << "." << endl;
   cout << "Bit 14 = " << bitArray[14] << "." << endl << endl;


   cout << "Set all bits" << endl << endl;

   bitArray.SetAllBits();

   cout << "Bit  2 = " << bitArray[ 2] << "." << endl;
   cout << "Bit  3 = " << bitArray[ 3] << "." << endl;
   cout << "Bit 14 = " << bitArray[14] << "." << endl << endl;


   cout << "Clear all bits" << endl << endl;

   bitArray.ClearAllBits();

   cout << "Bit  2 = " << bitArray[ 2] << "." << endl;
   cout << "Bit  3 = " << bitArray[ 3] << "." << endl;
   cout << "Bit 14 = " << bitArray[14] << "." << endl << endl;

   return 1;
}