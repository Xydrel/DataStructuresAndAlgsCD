/*
   Scene Graphs
   Chapter 13
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#ifndef _SCENE_GRAPH_H_
#define _SCENE_GRAPH_H_

#include"node.h"


class SceneGraph
{
   public:
      SceneGraph()
      {
         m_root = NULL;
      }

      ~SceneGraph()
      {
         Release();
      }


      void Release()
      {
         if(m_root != NULL)
            {
               delete m_root;
               m_root = NULL;
            }
      }


      void AddNode(Node *node)
      {
         if(m_root == NULL)
            m_root = new Node;

         m_root->AddChild(node);
      }


      void Process()
      {
         if(m_root != NULL)
            m_root->Process();
      }


   private:
      Node *m_root;
};


#endif