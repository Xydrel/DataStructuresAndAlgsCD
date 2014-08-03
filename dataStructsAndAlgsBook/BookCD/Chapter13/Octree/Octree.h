/*
   Octree
   Chapter 13
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#ifndef _OCTREE_H_
#define _OCTREE_H_

#include<stdio.h>
#include"BoundingBox.h"


enum NODE_ID
{
   TOP_FRONT_LEFT = 0, TOP_FRONT_RIGHT,
   TOP_BACK_LEFT,      TOP_BACK_RIGHT,
   BOTTOM_FRONT_LEFT,  BOTTOM_FRONT_RIGHT,
   BOTTOM_BACK_LEFT,   BOTTOM_BACK_RIGHT
};


class OctreeNode
{
   public:
      OctreeNode();
      ~OctreeNode();

      bool Initialize(Vector3D*, int, int, int);
      void Shutdown();

      bool isLeaf() { return (m_vertices != NULL); }
      BoundingBox GetBoundingBox() { return m_aabb; }
      Vector3D *GetVertices() { return m_vertices; }
      int GetTotalVertices() { return m_numVerts; }

      OctreeNode **GetSubNodes() { return m_subNodes; }


   private:
      void CreateNode(Vector3D*, int);
      void CreateLeafNode(Vector3D*, int, int);
      Vector3D GetNodeCenter(Vector3D&, float, int);


   private:
      BoundingBox m_aabb;
      Vector3D *m_vertices;
      int m_numVerts;
      OctreeNode *m_subNodes[8];
};


bool isInTopFrontLeft(Vector3D&, Vector3D&, Vector3D&, Vector3D &);
bool isInTopFrontRight(Vector3D &, Vector3D &, Vector3D &, Vector3D &);
bool isInTopBackLeft(Vector3D &, Vector3D &, Vector3D &, Vector3D &);
bool isInTopBackRight(Vector3D &, Vector3D &, Vector3D &, Vector3D &);
bool isInBottomFrontLeft(Vector3D &, Vector3D &, Vector3D &, Vector3D &);
bool isInBottomFrontRight(Vector3D &, Vector3D &, Vector3D &, Vector3D &);
bool isInBottomBackLeft(Vector3D &, Vector3D &, Vector3D &, Vector3D &);
bool isInBottomBackRight(Vector3D &, Vector3D &, Vector3D &, Vector3D &);

#endif