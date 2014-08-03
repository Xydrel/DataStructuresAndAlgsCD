/*
   Hash Tables - Hash Set
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
#include<hash_set>


using namespace _STL;
using namespace std;


struct cmp
{
   bool operator()(const char *str1, const char *str2) const
   {
      return strcmp(str1, str2) == 0;
   }
};


void Find(const hash_set<const char*, hash<const char*>, cmp> &c,
           const char *str)
{
   hash_set<const char*, hash<const char*>,
            cmp>::const_iterator it = c.find(str);

   if(it == c.end())
      cout << str << " - was not found!" << endl;
   else
      cout << str << " - was found in the hash table!" << endl;
}


int main(int args, char **argc)
{
   cout << "Hash Tables - Hash Set Example" << endl;
   cout << "Chapter 7: Hash Tables" << endl;
   cout << endl;


   hash_set<const char*, hash<const char*>, cmp> hashTable;

   hashTable.insert("Hello");
   hashTable.insert("Goodbye");
   hashTable.insert("So Long");
   hashTable.insert("Take Care");

   Find(hashTable, "Test");
   Find(hashTable, "Example");
   Find(hashTable, "Hello");
   Find(hashTable, "Take Care");
   Find(hashTable, "Good Night");

   cout << endl;


   return 1;
}