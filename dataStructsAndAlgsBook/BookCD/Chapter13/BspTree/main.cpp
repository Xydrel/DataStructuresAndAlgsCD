/*
   Bsp Tree
   Chapter 13
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include"OpenGL.h"
#include<stdio.h>
#include"BspTree.h"
#include"Camera.h"


void RenderScene();
void KeyDown(unsigned char key, int x, int y);
void KeyDown2(int key, int x, int y);
void Resize(int width, int height);
bool InitializeApp();
void ShutdownApp();


Camera g_camera;
BspNode *g_rootNode;


enum ENDIAN { ENDIAN_UNKNOWN = 0, ENDIAN_LITTLE, ENDIAN_BIG };


ENDIAN GetEndian()
{
   unsigned long data = 0x12345678;
   unsigned char *ptr = (unsigned char*)&data;

   if(*ptr == 0x12 && *(ptr+1) == 0x34 &&
      *(ptr+2) == 0x56 && *(ptr+3) == 0x78)
      {
         return ENDIAN_BIG;
      }
   else if(*ptr == 0x78 && *(ptr + 1) == 0x56 &&
           *(ptr + 2) == 0x34 && *(ptr + 3) == 0x12)
      {
         return ENDIAN_LITTLE;
      }

   return ENDIAN_UNKNOWN;
}


void SwapBytes(char *data, int size)
{
	char *ptr = data;
	char temp = 0;

	for(int i = 0, j = size - 1; i < size / 2; i++, j--)
	   {
		   temp = ptr[i];
		   ptr[i] = ptr[j];
		   ptr[j] = temp;
	   }
}


int main(int arg, char **argc)
{
   glutInitWindowSize(800, 600);
   glutInitWindowPosition(100, 100);
   glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
   glutInit(&arg, argc);

   glutCreateWindow("Bsp Tree Example");

   glutDisplayFunc(RenderScene);
   glutReshapeFunc(Resize);
   glutKeyboardFunc(KeyDown);
   glutSpecialFunc(KeyDown2);

   if(InitializeApp() == true)
      glutMainLoop();
   else
      printf("Error in InitializeApp()!\n\n");

   ShutdownApp();

   return 1;
}


void Resize(int width, int height)
{
   glViewport(0, 0, width, height);
   glMatrixMode(GL_PROJECTION);

   gluPerspective(45, width/height, 0.1, 1000.0);
   glMatrixMode(GL_MODELVIEW);
}


void KeyDown(unsigned char key, int x, int y)
{
   switch(key)
      {
         case 27:
            exit(0);
            break;
      }
}


void KeyDown2(int key, int x, int y)
{
   switch(key)
      {
         case 101:
            g_camera.MoveCamera(-0.5f);
            break;

         case 103:
            g_camera.MoveCamera(0.5f);
            break;

         case 100:
            g_camera.RotateCamera(0.5f, Vector3D(0, 1, 0));
            break;

         case 102:
            g_camera.RotateCamera(-0.5f, Vector3D(0, 1, 0));
            break;
      }
}


bool InitializeApp()
{
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glShadeModel(GL_SMOOTH);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

   ENDIAN e = GetEndian();
   bool byteSwap = false;

   if(e == ENDIAN_BIG)
      byteSwap = true;

   FILE *fp = fopen("../map.raw2", "rb");

   if(fp == NULL)
      {
         fp = fopen("../../map.raw2", "rb");
         
         if(fp == NULL)
            return false;
      }

   int size = 0;
   fread(&size, 1, sizeof(int), fp);

   if(byteSwap == true)
      SwapBytes((char*)&size, sizeof(int));

   Polygon *polys = new Polygon[size];
   g_rootNode = new BspNode();

   if(polys == NULL || g_rootNode == NULL)
      return false;

   for(int i = 0; i < 16; i++)
      {
         fread(polys[i].vertices, 1, sizeof(Vector3D) * 3, fp);

         if(byteSwap == true)
            {
               SwapBytes((char*)&polys[i].vertices[0].x, sizeof(float));
               SwapBytes((char*)&polys[i].vertices[0].y, sizeof(float));
               SwapBytes((char*)&polys[i].vertices[0].z, sizeof(float));
               SwapBytes((char*)&polys[i].vertices[1].x, sizeof(float));
               SwapBytes((char*)&polys[i].vertices[1].y, sizeof(float));
               SwapBytes((char*)&polys[i].vertices[1].z, sizeof(float));
               SwapBytes((char*)&polys[i].vertices[2].x, sizeof(float));
               SwapBytes((char*)&polys[i].vertices[2].y, sizeof(float));
               SwapBytes((char*)&polys[i].vertices[2].z, sizeof(float));
            }
      }

   fclose(fp);

	if(g_rootNode->CreateNode(polys, size) == false)
	   return false;

   delete[] polys;

   g_camera.SetPosition(Vector3D(0, 0, 0));
   g_camera.SetLookAt(Vector3D(0, 0, -1));

   return true;
}


void ShutdownApp()
{
   if(g_rootNode)
      {
         g_rootNode->Shutdown();
         delete g_rootNode;
         g_rootNode = NULL;
      }
}


void TraverseBackFront(BspNode *node, Vector3D pos)
{
   if(node == NULL)
      return;

   int totalPolys = 0, i = 0;
   Polygon *polyPtr = NULL;

   // Only draw nodes with geometry.
   if(node->isLeafNode())
      {
         totalPolys = node->GetTotalPolygons();
         polyPtr = node->GetPolygons();

         if(polyPtr == NULL || totalPolys <= 0)
            return;

         // Loop through and draw out all polygons.
         for(i = 0; i < totalPolys; i++)
            {
               glBegin(GL_TRIANGLES);

                  glVertex3f(polyPtr[i].vertices[0].x,
                             polyPtr[i].vertices[0].y,
                             polyPtr[i].vertices[0].z);

                  glVertex3f(polyPtr[i].vertices[1].x,
                             polyPtr[i].vertices[1].y,
                             polyPtr[i].vertices[1].z);

                  glVertex3f(polyPtr[i].vertices[2].x,
                             polyPtr[i].vertices[2].y,
                             polyPtr[i].vertices[2].z);

               glEnd();
            }
      }
   else
      {
         // Not leaf?  Determine which way to traverse...
         int result = node->ClassifyPoint(pos);

         if(result == PLANE_BACK)
            {
               TraverseBackFront(node->GetFrontNode(), pos);
               TraverseBackFront(node->GetBackNode(), pos);
            }
         else
            {
               TraverseBackFront(node->GetBackNode(), pos);
               TraverseBackFront(node->GetFrontNode(), pos);
            }
      }
}


void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();

   Vector3D pos = g_camera.GetPosition();
   Vector3D view = g_camera.GetLookAt();

   gluLookAt(pos.x, pos.y, pos.z,
             view.x, view.y, view.z,
             0, 1, 0);

   TraverseBackFront(g_rootNode, g_camera.GetPosition());

   glutSwapBuffers();
   glutPostRedisplay();
}