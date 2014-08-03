/*
   Bsp Tree
   Chapter 13
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<string.h>
#include"BspTree.h"


void BspNode::Shutdown()
{
   if(m_backNode)
      {
         m_backNode->Shutdown();
         delete m_backNode;
         m_backNode = NULL;
      }

   if(m_frontNode)
      {
         m_frontNode->Shutdown();
         delete m_frontNode;
         m_frontNode = NULL;
      }

   if(m_polygons)
      {
         delete[] m_polygons;
         m_polygons = NULL;
      }
}


bool BspNode::CreateNode(Polygon *pList, int totalPolys)
{
   Polygon *fList, *bList;
   int i = 0;
   int frontPolys = 0, backPolys = 0;
   int fIndex = 0, bIndex = 0;

   if(pList == NULL || totalPolys <= 0)
      return false;

   // If a plane can't be determined, make leaf node.
   if(FindBestSplitter(pList, totalPolys) == false)
      {
         m_polygons = new Polygon[totalPolys];

         if(!m_polygons)
            return false;

         m_totalPolygons = totalPolys;
         memcpy(m_polygons, pList, sizeof(Polygon) * totalPolys);
         return true;
      }

   // Separate polygons from front and back.
   for(i = 0; i < totalPolys; i++)
      {
         // Determine where this polygon lies.
         int result = m_splitter.ClassifyTri(pList[i].vertices[0],
                                             pList[i].vertices[1],
                                             pList[i].vertices[2]);

         if(result == PLANE_FRONT)
            {
               frontPolys++;
            }
         else if(result == PLANE_BACK)
            {
               backPolys++;
            }
         else if(result == PLANE_CLIPPED)
            {
               frontPolys++;
               backPolys++;
            }
         else if(result == PLANE_ON)
            {
               // Figure out which side is the best out of the 2.
               Plane pl;

               pl.Create(pList[i].vertices[0],
                         pList[i].vertices[1],
                         pList[i].vertices[2]);

               float dp = m_splitter.a * pl.a + m_splitter.b * pl.b +
                          m_splitter.c * pl.c;

               if(dp >= 0.0f)
                  frontPolys++;
               else
                  backPolys++;
            }
      }

   // Now that we know the size of each list, create them.
   if(frontPolys)
      fList = new Polygon[frontPolys];

   if(backPolys)
      bList = new Polygon[backPolys];

   if(fList == NULL || bList == NULL)
      return false;

   // Loop again to separate.
   for(i = 0; i < totalPolys; i++)
      {
         int result = m_splitter.ClassifyTri(pList[i].vertices[0],
                                             pList[i].vertices[1],
                                             pList[i].vertices[2]);

         if(result == PLANE_FRONT)
            {
               fList[fIndex++] = pList[i];
            }
         else if(result == PLANE_BACK)
            {
               bList[bIndex++] = pList[i];
            }
         else if(result == PLANE_CLIPPED)
            {
               // If this poly splits the plane break it into two new polys.
               pList[i].ClipPolygon(m_splitter, &fList[fIndex++], &bList[bIndex++]);
            }
         else if(result == PLANE_ON)
            {
               Plane pl;

               pl.Create(pList[i].vertices[0],
                         pList[i].vertices[1],
                         pList[i].vertices[2]);

               float dp = m_splitter.a * pl.a + m_splitter.b * pl.b +
                          m_splitter.c * pl.c;

               if(dp >= 0.0f)
                  fList[fIndex++] = pList[i];
               else
                  bList[bIndex++] = pList[i];
            }
      }

   // Create the back and front nodes
   m_backNode = new BspNode();
   m_frontNode = new BspNode();

   if(m_backNode == NULL || m_frontNode == NULL)
      return false;

   // Recursively build.
   if(!m_backNode->CreateNode(bList, backPolys))
      return false;

   if(!m_frontNode->CreateNode(fList, frontPolys))
      return false;

   delete[] fList;
   delete[] bList;

   return true;
}


bool BspNode::FindBestSplitter(Polygon *pList, int totalPolys)
{
   Polygon *bestSplit = NULL;
   Plane plane;
   int bCount, fCount, pCount, sCount;
   long score, topScore = 1000000;

   // Loop through all polygons to find the best.
   for(int i = 0; i < totalPolys; i++)
      {
         // Don't look at polys already used as planes.
         if(pList[i].flag == 1)
            continue;

         // Create a temp plane out of this polygon.
         plane.Create(pList[i].vertices[0],
                      pList[i].vertices[1],
                      pList[i].vertices[2]);

         // Back, front, on, and spanning counters.
         bCount = fCount = pCount = sCount = 0;

         for(int k = 0; k < totalPolys; k++)
            {
               // Don't include the current polygon we are testing.
               if(i == k)
                  continue;

               // Test where this polygons lies.
               int result = plane.ClassifyTri(pList[k].vertices[0],
                                              pList[k].vertices[1],
                                              pList[k].vertices[2]);

               // Depending on where we add to a counter.
               if(result == PLANE_BACK)
                  bCount++;
               else if(result == PLANE_FRONT)
                  fCount++;
               else if(result == PLANE_ON)
                  pCount++;
               else
                  sCount++;
            }

         // Get the score.
         int diff = fCount - bCount;
         diff = (diff < 0) ? -diff : diff;
         score = diff + (sCount * 3);

         // The polygon with the lowest score will be used.
         if(score < topScore)
            {
               // Only if polys that are in front, back, or spliting.
               if(sCount > 0 || (fCount > 0 && bCount > 0))
                  {
                     topScore = score;
                     bestSplit = &pList[i];
                  }
            }
      }

   if(bestSplit == false)
      return false;

   // Set this polygon as used as a splitter.
   bestSplit->flag = 1;

   // Create this node's splitter plane out of the best polygon.
   m_splitter.Create(bestSplit->vertices[0],
                     bestSplit->vertices[1],
                     bestSplit->vertices[2]);
   return true;
}