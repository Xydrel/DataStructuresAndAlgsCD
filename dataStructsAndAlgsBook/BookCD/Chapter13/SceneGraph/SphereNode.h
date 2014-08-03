/*
   Scene Graphs
   Chapter 13
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#ifndef _SPHERE_NODE_H_
#define _SPHERE_NODE_H_

#include"node.h"


class SphereNode : public Node
{
   public:
      SphereNode(double rd, int slices, int stacks,
                 float r, float g, float b) :
                 m_radius(rd), m_slices(slices), m_stacks(stacks),
                 m_red(r), m_green(g), m_blue(b)
      {

      }

      ~SphereNode()
      {

      }


      void Process()
      {
         glColor3f(m_red, m_green, m_blue);
         glutSolidSphere(m_radius, m_slices, m_stacks);

         if(m_child != NULL)
            m_child->Process();

         if(m_next != NULL)
            m_next->Process();
      }

   protected:
      double m_radius;
      int m_slices, m_stacks;
      float m_red, m_green, m_blue;
};


#endif