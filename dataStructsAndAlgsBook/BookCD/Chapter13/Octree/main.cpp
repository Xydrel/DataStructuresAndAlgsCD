/*
   Octree
   Chapter 13
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include"OpenGL.h"
#include<stdio.h>
#include"Terrain.h"
#include"Camera.h"


void RenderScene();
void KeyDown(unsigned char key, int x, int y);
void KeyDown2(int key, int x, int y);
void Resize(int width, int height);
bool InitializeApp();
void ShutdownApp();


Terrain g_terrain;
Camera g_camera;


int main(int arg, char **argc)
{
   glutInitWindowSize(800, 600);
   glutInitWindowPosition(100, 100);
   glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
   glutInit(&arg, argc);

   glutCreateWindow("Octree Example");

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
   glClearColor(0.6f, 0.6f, 1.0f, 1.0f);
   glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

   // Load map.
   if(!g_terrain.LoadMap("../map.raw"))
      {
         if(!g_terrain.LoadMap("../../map.raw"))
            return false;
      }

   // Set the camera's default position.
   g_camera.SetPosition(Vector3D(50.0f, 50.0f, 10.0f));
   g_camera.SetLookAt(Vector3D(50.0f, 50.0f, 11.0f));

   return true;
}


void ShutdownApp()
{
   g_terrain.ShutDown();
}


void DrawBoundingBox(Vector3D &min, Vector3D &max)
{
	glColor3f(1.0, 0.0, 0.0f);

	glBegin(GL_LINE_LOOP);
	   glVertex3f(min.x, min.y, min.z);
	   glVertex3f(max.x, min.y, min.z);
	   glVertex3f(max.x, min.y, max.z);
	   glVertex3f(min.x, min.y, max.z);
	glEnd();

	glBegin(GL_LINE_LOOP);
	   glVertex3f(min.x, max.y, min.z);
	   glVertex3f(max.x, max.y, min.z);
	   glVertex3f(max.x, max.y, max.z);
	   glVertex3f(min.x, max.y, max.z);
	glEnd();

	glBegin(GL_LINES);
	   glVertex3f(min.x, min.y, min.z);
	   glVertex3f(min.x, max.y, min.z);
	   glVertex3f(max.x, min.y, min.z);
	   glVertex3f(max.x, max.y, min.z);
   glEnd();

   glBegin(GL_LINES);
	   glVertex3f(max.x, min.y, max.z);
	   glVertex3f(max.x, max.y, max.z);
	   glVertex3f(min.x, min.y, max.z);
	   glVertex3f(min.x, max.y, max.z);
	glEnd();

   glColor3f(1.0, 1.0, 1.0f);
}


void RenderOctreeNode(OctreeNode* pNode)
{
   if(pNode == NULL)
      return;

   if(pNode->isLeaf())
      {
         BoundingBox aabb = pNode->GetBoundingBox();
         DrawBoundingBox(aabb.m_min, aabb.m_max);

         glEnableClientState(GL_VERTEX_ARRAY);
         glVertexPointer(3, GL_FLOAT, 0, pNode->GetVertices());
         glDrawArrays(GL_TRIANGLES, 0, pNode->GetTotalVertices());
         glDisableClientState(GL_VERTEX_ARRAY);
      }
   else
      {
         OctreeNode **pSubNodes = pNode->GetSubNodes();
         RenderOctreeNode(pSubNodes[TOP_FRONT_LEFT]);
         RenderOctreeNode(pSubNodes[TOP_FRONT_RIGHT]);
         RenderOctreeNode(pSubNodes[TOP_BACK_LEFT]);
         RenderOctreeNode(pSubNodes[TOP_BACK_RIGHT]);

         RenderOctreeNode(pSubNodes[BOTTOM_FRONT_LEFT]);
         RenderOctreeNode(pSubNodes[BOTTOM_FRONT_RIGHT]);
         RenderOctreeNode(pSubNodes[BOTTOM_BACK_LEFT]);
         RenderOctreeNode(pSubNodes[BOTTOM_BACK_RIGHT]);
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

   RenderOctreeNode(g_terrain.GetRoot());

   glutSwapBuffers();
   glutPostRedisplay();
}