/*
   Stacks implemented with LinkList in C++
   Chapter 6
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#ifndef _STACK_H_
#define _STACK_H_


#include"LinkList.h"


template<typename T>
class Stack
{
   public:
      Stack()  { }
      ~Stack() { }


      void push(T val)
      {
         m_container.Push(val);
      }


      void pop()
      {
         m_container.Pop();
      }


      const T& top()
      {
         LinkIterator<T> it;
         it = m_container.Last();
         return *it;
      }


      int GetSize()  { return m_container.GetSize(); }
      bool isEmpty() { return (m_container.GetSize() == 0); }


   private:
      LinkList<T> m_container;
      int m_size;
};

#endif