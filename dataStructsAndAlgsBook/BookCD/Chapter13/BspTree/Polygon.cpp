/*
   Bsp Tree
   Chapter 13
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include"Polygon.h"


void Polygon::ClipPolygon(Plane &plane, Polygon *fP, Polygon *bP)
{
   float dist[3] = { 0, 0, 0 };
   int side[3] = { 0, 0, 0 };
   int numFront = 0;
   int numBack = 0;
   int frontIndex = 0, backIndex = 0;
   Vector3D pNormal(plane.a, plane.b, plane.c);

   for(int i = 0; i < 3; i++)
      {
         dist[i] = fabs(vertices[i].Dot3(pNormal)) - -plane.d;

         if(dist[i] > 0.001f)
            {
               side[i] = PLANE_FRONT;
               numFront++;
            }
         else if(dist[i] < -0.001f)
            {
               side[i] = PLANE_BACK;
               numBack++;
            }
         else side[i] = PLANE_ON;
      }

   if(!numBack)
      {
         *fP = *this;
      }
   else if(!numFront)
      {
         *bP = *this;
      }
   else
      {
         for(int i = 0; i < 3; i++)
            {
               if(!(side[i] & PLANE_BACK))
                  {
                     fP->vertices[frontIndex] = vertices[i];
                     fP->flag = flag;
                  }
               if(!(side[i] & PLANE_FRONT))
                  {
                     bP->vertices[backIndex] = vertices[i];
                     bP->flag = flag;
                  }

               int j = (i + 1) % 3;

               if((side[i] | side[j]) == PLANE_CLIPPED)
                  {
                     float t = dist[i] / (dist[i] - dist[j]);
                     Vector3D v = vertices[i] * (1.0f - t) + vertices[j] * t;
                     
                     fP->vertices[frontIndex] = v;
                     fP->flag = flag;

                     bP->vertices[backIndex] = v;
                     bP->flag = flag;

                     frontIndex++;
                     backIndex++;
                  }
            }
      }
}