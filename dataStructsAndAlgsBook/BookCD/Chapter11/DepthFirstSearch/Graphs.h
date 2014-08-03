/*
   Graphs - Depth First Search
   Chapter 11
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#ifndef _GRAPHS_H_
#define _GRAPHS_H_


#include<vector>
#include<stack>
#include<cassert>


using namespace std;


template<typename T>
class GraphVertex
{
   public:
      GraphVertex(T node) : m_node(node) { }

      T GetNode() { return m_node; }

   private:
      T m_node;
};


template<typename T>
class Graph
{
   public:
      Graph(int numVerts) : m_maxVerts(numVerts), m_adjMatrix(NULL)
      {
         assert(numVerts > 0);

         m_vertices.reserve(m_maxVerts);

         m_adjMatrix = new char*[m_maxVerts];
         assert(m_adjMatrix != NULL);

         m_vertVisits = new char[m_maxVerts];
         assert(m_vertVisits != NULL);

         memset(m_vertVisits, 0, m_maxVerts);

         for(int i = 0; i < m_maxVerts; i++)
            {
               m_adjMatrix[i] = new char[m_maxVerts];
               assert(m_adjMatrix[i] != NULL);

               memset(m_adjMatrix[i], 0, m_maxVerts);
            }
      }


      ~Graph()
      {
         if(m_adjMatrix != NULL)
            {
               for(int i = 0; i < m_maxVerts; i++)
                  {
                     if(m_adjMatrix[i] != NULL)
                        {
                           delete[] m_adjMatrix[i];
                           m_adjMatrix[i] = NULL;
                        }
                  }

               delete[] m_adjMatrix;
               m_adjMatrix = NULL;
            }

         if(m_vertVisits != NULL)
            {
               delete[] m_vertVisits;
               m_vertVisits = NULL;
            }
      }


      bool push(T node)
      {
         if((int)m_vertices.size() >= m_maxVerts)
            return false;

         m_vertices.push_back(GraphVertex<T>(node));
         return true;
      }


      void attachEdge(int index1, int index2)
      {
         assert(m_adjMatrix != NULL);

         m_adjMatrix[index1][index2] = 1;
         m_adjMatrix[index2][index1] = 1;
      }


      void attachDirectedEdge(int index1, int index2)
      {
         assert(m_adjMatrix != NULL);

         m_adjMatrix[index1][index2] = 1;
      }


      int getNextUnvisitedVertex(int index)
      {
         assert(m_adjMatrix != NULL);
         assert(m_vertVisits != NULL);

         for(int i = 0; i < (int)m_vertices.size(); i++)
            {
               if(m_adjMatrix[index][i] == 1 &&
                  m_vertVisits[i] == 0)
                  {
                     return i;
                  }
            }

         return -1;
      }


      bool DepthFirstSearch(int startIndex, int endIndex)
      {
         assert(m_adjMatrix != NULL);
         assert(m_vertVisits != NULL);

         m_vertVisits[startIndex] = 1;

         // FOR OUTPUT PURPOSES OF THE DEMOS.
         cout << m_vertices[startIndex].GetNode();

         stack<int> searchStack;
         int vert = 0;

         searchStack.push(startIndex);

         while(searchStack.empty() != true)
            {
               vert = getNextUnvisitedVertex(searchStack.top());

               if(vert == -1)
                  {
                     searchStack.pop();
                  }
               else
                  {
                     m_vertVisits[vert] = 1;

                     // FOR OUTPUT PURPOSES OF THE DEMOS.
                     cout << m_vertices[vert].GetNode();

                     searchStack.push(vert);
                  }

               if(vert == endIndex)
                  {
                     memset(m_vertVisits, 0, m_maxVerts);
                     return true;
                  }
            }

         memset(m_vertVisits, 0, m_maxVerts);

         return false;
      }


   private:
      vector<GraphVertex<T> > m_vertices;
      int m_maxVerts;

      char **m_adjMatrix;
      char *m_vertVisits;
};

#endif