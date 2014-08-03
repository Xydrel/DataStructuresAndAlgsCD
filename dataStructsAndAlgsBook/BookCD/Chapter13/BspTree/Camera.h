/*
   Bsp Tree
   Chapter 13
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#ifndef _CAMERA_H_
#define _CAMERA_H_


#include"Vector3D.h"
#include"Quaternion.h"


class Camera
{
   public:
      Camera()
      {
      
      }


      Camera(Vector3D &pos, Vector3D &lookAt)
      {
         m_pos = pos;
         m_lookAt = lookAt;
      }


      void MoveCamera(float speed)
      {
         Vector3D direction = m_pos - m_lookAt;
         direction.Normalize();

	      m_pos = m_pos + direction * speed;
	      m_lookAt = m_lookAt + direction * speed;
      }
      
      
      void RotateCamera(float angle, Vector3D axis)
      {
	      Quaternion qRotation, qView, qNewView;

         qRotation.Rotatef(angle, axis);

         qView.x = m_lookAt.x - m_pos.x;
         qView.y = m_lookAt.y - m_pos.y;
         qView.z = m_lookAt.z - m_pos.z;
         qView.w = 0;

         qNewView = ((qRotation * qView) * qRotation.Conjugate());

         m_lookAt.x = m_pos.x + qNewView.x;
         m_lookAt.y = m_pos.y + qNewView.y;
         m_lookAt.z = m_pos.z + qNewView.z;
      }


      void SetPosition(Vector3D pos)
      {
         m_pos = pos;
      }


      void SetLookAt(Vector3D at)
      {
         m_lookAt = at;
      }

      Vector3D GetPosition()
      {
         return m_pos;
      }


      Vector3D GetLookAt()
      {
         return m_lookAt;
      }


   private:
      Vector3D m_pos, m_lookAt;
};

#endif