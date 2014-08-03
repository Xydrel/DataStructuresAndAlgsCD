/*
   Bsp Tree
   Chapter 13
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#ifndef _PLANE_H_
#define _PLANE_H_

#include"Vector3D.h"


enum PLANE_STATUS { PLANE_ON = 0, PLANE_FRONT, PLANE_BACK, PLANE_CLIPPED };


class Plane
{
   public:
      Plane() : a(0), b(0), c(0), d(0) { }
      Plane(float A, float B, float C, float D) :
         a(A), b(B), c(C), d(D) { }


      void Create(Vector3D &t1, Vector3D &t2, Vector3D &t3)
      {
         Vector3D e1, e2, n;

         e1 = t2 - t1;
         e2 = t3 - t1;

         n = e1.CrossProduct(e2);
         n.Normalize();

         a = n.x; b = n.y; c = n.z;
         d = - (a * t1.x + b * t1.y + c * t1.z);
      }


      bool Intersect(const Vector3D &bbMin, const Vector3D &bbMax)
      {
         Vector3D min, max;
         Vector3D normal(a, b, c);
         
         if(normal.x >= 0.0f)
            {
               min.x = bbMin.x; max.x = bbMax.x;
            }
         else
            {
               min.x = bbMax.x; max.x = bbMin.x;
            }
         
         if(normal.y >= 0.0f)
            {
               min.y = bbMin.y; max.y = bbMax.y;
            }
         else
            {
               min.y = bbMax.y; max.y = bbMin.y;
            }
         
         if(normal.z >= 0.0f)
            {
               min.z = bbMin.z; max.z = bbMax.z;
            }
         else
            {
               min.z = bbMax.z; max.z = bbMin.z;
            }
         
         if((normal.Dot3(min) + d) > 0.0f)
            return false;

         if((normal.Dot3(max) + d) >= 0.0f)
            return true;
         
         return false;
      }


      bool Intersect(Vector3D &position, float radius)
      {
	      float dp = fabs(GetDistance(position));

	      if(dp <= radius)
            return true;

         return false;
      }


      PLANE_STATUS ClassifyPoint(float x, float y, float z, float *dist)
      {
         float distance = a * x + b * y + c * z + d;

         if(dist != 0)
            *dist = distance;

         if(distance > 0.001)
            return PLANE_FRONT;

         if(distance < -0.001)
            return PLANE_BACK;

         return PLANE_ON;
      }
      
      
      PLANE_STATUS ClassifyPoint(Vector3D &v, float *dist)
      {
         float distance = a * v.x + b * v.y + c * v.z + d;

         if(dist != 0)
            *dist = distance;

         if(distance > 0.001)
            return PLANE_FRONT;

         if(distance < -0.001)
            return PLANE_BACK;

         return PLANE_ON;
      }


      int ClassifyTri(Vector3D &v1, Vector3D &v2, Vector3D &v3)
      {
         int numFront = 0, numBack = 0, numOnPlane = 0, result;

         result = ClassifyPoint(v1, 0);
         if(result == PLANE_FRONT) numFront++;
         if(result == PLANE_BACK) numBack++;
         if(result == PLANE_ON) numOnPlane++;

         result = ClassifyPoint(v2, 0);
         if(result == PLANE_FRONT) numFront++;
         if(result == PLANE_BACK) numBack++;
         if(result == PLANE_ON) numOnPlane++;

         result = ClassifyPoint(v3, 0);
         if(result == PLANE_FRONT) numFront++;
         if(result == PLANE_BACK) numBack++;
         if(result == PLANE_ON) numOnPlane++;

         if(numFront == 3) return PLANE_FRONT;
         if(numBack == 3) return PLANE_BACK;
         if(numOnPlane == 3) return PLANE_ON;

         return PLANE_CLIPPED;
      }


      float GetDistance(Vector3D &pos)
      {
         return a * pos.x + b * pos.y + c * pos.z + d;
      }


      float a, b, c, d;
};


#endif
