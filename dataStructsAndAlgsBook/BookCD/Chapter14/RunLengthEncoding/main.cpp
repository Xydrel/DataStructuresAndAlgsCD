/*
   Run Length Encoding
   Chapter 14
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<iostream>
#include<string>

using namespace std;


void Encode(string &src, string &dst)
{
   int index = 0;
   char runTotal = 0, currentChar = 0;

   while(index < (int)src.length())
      {
         runTotal = 0;
         currentChar = src[index];

         while(currentChar == src[index] && runTotal < 255)
            {
               runTotal++;
               index++;
            }

         if(runTotal > 3)
            {
               dst += '~';
               dst += runTotal;
               dst += currentChar;
            }
         else
            {
               for(int i = 0; i < runTotal; i++)
                  {
                     dst += currentChar;
                  }
            }
      }
}


void Decode(string &src, string &dst)
{
   int index = 0, runTotal = 0;
   char currentChar = 0;

   while(index < (int)src.length())
      {
         if(src[index++] == '~')
            {
               runTotal = (int)src[index++];
               currentChar = src[index++];

               for(int i = 0; i < runTotal; i++)
                  {
                     dst += currentChar;
                  }
            }
         else
            {
               dst += src[index - 1];
            }
      }
}


int main(int args, char **argc)
{
   cout << "Run Length Encoding" << endl;
   cout << "Chapter 14: Data Compression and Encryption" << endl;
   cout << endl;


   string str = "AAAAaaBBBBBBCCCCCCddddddEEEEEeeeeFFFFGGGG";
   string encodedStr, decodedStr;

   cout << "Original Data Size: " << str.length() << endl;
   cout << "Original Data:" << endl;
   cout << str << endl << endl;


   Encode(str, encodedStr);

   cout << "Compressed Size: " << encodedStr.length() << endl;
   cout << "Compressed Data:" << endl;
   cout << encodedStr << endl << endl;


   Decode(encodedStr, decodedStr);

   cout << "Decompressed Size: " << decodedStr.length() << endl;
   cout << "Decompressed Data:" << endl;
   cout << decodedStr << endl << endl;


   return 1;
}