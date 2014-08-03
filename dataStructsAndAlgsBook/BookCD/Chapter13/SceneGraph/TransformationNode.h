/*
   Scene Graphs
   Chapter 13
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#ifndef _TRANSFORMATION_NODE_H_
#define _TRANSFORMATION_NODE_H_

#include"node.h"
#include"Vector3D.h"


class TransformationNode : public Node
{
   public:
      TransformationNode(Vector3D pos) : m_pos(pos)
      {

      }

      ~TransformationNode()
      {

      }


      void Process()
      {
         glPushMatrix();

         glTranslatef(m_pos.x, m_pos.y, m_pos.z);

         if(m_child != NULL)
            m_child->Process();

         glPopMatrix();

         if(m_next != NULL)
            m_next->Process();
      }

   protected:
      Vector3D m_pos;
};


#endif