/*
   Bsp Tree
   Chapter 13
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#ifndef _POLYGON_H_
#define _POLYGON_H_


#include"Vector3D.h"
#include"Plane.h"


class Polygon
{
   public:
      Polygon() : flag(0) { }
      ~Polygon() { }

      void ClipPolygon(Plane &plane, Polygon *fP, Polygon *bP);

      void operator=(Polygon &p)
      {
         flag = p.flag;
         vertices[0] = p.vertices[0];
         vertices[1] = p.vertices[1];
         vertices[2] = p.vertices[2];
      }

      Vector3D vertices[3];

      // Used in the BSP demos only.
      int flag;
};

#endif