/*
   The Median-Of-Three Quicksort Algorithm
   Chapter 8
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<cassert>


#ifndef _ARRAYS_H_
#define _ARRAYS_H_


#define QUICKSORT_CUTOFF   4


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


      void clear()      { m_numElements = 0; }
      int GetSize()     { return m_numElements; }
      int GetMaxSize()  { return m_maxSize; }
      int GetGrowSize() { return m_growSize; }

      void SetGrowSize(int val)
      {
         assert(val >= 0);
         m_growSize = val;
      }


      void InsertionSort()
      {
         InsertionSort(0, m_numElements - 1);
      }


      void SwapElements(int index1, int index2)
      {
         assert(index1 >= 0 && index1 < m_numElements);
         assert(index2 >= 0 && index2 < m_numElements);
         assert(m_array != NULL);

         T temp = m_array[index1];
         m_array[index1] = m_array[index2];
         m_array[index2] = temp;
      }


      void Quicksort()
      {
         QuickSort(0, m_numElements - 1);
      }


   private:
      void QuickSort(int lVal, int rVal)
      {
         if((rVal - lVal + 1) < QUICKSORT_CUTOFF)
            {
               InsertionSort(lVal, rVal);
               return;
            }

         int center = (lVal + rVal) / 2;

         if(m_array[lVal] > m_array[center])
            SwapElements(lVal, center);

         if(m_array[lVal] > m_array[rVal])
            SwapElements(lVal, rVal);

         if(m_array[center] > m_array[rVal])
            SwapElements(center, rVal);

         int pivotIndex = Partition(lVal, rVal, center);

         QuickSort(lVal, pivotIndex - 1);
         QuickSort(pivotIndex, rVal);
      }


      int Partition(int lIndex, int rIndex, int pivot)
      {
         while(1)
            {
               while(m_array[++lIndex] < m_array[pivot]);
               while(m_array[--rIndex] > m_array[pivot]);

               if(lIndex >= rIndex)
                  break;

               SwapElements(lIndex, rIndex);
            }

         // Returns position of the pivot.
         return lIndex;
      }


      void InsertionSort(int lVal, int rVal)
      {
         assert(m_array != NULL);

         T temp;
         int i = 0;

         for(int k = lVal + 1; k <= rVal; k++)
            {
               temp = m_array[k];
               i = k;

               while(i > lVal && m_array[i - 1] >= temp)
                  {
                     m_array[i] = m_array[i - 1];
                     i--;
                  }

               m_array[i] = temp;
            }
      }


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