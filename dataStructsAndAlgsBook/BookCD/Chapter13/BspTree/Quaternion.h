/*
   Bsp Tree
   Chapter 13
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#ifndef _QUATERNION_H_
#define _QUATERNION_H_

#define PI 3.141592654
#define GET_RADIANS(degree) (float)((degree * PI) / 180.0f)

#include<math.h>
#include"Vector3D.h"


class Quaternion 
{
   public:
      Quaternion() : x(0), y(0), z(0), w(1)
      {
      }
      
      
      Quaternion(float X, float Y, float Z, float W) :
         x(X), y(Y), z(Z), w(W)
      {
      }


      void operator=(const Quaternion &q)
      {
         w = q.w; x = q.x; y = q.y; z = q.z;
      }


      Quaternion operator*(const Quaternion &q)
      {
         // To multiply a quaternion you must first
         // do the dot and cross product
         // of the 2 quaternions then add/subract
         // them to a result.
         Quaternion result;

         result.x = w * q.x + x * q.w + y * q.z - z * q.y;
         result.y = w * q.y - x * q.z + y * q.w + z * q.x;
         result.z = w * q.z + x * q.y - y * q.x + z * q.w;
         result.w = w * q.w - x * q.x - y * q.y - z * q.z;

         return result;
      }


      Quaternion Conjugate()
      {
         return Quaternion(-x, -y, -z, w);
      }


	   void Rotatef(float amount, Vector3D &axisNormal)
      {
         float angle = GET_RADIANS(amount);
	      float sine = (float)sin(angle / 2.0f);

	      x = axisNormal.x * sine;
	      y = axisNormal.y * sine;
	      z = axisNormal.z * sine;
         w = (float)cos(angle / 2.0f);

         // Normalize the quaternion.
         float length = 1 / (float)sqrt(x * x + y * y + z * z + w * w);
         x *= length;
         y *= length;
         z *= length;
      }


	   float x, y, z, w;
};

#endif