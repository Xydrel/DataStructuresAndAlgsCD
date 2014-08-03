/*
   Hash Tables - Hash Multi-Map Table
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


typedef hash_multimap<const char*, int, hash<const char*>, cmp> hashType;


void Find(const hashType &hTable, const char *str)
{
   cout << str << " - ";

   pair<hashType::const_iterator,
        hashType::const_iterator> range = hTable.equal_range(str);

   hashType::const_iterator it;

   for(it = range.first; it != range.second; it++)
      cout << (*it).second << " ";

   cout << endl;
}


int main(int args, char **argc)
{
   cout << "Hash Tables - Hash Multi-Map Table Example" << endl;
   cout << "Chapter 7: Hash Tables" << endl;
   cout << endl;


   hashType hashTable;

   if(hashTable.empty() == true)
      cout << "The hash table is now empty." << endl;

   hashTable.insert(hashType::value_type("DVD", 30));
   hashTable.insert(hashType::value_type("Apple", 1));
   hashTable.insert(hashType::value_type("Video Game", 59));


   cout << "The hash table has " << hashTable.size()
        << " items after insertions." << endl << endl;


   Find(hashTable, "DVD");
   Find(hashTable, "Apple");
   Find(hashTable, "Video Game");
   Find(hashTable, "PS3");

   cout << endl;


   return 1;
}