/*
   Bsp Tree
   Chapter 13
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#ifndef _BSP_TREE_H_
#define _BSP_TREE_H_

#include<stdio.h>
#include"Vector3D.h"
#include"Polygon.h"
#include"Plane.h"


class BspNode
{
   public:
      BspNode() : m_backNode(0), m_frontNode(0),
                  m_polygons(0), m_totalPolygons(0) { }
      ~BspNode() { Shutdown(); }

      bool CreateNode(Polygon *pList, int totalPolys);
      void Shutdown();

      bool isLeafNode()
      {
         return (m_frontNode == NULL) && (m_backNode == NULL);
      }

      int ClassifyPoint(Vector3D pos)
      {
         return m_splitter.ClassifyPoint(pos, NULL);
      }

      BspNode *GetBackNode() { return m_backNode; }
      BspNode *GetFrontNode() { return m_frontNode; }
      Polygon *GetPolygons() { return m_polygons; }
      int GetTotalPolygons() { return m_totalPolygons; }

   private:
      bool FindBestSplitter(Polygon *pList, int totalPolys);

   private:
      BspNode *m_backNode;
      BspNode *m_frontNode;
      Plane m_splitter;

      Polygon *m_polygons;
      int m_totalPolygons;
};

#endif