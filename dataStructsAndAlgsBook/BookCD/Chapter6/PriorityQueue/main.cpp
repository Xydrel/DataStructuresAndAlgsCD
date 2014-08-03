/*
   Priority Queue Data Structures in C++
   Chapter 6
   Data Structures for Game Developers
   Created by Allen Sherrod
*/



#include<iostream>
#include"PriorityQueue.h"

using namespace std;


template<typename T>
class less_cmp
{
   public:
      inline bool operator()(T lVal, T rVal)
      {
         return (lVal < rVal);
      }
};


template<typename T>
class less_cmp_ptr
{
   public:
      inline bool operator()(T lVal, T rVal)
      {
         return ((*lVal) < (*rVal));
      }
};


template<typename T>
class greater_cmp
{
   public:
      inline bool operator()(T lVal, T rVal)
      {
         return !(lVal < rVal);
      }
};


template<typename T>
class greater_cmp_ptr
{
   public:
      inline bool operator()(T lVal, T rVal)
      {
         return !((*lVal) < (*rVal));
      }
};


class NetworkMessage
{
   public:
      NetworkMessage() : m_priority(0), m_id(0) { }
      NetworkMessage(int p, int id) : m_priority(p), m_id(id) { }
      ~NetworkMessage() { }


      int GetPriority() { return m_priority; }
      int GetID()       { return m_id; }


      bool operator<(NetworkMessage &m)
      {
         if(m_priority < m.GetPriority())
            return true;
         else if(m_id < m.GetID())
            return true;

         return false;
      }

      bool operator>(NetworkMessage &m)
      {
         return !(*this < m);
      }


   private:
      int m_priority, m_id;
};


int main(int args, char **argc)
{
   cout << "Priority Queue Data Structures Example" << endl;
   cout << "Chapter 6: Stacks and Queues" << endl;
   cout << endl;


   // Create and populate queue.
   const int size = 4;
   PriorityQueue<NetworkMessage,
                 less_cmp<NetworkMessage> > que(size);

   que.push(NetworkMessage(3, 100));
   que.push(NetworkMessage(2, 286));
   que.push(NetworkMessage(1, 362));
   que.push(NetworkMessage(3, 435));


   // Display integer queue.
   cout << "Priority Queue Contents (Size - "
        << que.GetSize() << ") :" << endl;

   while(que.isEmpty() == false)
      {
         cout << "   Priority: " << que.front().GetPriority();
         cout << " - ID: "       << que.front().GetID();
         cout << endl;

         que.pop();
      }

   cout << endl;


   // Calling isEmpty() to test if container is empty.
   if(que.isEmpty() == true)
      cout << "The container is empty." << endl << endl;
   else
      cout << "The container is NOT empty." << endl << endl;

   return 1;
}