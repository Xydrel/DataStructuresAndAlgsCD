/*
   Scene Graphs
   Chapter 13
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#ifndef _NODE_H_
#define _NODE_H_


class Node
{
   public:
      Node()
      {
         m_next = NULL;
         m_prev = NULL;
         m_child = NULL;
      }

      virtual ~Node()
      {
         m_prev = NULL;

         if(m_child != NULL)
            {
               delete m_child;
               m_child = NULL;
            }

         if(m_next != NULL)
            {
               delete m_next;
               m_next = NULL;
            }
      }

      void AddChild(Node *node)
      {
         if(m_child == NULL)
            {
               m_child = node;
            }
         else
            {
               m_child->AddSibling(node);
            }
      }

      void AddSibling(Node *node)
      {
         Node *ptr = m_next;

         if(m_next == NULL)
            {
               m_next = node;
               node->m_prev = this;
            }
         else
            {
               while(ptr->m_next != NULL)
                  {
                     ptr = ptr->m_next;
                  }

               ptr->m_next = node;
               node->m_prev = ptr;
            }
      }

      virtual void Process()
      {
         if(m_child != NULL)
            m_child->Process();

         if(m_next != NULL)
            m_next->Process();
      }


   protected:
      Node *m_next;
      Node *m_prev;
      Node *m_child;
};


#endif