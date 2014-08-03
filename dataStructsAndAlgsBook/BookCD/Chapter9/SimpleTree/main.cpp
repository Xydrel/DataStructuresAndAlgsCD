/*
   Simple Tree
   Chapter 9
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<iostream>

using namespace std;


class Node
{
   public:
      Node(int obj) : m_object(obj), m_next(NULL),
                      m_prev(NULL), m_child(NULL)
      {
         cout << "Node created!" << endl;
      }


      ~Node()
      {
         m_prev = NULL;

         if(m_child != NULL)
            delete m_child;

         if(m_next != NULL)
            delete m_next;

         m_child = NULL;
         m_next = NULL;

         cout << "Node deleted!" << endl;
      }


      void AddChild(Node *node)
      {
         if(m_child == NULL)
            m_child = node;
         else
            m_child->AddSibling(node);
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
                  ptr = ptr->m_next;

               ptr->m_next = node;
               node->m_prev = ptr;
            }
      }


      void DisplayTree()
      {
         cout << m_object;

         if(m_next != NULL)
            {
               cout << " ";
               m_next->DisplayTree();
            }

         if(m_child != NULL)
            {
               cout << endl;
               m_child->DisplayTree();
            }

      }


      bool Search(int value)
      {
         if(m_object == value)
            return true;

         if(m_child != NULL)
            {
               if(m_child->Search(value) == true)
                  return true;
            }

         if(m_next != NULL)
            {
               if(m_next->Search(value) == true)
                  return true;
            }

         return false;
      }


   private:
      int m_object;
      Node *m_next, *m_prev, *m_child;
};


int main(int args, char *arg[])
{
   cout << "Simple Tree Data Structure" << endl;
   cout << "Chapter 9: Trees" << endl << endl;


   // Manually create the tree...
   Node *root = new Node(1);
   Node *subTree1 = new Node(3);

   root->AddChild(new Node(2));

   subTree1->AddChild(new Node(5));
   subTree1->AddChild(new Node(6));

   root->AddChild(subTree1);
   root->AddChild(new Node(4));

   cout << endl;


   // Display the tree...
   cout << "Tree contents by level:" << endl;

   root->DisplayTree();

   cout << endl << endl;


   // Test seaching...
   cout << "Searching for node 5: ";

   if(root->Search(5) == true)
      cout << "Node Found!" << endl;
   else
      cout << "Node NOT Found!" << endl;

   cout << "Searching for node 9: ";

   if(root->Search(9) == true)
      cout << "Node Found!" << endl;
   else
      cout << "Node NOT Found!" << endl;

   cout << endl;


   // Will delete entire tree...
   delete root;

   cout << endl << endl;

   return 1;
}