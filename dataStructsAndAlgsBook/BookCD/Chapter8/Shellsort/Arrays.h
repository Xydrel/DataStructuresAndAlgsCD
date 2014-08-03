/*
   The Shellsort Algorithm
   Chapter 8
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<cassert>


#ifndef _ARRAYS_H_
#define _ARRAYS_H_


template<typename T>
class UnorderedArray
{
   public:
      UnorderedArray(int m_numElements, int growBy = 1) :
                     m_array(NULL), m_maxSize(0),
                     m_growSize(0), m_numElements(0)
      {
         if(m_numElements)
            {
               m_maxSize = m_numElements;
               m_array = new T[m_maxSize];
               memset(m_array, 0, sizeof(T) * m_maxSize);

               m_growSize = ((growBy > 0) ? growBy : 0);
            }
      }


      ~UnorderedArray()
      {
         if(m_array != NULL)
            {
               delete[] m_array;
               m_array = NULL;
            }
      }


      void push(T val)
      {
         assert(m_array != NULL);

         if(m_numElements >= m_maxSize)
            {
               Expand();
            }

         m_array[m_numElements] = val;
         m_numElements++;
      }


      void pop()
      {
         if(m_numElements > 0)
            m_numElements--;
      }


      void remove(int index)
      {
         assert(m_array != NULL);

         if(index >= m_maxSize)
            {
               return;
            }

         for(int k = index; k < m_maxSize - 1; k++)
            m_array[k] = m_array[k + 1];
      
         m_maxSize--;

         if(m_numElements >= m_maxSize)
            m_numElements = m_maxSize - 1;
      }


      T& operator[](int index)
      {
         assert(m_array != NULL && index <= m_numElements);
         return m_array[index];
      }


      int search(T val)
      {
         assert(m_array != NULL);

         for(int i = 0; i < m_numElements; i++)
            {
               if(m_array[i] == val)
                  return i;
            }

         return -1;
      }


      void Shellsort()
      {
         assert(m_array != NULL);

         T temp;
         int i = 0, k = 0;

         // Sequence...
         int seq = 1;

         while(seq <= m_numElements / 3)
            seq = seq * 3 + 1;

         while(seq > 0)
            {
               for(k = seq; k < m_numElements; k++)
                  {
                     temp = m_array[k];
                     i = k;

                     while(i > seq - 1 && m_array[i - seq] >= temp)
                        {
                           m_array[i] = m_array[i - seq];
                           i -= seq;
                        }

                     m_array[i] = temp;
                  }

               seq = (seq - 1) / 3;
            }
      }


      void clear()      { m_numElements = 0; }
      int GetSize()     { return m_numElements; }
      int GetMaxSize()  { return m_maxSize; }
      int GetGrowSize() { return m_growSize; }

      void SetGrowSize(int val)
      {
         assert(val >= 0);
         m_growSize = val;
      }


   private:
      bool Expand()
      {
         if(m_growSize <= 0)
            return false;

         T *temp = new T[m_maxSize + m_growSize];
         assert(temp != NULL);

         memcpy(temp, m_array, sizeof(T) * m_maxSize);

         delete[] m_array;
         m_array = temp;

         m_maxSize += m_growSize;

         return true;
      }


   private:
      T *m_array;

      int m_maxSize;
      int m_growSize;
      int m_numElements;
};


#endif