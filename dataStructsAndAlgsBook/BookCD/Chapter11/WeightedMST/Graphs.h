/*
   Graphs - Weighted Minimum Spanning Trees
   Chapter 11
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#ifndef _GRAPHS_H_
#define _GRAPHS_H_


#include<vector>
#include<string>
#include<cassert>
#include<algorithm>


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


class EdgeInfo
{
   public:
      EdgeInfo() : m_v1Index(0), m_v2Index(0), m_weight(0) {}

      bool operator<(const EdgeInfo &e2) const
      {
         return (m_weight < e2.m_weight);
      }


      bool operator==(const EdgeInfo &e2) const
      {
         return (m_v2Index == e2.m_v2Index);
      }


      int m_v1Index, m_v2Index;
      int m_weight;
};


template<typename T>
class Graph
{
   public:
      Graph(int numVerts) : m_maxVerts(numVerts), m_adjMatrix(NULL)
      {
         assert(numVerts > 0);

         m_vertices.reserve(m_maxVerts);

         m_adjMatrix = new int*[m_maxVerts];
         assert(m_adjMatrix != NULL);

         m_vertVisits = new char[m_maxVerts];
         assert(m_vertVisits != NULL);

         memset(m_vertVisits, 0, m_maxVerts);

         for(int i = 0; i < m_maxVerts; i++)
            {
               m_adjMatrix[i] = new int[m_maxVerts];
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


      void attachEdge(int index1, int index2, int weight)
      {
         assert(m_adjMatrix != NULL);

         m_adjMatrix[index1][index2] = weight;
         m_adjMatrix[index2][index1] = weight;
      }


      void attachDirectedEdge(int index1, int index2, int weight)
      {
         assert(m_adjMatrix != NULL);

         m_adjMatrix[index1][index2] = weight;
      }


      void DisplayMST(string &output)
      {
         assert(m_adjMatrix != NULL);
         assert(m_vertVisits != NULL);

         int currentVert = 0, totalChecked = 0;
         int size = (int)m_vertices.size();

         vector<EdgeInfo> vList;

         while(totalChecked < size - 1)
            {
               m_vertVisits[currentVert] = 1;
               totalChecked++;

               for(int i = 0; i < size; i++)
                  {
                     if(i == currentVert || m_vertVisits[i] == 1 ||
                        m_adjMatrix[currentVert][i] == 0)
                        continue;

                     EdgeInfo edge;
                     edge.m_v1Index = currentVert;
                     edge.m_v2Index = i;
                     edge.m_weight = m_adjMatrix[currentVert][i];

                     vector<EdgeInfo>::iterator it = find(vList.begin(),
                                                          vList.end(),
                                                          edge);

                     if(it == vList.end())
                        {
                           vList.push_back(edge);
                        }
                     else
                        {
                           if(edge.m_weight <= (*it).m_weight)
                              {
                                 (*it).m_v1Index = edge.m_v1Index;
                                 (*it).m_v2Index = edge.m_v2Index;
                                 (*it).m_weight = edge.m_weight;
                              }
                        }
                  }

               if(vList.empty() == true)
                  {
                     output = "Error: Graph is not connected.";
                     return;
                  }

               // Orders from greatest to least.
               // Since we have to sort anyhow lets put the
               // min at the end so pop_back() is fast.
               sort(vList.rbegin(), vList.rend());

               int endIndex = (int)vList.size() - 1;
               int v1 = vList[endIndex].m_v1Index;
               currentVert = vList[endIndex].m_v2Index;

               // For demo output.
               output += m_vertices[v1].GetNode();
               output += ":";
               output += m_vertices[currentVert].GetNode();
               output += " ";

               // Remove minimum, which was placed at the back.
               vList.pop_back();
            }

         memset(m_vertVisits, 0, m_maxVerts);
      }


   private:
      vector<GraphVertex<T> > m_vertices;
      int m_maxVerts;

      int **m_adjMatrix;
      char *m_vertVisits;
};

#endif