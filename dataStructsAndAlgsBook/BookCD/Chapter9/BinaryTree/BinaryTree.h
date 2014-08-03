/*
   Binary Trees
   Chapter 9
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#ifndef _BINARY_TREE_
#define _BINARY_TREE_


#include<iostream>

using namespace std;


template<typename T>
class BinaryTree;


template<typename T>
class Node
{
   friend class BinaryTree<T>;

   public:
      Node(T key) : m_key(key), m_left(NULL), m_right(NULL)
      {

      }


      ~Node()
      {
         if(m_left != NULL)
            {
               delete m_left;
               m_left = NULL;
            }

         if(m_right != NULL)
            {
               delete m_right;
               m_right = NULL;
            }
      }


      T GetKey()
      {
         return m_key;
      }


   private:
      T m_key;

      Node *m_left, *m_right;
};


template<typename T>
class BinaryTree
{
   public:
      BinaryTree() : m_root(NULL)
      {

      }


      ~BinaryTree()
      {
         if(m_root != NULL)
            {
               delete m_root;
               m_root = NULL;
            }
      }


      bool push(T key)
      {
         Node<T> *newNode = new Node<T>(key);

         if(m_root == NULL)
            {
               m_root = newNode;
            }
         else
            {
               Node<T> *parentNode = NULL;
               Node<T> *currentNode = m_root;

               while(1)
                  {
                     parentNode = currentNode;

                     if(key == currentNode->m_key)
                        {
                           delete newNode;
                           return false;
                        }

                     if(key < currentNode->m_key)
                        {
                           currentNode = currentNode->m_left;

                           if(currentNode == NULL)
                              {
                                 parentNode->m_left = newNode;
                                 return true;
                              }
                        }
                     else
                        {
                           currentNode = currentNode->m_right;

                           if(currentNode == NULL)
                              {
                                 parentNode->m_right = newNode;
                                 return true;
                              }
                        }
                  }
            }

         return true;
      }


      bool search(T key)
      {
         if(m_root == NULL)
            return false;

         Node<T> *currentNode = m_root;

         while(currentNode->m_key != key)
            {
               if(key < currentNode->m_key)
                  currentNode = currentNode->m_left;
               else
                  currentNode = currentNode->m_right;

               if(currentNode == NULL)
                  return false;
            }

         return true;
      }


      void remove(T key)
      {
         if(m_root == NULL)
            return;

         Node<T> *parent = m_root;
         Node<T> *node = m_root;
         bool isLeftNode = false;

         while(node->m_key != key)
            {
               parent = node;

               if(key < node->m_key)
                  {
                     node = node->m_left;
                     isLeftNode = true;
                  }
               else
                  {
                     node = node->m_right;
                     isLeftNode = false;
                  }

               if(node == NULL)
                  return;
            }

         if(node->m_left == NULL && node->m_right == NULL)
            {
               if(node == m_root)
                  m_root = NULL;
               else if(isLeftNode == true)
                  parent->m_left = NULL;
               else
                  parent->m_right = NULL;
            }
         else if(node->m_left == NULL)
            {
               if(node == m_root)
                  m_root = node->m_right;
               else if(isLeftNode == true)
                  parent->m_left = node->m_right;
               else
                  parent->m_right = node->m_right;
            }
         else if(node->m_right == NULL)
            {
               if(node == m_root)
                  m_root = node->m_left;
               else if(isLeftNode == true)
                  parent->m_left = node->m_left;
               else
                  parent->m_right = node->m_left;
            }
         else
            {
               Node<T> *tempNode = node->m_right;
               Node<T> *successor = node;
               Node<T> *successorParent = node;

               while(tempNode != NULL)
                  {
                     successorParent = successor;
                     successor = tempNode;
                     tempNode = tempNode->m_left;
                  }

               if(successor != node->m_right)
                  {
                     successorParent->m_left = successor->m_right;
                     successor->m_right = node->m_right;
                  }

               if(node == m_root)
                  {
                     m_root = successor;
                  }
               else if(isLeftNode)
                  {
                     node = parent->m_left;
                     parent->m_left = successor;
                  }
               else
                  {
                     node = parent->m_right;
                     parent->m_right = successor;
                  }

               successor->m_left = node->m_left;
            }

         node->m_left = NULL;
         node->m_right = NULL;
         delete node;
      }


      void DisplayPreOrder()
      {
         DisplayPreOrder(m_root);
      }


      void DisplayPostOrder()
      {
         DisplayPostOrder(m_root);
      }


      void DisplayInOrder()
      {
         DisplayInOrder(m_root);
      }


   private:
      void DisplayPreOrder(Node<T> *node)
      {
         if(node != NULL)
            {
               cout << node->m_key << " ";

               DisplayPreOrder(node->m_left);
               DisplayPreOrder(node->m_right);
            }
      }


      void DisplayPostOrder(Node<T> *node)
      {
         if(node != NULL)
            {
               DisplayPostOrder(node->m_left);
               DisplayPostOrder(node->m_right);

               cout << node->m_key << " ";
            }
      }


      void DisplayInOrder(Node<T> *node)
      {
         if(node != NULL)
            {
               DisplayInOrder(node->m_left);

               cout << node->m_key << " ";

               DisplayInOrder(node->m_right);
            }
      }


   private:
      Node<T> *m_root;
};

#endif