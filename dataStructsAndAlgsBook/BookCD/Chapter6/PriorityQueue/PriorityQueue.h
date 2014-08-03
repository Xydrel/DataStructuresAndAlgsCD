/*
   Priority Queue Data Structures in C++
   Chapter 6
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_


#include"LinkList.h"


template<typename T, typename CMP>
class PriorityQueue
{
   public:
      PriorityQueue(int size)
      {
         assert(size > 0);
         m_size = size;
      }


      ~PriorityQueue()
      {

      }


      void push(T val)
      {
         assert(m_elements.GetSize() < m_size);

         if(m_elements.GetSize() == 0)
            {
               m_elements.Push(val);
            }
         else
            {
               LinkIterator<T> it;
               it = m_elements.Begin();

               CMP cmp;

               while(it.isValid())
                  {
                     if(cmp(val, *it))
                        break;

                     it++;
                  }

               if(it.isValid())
                  m_elements.Insert_Before(it, val);
               else
                  m_elements.Push(val);
            }
      }


      void pop()
      {
         m_elements.Pop_Front();
      }


      T& front()
      {
         LinkIterator<T> it;
         it = m_elements.Begin();

         return *it;
      }


      T& back()
      {
         LinkIterator<T> it;
         it = m_elements.Last();

         return *it;
      }

      int GetSize()    { return m_elements.GetSize(); }
      int GetMaxSize() { return m_size; }
      bool isEmpty()   { return (m_elements.GetSize() == 0); }

      void Resize(int size) { assert(size > 0); m_size = size; }


   private:
      LinkList<T> m_elements;
      int m_size;
};

#endif