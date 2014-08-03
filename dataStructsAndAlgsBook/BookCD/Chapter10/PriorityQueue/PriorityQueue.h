/*
   Heap used in a Priority Queue
   Chapter 10
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_


#include"Heap.h"


template<typename T, typename CMP>
class PriorityQueue
{
   public:
      PriorityQueue()
      {
      }


      void push(T val)
      {
         m_elements.push(val);
      }


      void pop()
      {
         m_elements.pop();
      }


      T peek()
      {
         return m_elements.peek();
      }


      int size()
      {
         return m_elements.size();
      }


      bool empty()
      {
         return (m_elements.size() == 0);
      }


   private:
      Heap<T, CMP> m_elements;
};

#endif