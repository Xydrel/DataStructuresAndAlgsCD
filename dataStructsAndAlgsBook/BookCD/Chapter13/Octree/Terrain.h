/*
   Octree
   Chapter 13
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#ifndef _TERRAIN_H_
#define _TERRAIN_H_

#include"Octree.h"


class Terrain
{
   public:
      Terrain();
      ~Terrain();

      bool LoadMap(char *filename);
      void ShutDown();

      OctreeNode *GetRoot() { return m_rootNode; }


   private:
      OctreeNode *m_rootNode;
};

#endif