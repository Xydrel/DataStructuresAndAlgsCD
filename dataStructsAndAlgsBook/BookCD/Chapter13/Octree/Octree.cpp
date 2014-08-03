/*
   Octree
   Chapter 13
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<string.h>
#include"Octree.h"


int g_level = 0;
int g_maxLevel = 0;
int g_maxTris = 0;


OctreeNode::OctreeNode() : m_vertices(0), m_numVerts(0)
{
   for(int i = 0; i < 8; i++)
      m_subNodes[i] = NULL;
}


OctreeNode::~OctreeNode()
{
   Shutdown();
}


bool OctreeNode::Initialize(Vector3D *vertexList, int numVerts,
                            int maxLevels, int maxTris)
{
   g_maxLevel = maxLevels;
   g_maxTris = maxTris;
   m_aabb.Calculate(vertexList, numVerts);
   CreateNode(vertexList, numVerts);

   return true;
}


void OctreeNode::CreateNode(Vector3D *vertexList, int numVerts)
{
   if(vertexList == NULL)
      return;

   if((numVerts / 3) <= g_maxTris || g_level >= g_maxLevel)
      {
         m_numVerts = numVerts;
         m_vertices = new Vector3D[numVerts];
         memcpy(m_vertices, vertexList, sizeof(Vector3D) * numVerts);
      }
   else
      {
         int tflIndex = 0, tfrIndex = 0, tblIndex = 0, tbrIndex = 0,
             bflIndex = 0, bfrIndex = 0, bblIndex = 0, bbrIndex = 0;

         Vector3D *vlTopFrontLeft     = new Vector3D[numVerts];
         Vector3D *vlTopFrontRight    = new Vector3D[numVerts];
         Vector3D *vlTopBackLeft      = new Vector3D[numVerts];
         Vector3D *vlTopBackRight     = new Vector3D[numVerts];
         Vector3D *vlBottomFrontLeft  = new Vector3D[numVerts];
         Vector3D *vlBottomFrontRight = new Vector3D[numVerts];
         Vector3D *vlBottomBackLeft   = new Vector3D[numVerts];
         Vector3D *vlBottomBackRight  = new Vector3D[numVerts];

         // Loop through and find which triangles fall in which node.
         // A better method would be to clip polygons to the boxes
         // instead of placing potentially duplicate polygons in all
         // boxes they happen to fall in (span).

         // Loop for each polygon (which is ever 3 verts in this demo.
         for(int i = 0; i < numVerts; i += 3)
            {
               if(isInTopFrontLeft(vertexList[i], vertexList[i+1],
                  vertexList[i+2], m_aabb.m_center))
                  {
                     vlTopFrontLeft[tflIndex++] = vertexList[i];
                     vlTopFrontLeft[tflIndex++] = vertexList[i + 1];
                     vlTopFrontLeft[tflIndex++] = vertexList[i + 2];
                  }

               if(isInTopFrontRight(vertexList[i], vertexList[i+1],
                  vertexList[i+2], m_aabb.m_center))
                  {
                     vlTopFrontRight[tfrIndex++] = vertexList[i];
                     vlTopFrontRight[tfrIndex++] = vertexList[i + 1];
                     vlTopFrontRight[tfrIndex++] = vertexList[i + 2];
                  }

               if(isInTopBackLeft(vertexList[i], vertexList[i+1],
                  vertexList[i+2], m_aabb.m_center))
                  {
                     vlTopBackLeft[tblIndex++] = vertexList[i];
                     vlTopBackLeft[tblIndex++] = vertexList[i + 1];
                     vlTopBackLeft[tblIndex++] = vertexList[i + 2];
                  }

               if(isInTopBackRight(vertexList[i], vertexList[i+1],
                  vertexList[i+2], m_aabb.m_center))
                  {
                     vlTopBackRight[tbrIndex++] = vertexList[i];
                     vlTopBackRight[tbrIndex++] = vertexList[i + 1];
                     vlTopBackRight[tbrIndex++] = vertexList[i + 2];
                  }

               if(isInBottomFrontLeft(vertexList[i], vertexList[i+1],
                  vertexList[i+2], m_aabb.m_center))
                  {
                     vlBottomFrontLeft[bflIndex++] = vertexList[i];
                     vlBottomFrontLeft[bflIndex++] = vertexList[i + 1];
                     vlBottomFrontLeft[bflIndex++] = vertexList[i + 2];
                  }

               if(isInBottomFrontRight(vertexList[i], vertexList[i+1],
                  vertexList[i+2], m_aabb.m_center))
                  {
                     vlBottomFrontRight[bfrIndex++] = vertexList[i];
                     vlBottomFrontRight[bfrIndex++] = vertexList[i + 1];
                     vlBottomFrontRight[bfrIndex++] = vertexList[i + 2];
                  }

               if(isInBottomBackLeft(vertexList[i], vertexList[i+1],
                  vertexList[i+2], m_aabb.m_center))
                  {
                     vlBottomBackLeft[bblIndex++] = vertexList[i];
                     vlBottomBackLeft[bblIndex++] = vertexList[i + 1];
                     vlBottomBackLeft[bblIndex++] = vertexList[i + 2];
                  }

               if(isInBottomBackRight(vertexList[i], vertexList[i+1],
                  vertexList[i+2], m_aabb.m_center))
                  {
                     vlBottomBackRight[bbrIndex++] = vertexList[i];
                     vlBottomBackRight[bbrIndex++] = vertexList[i + 1];
                     vlBottomBackRight[bbrIndex++] = vertexList[i + 2];
                  }
            }

         // Create each sub node.
         CreateLeafNode(vlTopFrontLeft,     tflIndex, TOP_FRONT_LEFT);
         CreateLeafNode(vlTopFrontRight,    tfrIndex, TOP_FRONT_RIGHT);
         CreateLeafNode(vlTopBackLeft,      tblIndex, TOP_BACK_LEFT);
         CreateLeafNode(vlTopBackRight,     tbrIndex, TOP_BACK_RIGHT);
         CreateLeafNode(vlBottomFrontLeft,  bflIndex, BOTTOM_FRONT_LEFT);
         CreateLeafNode(vlBottomFrontRight, bfrIndex, BOTTOM_FRONT_RIGHT);
         CreateLeafNode(vlBottomBackLeft,   bblIndex, BOTTOM_BACK_LEFT);
         CreateLeafNode(vlBottomBackRight,  bbrIndex, BOTTOM_BACK_RIGHT);

         // Free temp data.
         delete[] vlTopFrontLeft;
         delete[] vlTopFrontRight;
         delete[] vlTopBackLeft;
         delete[] vlTopBackRight;
         delete[] vlBottomFrontLeft;
         delete[] vlBottomFrontRight;
         delete[] vlBottomBackLeft;
         delete[] vlBottomBackRight;
      }
}


void OctreeNode::CreateLeafNode(Vector3D *vList, int numVerts, int nodeId)
{

   if(vList == NULL || numVerts <= 0)
      return;

   // Allocate this sub node.
   m_subNodes[nodeId] = new OctreeNode();
   g_level++;

   float size = fabs(m_aabb.m_max.x - m_aabb.m_center.x);
   Vector3D center = GetNodeCenter(m_aabb.m_center, size * 2, nodeId);

   // Calculate aabb based on parent aabb, not geometry.
   m_subNodes[nodeId]->m_aabb.m_center = center;
   m_subNodes[nodeId]->m_aabb.m_min = center - size / 2;
   m_subNodes[nodeId]->m_aabb.m_max = center + size / 2;

   // Recursively keep going down the tree.
   m_subNodes[nodeId]->CreateNode(vList, numVerts);

   g_level--;
}


Vector3D OctreeNode::GetNodeCenter(Vector3D &center, float size, int nodeId)
{
   Vector3D newCenter;

   switch(nodeId)
      {
         case TOP_FRONT_LEFT:
            newCenter.x = center.x - size / 4;
            newCenter.y = center.y + size / 4;
            newCenter.z = center.z + size / 4;
            break;

         case TOP_FRONT_RIGHT:
            newCenter.x = center.x + size / 4;
            newCenter.y = center.y + size / 4;
            newCenter.z = center.z + size / 4;
            break;

         case TOP_BACK_LEFT:
            newCenter.x = center.x - size / 4;
            newCenter.y = center.y + size / 4;
            newCenter.z = center.z - size / 4;
            break;

         case TOP_BACK_RIGHT:
            newCenter.x = center.x + size / 4;
            newCenter.y = center.y + size / 4;
            newCenter.z = center.z - size / 4;
            break;

         case BOTTOM_FRONT_LEFT:
            newCenter.x = center.x - size / 4;
            newCenter.y = center.y - size / 4;
            newCenter.z = center.z + size / 4;
            break;

         case BOTTOM_FRONT_RIGHT:
            newCenter.x = center.x + size / 4;
            newCenter.y = center.y - size / 4;
            newCenter.z = center.z + size / 4;
            break;

         case BOTTOM_BACK_LEFT:
            newCenter.x = center.x - size / 4;
            newCenter.y = center.y - size / 4;
            newCenter.z = center.z - size / 4;
            break;

         case BOTTOM_BACK_RIGHT:
            newCenter.x = center.x + size / 4;
            newCenter.y = center.y - size / 4;
            newCenter.z = center.z - size / 4;
            break;
      }

   return newCenter;
}



void OctreeNode::Shutdown()
{
   if(m_vertices != NULL)
      {
         delete[] m_vertices;
         m_vertices = NULL;
      }

   for(int i = 0; i < 8; i++)
      {
         if(m_subNodes[i] != NULL)
            {
               m_subNodes[i]->Shutdown();
               delete m_subNodes[i];
               m_subNodes[i] = NULL;
            }
      }
}


bool isInTopFrontLeft(Vector3D &v1, Vector3D &v2,
                      Vector3D &v3, Vector3D &center)
{
   if((v1.x <= center.x) && (v1.y >= center.y) && (v1.z >= center.z))
      return true;
   else if((v2.x <= center.x) && (v2.y >= center.y) && (v2.z >= center.z))
      return true;
   else if((v3.x <= center.x) && (v3.y >= center.y) && (v3.z >= center.z))
      return true;

   return false;
}


bool isInTopFrontRight(Vector3D &v1, Vector3D &v2,
                       Vector3D &v3, Vector3D &center)
{
   if((v1.x >= center.x) && (v1.y >= center.y) && (v1.z >= center.z))
      return true;
   else if((v2.x >= center.x) && (v2.y >= center.y) && (v2.z >= center.z))
      return true;
   else if((v3.x >= center.x) && (v3.y >= center.y) && (v3.z >= center.z))
      return true;

   return false;
}


bool isInTopBackLeft(Vector3D &v1, Vector3D &v2,
                     Vector3D &v3, Vector3D &center)
{
   if((v1.x <= center.x) && (v1.y >= center.y) && (v1.z <= center.z))
      return true;
   else if((v2.x <= center.x) && (v2.y >= center.y) && (v2.z <= center.z))
      return true;
   else if((v3.x <= center.x) && (v3.y >= center.y) && (v3.z <= center.z))
      return true;

   return false;
}


bool isInTopBackRight(Vector3D &v1, Vector3D &v2,
                      Vector3D &v3, Vector3D &center)
{
   if((v1.x >= center.x) && (v1.y >= center.y) && (v1.z <= center.z))
      return true;
   else if((v2.x >= center.x) && (v2.y >= center.y) && (v2.z <= center.z))
      return true;
   else if((v3.x >= center.x) && (v3.y >= center.y) && (v3.z <= center.z))
      return true;

   return false;
}


bool isInBottomFrontLeft(Vector3D &v1, Vector3D &v2,
                         Vector3D &v3, Vector3D &center)
{
   if((v1.x <= center.x) && (v1.y <= center.y) && (v1.z >= center.z))
      return true;
   else if((v2.x <= center.x) && (v2.y <= center.y) && (v2.z >= center.z))
      return true;
   else if((v3.x <= center.x) && (v3.y <= center.y) && (v3.z >= center.z))
      return true;

   return false;
}


bool isInBottomFrontRight(Vector3D &v1, Vector3D &v2,
                          Vector3D &v3, Vector3D &center)
{
   if((v1.x >= center.x) && (v1.y <= center.y) && (v1.z >= center.z))
      return true;
   else if((v2.x >= center.x) && (v2.y <= center.y) && (v2.z >= center.z))
      return true;
   else if((v3.x >= center.x) && (v3.y <= center.y) && (v3.z >= center.z))
      return true;

   return false;
}


bool isInBottomBackLeft(Vector3D &v1, Vector3D &v2,
                        Vector3D &v3, Vector3D &center)
{
   if((v1.x <= center.x) && (v1.y <= center.y) && (v1.z <= center.z))
      return true;
   else if((v2.x <= center.x) && (v2.y <= center.y) && (v2.z <= center.z))
      return true;
   else if((v3.x <= center.x) && (v3.y <= center.y) && (v3.z <= center.z))
      return true;

   return false;
}


bool isInBottomBackRight(Vector3D &v1, Vector3D &v2,
                         Vector3D &v3, Vector3D &center)
{
   if((v1.x >= center.x) && (v1.y <= center.y) && (v1.z <= center.z))
      return true;
   else if((v2.x >= center.x) && (v2.y <= center.y) && (v2.z <= center.z))
      return true;
   else if((v3.x >= center.x) && (v3.y <= center.y) && (v3.z <= center.z))
      return true;

   return false;
}