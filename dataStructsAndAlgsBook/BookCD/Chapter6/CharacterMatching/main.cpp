/*
   Character Matching in C++
   Chapter 6
   Data Structures for Game Developers
   Created by Allen Sherrod
*/



#include<iostream>
#include"Stack.h"

using namespace std;


void PrintError(char ch, int index)
{
   cout << "   Error " << ch << " at " << index << "." << endl;
}


void ParseString(char *str, int size)
{
   if(str == NULL || size <= 0)
      {
         cout << "   Error with parameters!" << endl << endl;
         return;
      }

   Stack<char> sList(size);
   char ch = 0;
   int errors = 0;

   for(int i = 0; i < size; i++)
      {
         switch(str[i])
            {
               case '{':
               case '(':
               case '[':
                  sList.push(str[i]);
                  break;

               case '}':
               case ')':
               case ']':
                  if(sList.isEmpty() == false)
                     {
                        ch = sList.pop();

                        if((ch != '{' && str[i] == '}') ||
                           (ch != '(' && str[i] == ')') ||
                           (ch != '[' && str[i] == ']'))
                           {
                              PrintError(ch, i + 1);
                              errors++;
                           }
                     }
                  break;
            }
      }

   if(sList.isEmpty() && errors == 0)
      cout << "   No Parsing Errors." << endl << endl;
   else if(sList.isEmpty() == false)
      cout << "   Unclosed Characters: " << sList.GetSize()
           << "." << endl << endl;
}


int main(int args, char **argc)
{
   cout << "Character Matching with Stacks Example" << endl;
   cout << "Chapter 6: Stacks and Queues" << endl;
   cout << endl;


   char str[] = { '{', '(', 'a', '[', '5', ']', ')', '}' };
   int size = strlen(str);

   cout << "Parsing str." << endl;
   ParseString(str, size);


   char str2[] = { '{', ')', 'b', '[', '10', ']', ')', '}' };
   size = strlen(str2);

   cout << "Parsing str2." << endl;
   ParseString(str2, size);

   cout << endl;

   return 1;
}