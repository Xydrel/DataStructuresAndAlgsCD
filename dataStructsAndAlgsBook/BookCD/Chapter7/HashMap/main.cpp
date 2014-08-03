/*
   Hash Tables - Hash Map
   Chapter 7
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#ifdef NDEBUG
#  undef _STLP_DEBUG
#else
#  define _STLP_DEBUG 1
#endif

#ifdef WIN32
#  define NOMINMAX
#endif


#include<iostream>
#include<hash_map>


using namespace _STL;
using namespace std;


struct cmp
{
   bool operator()(const char *str1, const char *str2) const
   {
      return strcmp(str1, str2) == 0;
   }
};


int main(int args, char **argc)
{
   cout << "Hash Tables - Hash Map Example" << endl;
   cout << "Chapter 7: Hash Tables" << endl;
   cout << endl;


   hash_map<const char*, int, hash<const char*>, cmp> hashTable;

   if(hashTable.empty() == true)
      cout << "The hash table is now empty." << endl;

   hashTable["DVD"] = 30;
   hashTable["Apple"] = 1;
   hashTable["Video Game"] = 59;


   cout << "The hash table has " << hashTable.size()
        << " items after insertions." << endl << endl;


   cout << "DVD - " << hashTable["DVD"] << endl;
   cout << "Apple - " << hashTable["Apple"] << endl;
   cout << "Video Game - " << hashTable["Video Game"] << endl;
   cout << "PS3 - " << hashTable["PS3"] << endl;

   cout << endl;


   return 1;
}