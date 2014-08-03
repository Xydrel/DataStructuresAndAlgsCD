/*
   STL Priority Queue 2 in C++
   Chapter 6
   Data Structures for Game Developers
   Created by Allen Sherrod
*/



#include<iostream>
#include<queue>
#include<vector>

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
      NetworkMessage(int data) : m_data(data) { }
      ~NetworkMessage() { }


      bool operator<(NetworkMessage &obj)
      {
         return (m_data < obj.GetData());
      }


      bool operator>(NetworkMessage &obj)
      {
         return !(m_data < obj.GetData());
      }


      int GetData() const
      {
         return m_data;
      }

   private:
      int m_data;
};


int main(int args, char **argc)
{
   cout << "STL Priority Queue 2 Example" << endl;
   cout << "Chapter 6: Stacks and Queues" << endl;
   cout << endl;


   // Create two test priority queues.
   priority_queue<NetworkMessage, vector<NetworkMessage>,
                  less_cmp<NetworkMessage> > priQueue;

   priority_queue<NetworkMessage*, vector<NetworkMessage*>,
                  greater_cmp_ptr<NetworkMessage*> > priQueuePtr;

   priQueue.push(NetworkMessage(5));
   priQueue.push(NetworkMessage(35));
   priQueue.push(NetworkMessage(2));
   priQueue.push(NetworkMessage(53));

   priQueuePtr.push(new NetworkMessage(14));
   priQueuePtr.push(new NetworkMessage(67));
   priQueuePtr.push(new NetworkMessage(13));
   priQueuePtr.push(new NetworkMessage(12));


   // Display priority queue.
   cout << "Priority Queue Contents:" << endl;

   int size = (int)priQueue.size();

   for(int i = 0; i < size; i++)
      {
         cout << "   " << priQueue.top().GetData() << endl;
         priQueue.pop();
      }

   cout << endl;


   // Display priority queue ptr.
   cout << "Priority Queue PTR Contents:" << endl;

   size = (int)priQueuePtr.size();

   for(int i = 0; i < size; i++)
      {
         NetworkMessage *ptr = priQueuePtr.top();

         if(ptr != NULL)
            {
               cout << "   " << ptr->GetData();
               delete ptr;
               cout << " (deleted)" << endl;
            }

         priQueuePtr.pop();
      }

   cout << endl << endl;

   return 1;
}