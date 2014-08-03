/*
   Stacks implemented with UnorderedArray in C++
   Chapter 6
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#ifndef _STACK_H_
#define _STACK_H_


#include"Arrays.h"


template<typename T>
class Stack
{
   public:
      Stack(int size, int growBy = 1)
      {
         assert(size > 0 && growBy >= 0);

         m_container = new UnorderedArray<T>(size, growBy);
         assert(m_container != NULL);
      }


      ~Stack()
      {
         if(m_container != NULL)
            {
               delete m_container;
               m_container = NULL;
            }
      }


      void push(T val)
      {
         assert(m_container != NULL);
         m_container->push(val);
      }


      void pop()
      {
         assert(m_container != NULL);
         m_container->pop();
      }


      const T& top()
      {
         assert(m_container != NULL);
         return (*m_container)[m_container->GetSize() - 1];
      }

      int GetSize()
      {
         assert(m_container != NULL);
         return m_container->GetSize();
      }

      int GetMaxSize()
      {
         assert(m_container != NULL);
         return m_container->GetMaxSize();
      }

      bool isEmpty()
      {
         assert(m_container != NULL);
         return (m_container->GetSize() == 0);
      }


   private:
      UnorderedArray<T> *m_container;
};

#endif