/*
   Scene Graphs
   Chapter 13
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include"OpenGL.h"
#include<stdio.h>
#include"SceneGraph.h"
#include"TransformationNode.h"
#include"SphereNode.h"


void RenderScene();
void KeyDown(unsigned char key, int x, int y);
void Resize(int width, int height);
bool InitializeApp();
void ShutdownApp();


// Scene graph.
SceneGraph g_sceneGraph;


int main(int arg, char **argc)
{
   glutInitWindowSize(800, 600);
   glutInitWindowPosition(100, 100);
   glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
   glutInit(&arg, argc);

   glutCreateWindow("Scene Graph");

   glutDisplayFunc(RenderScene);
   glutReshapeFunc(Resize);
   glutKeyboardFunc(KeyDown);

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

   gluPerspective(45, width/height, 0.1, 200.0);
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


bool InitializeApp()
{
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

   float diffuseLight[] = {0.8f, 0.8f, 0.8f, 1.0f};
   float specularLight[] = {1.0f, 1.0f, 1.0f, 1.0f};
   float LightPosition[] = {1.0f, 0.0f, 8.0f, 1.0f};

   glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
   glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
   glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
   glEnable(GL_LIGHT0);

   glEnable(GL_COLOR_MATERIAL);
   glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
   glMaterialfv(GL_FRONT, GL_SPECULAR, specularLight);
   glMateriali(GL_FRONT, GL_SHININESS, 128);


   TransformationNode *group1 = NULL,  *group2 = NULL,
                      *spherePos1 = NULL, *spherePos2 = NULL,
                      *spherePos3 = NULL, *spherePos4 = NULL,
                      *spherePos5 = NULL, *spherePos6 = NULL;

   SphereNode *sphere1 = NULL, *sphere2 = NULL, *sphere3 = NULL,
              *sphere4 = NULL, *sphere5 = NULL, *sphere6 = NULL;

   group1 = new TransformationNode(Vector3D(5, 0, 0));

   spherePos1 = new TransformationNode(Vector3D(-1, 0, 0));
   spherePos2 = new TransformationNode(Vector3D(1, 0, 0));
   spherePos3 = new TransformationNode(Vector3D(0, 0, -1));

   sphere1 = new SphereNode(1, 20, 20, 1, 0, 0);
   sphere2 = new SphereNode(1, 20, 20, 0, 1, 0);
   sphere3 = new SphereNode(1, 20, 20, 0, 0, 1);

   spherePos1->AddChild(sphere1);
   spherePos2->AddChild(sphere2);
   spherePos3->AddChild(sphere3);

   group1->AddChild(spherePos1);
   group1->AddChild(spherePos2);
   group1->AddChild(spherePos3);


   group2 = new TransformationNode(Vector3D(-5, 0, 0));

   spherePos4 = new TransformationNode(Vector3D(-1, 0, 0));
   spherePos5 = new TransformationNode(Vector3D(1, 0, 0));
   spherePos6 = new TransformationNode(Vector3D(0, 0, -1));

   sphere4 = new SphereNode(1, 20, 20, 1, 1, 0);
   sphere5 = new SphereNode(1, 20, 20, 0, 1, 1);
   sphere6 = new SphereNode(1, 20, 20, 1, 0, 1);

   spherePos4->AddChild(sphere4);
   spherePos5->AddChild(sphere5);
   spherePos6->AddChild(sphere6);

   group2->AddChild(spherePos4);
   group2->AddChild(spherePos5);
   group2->AddChild(spherePos6);


   g_sceneGraph.AddNode(group1);
   g_sceneGraph.AddNode(group2);

   return true;
}


void ShutdownApp()
{
   g_sceneGraph.Release();
}


void RenderScene()
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();

   gluLookAt(0, 5, -20, 0, 0, 0, 0, 1, 0);
   g_sceneGraph.Process();

   glutSwapBuffers();
   glutPostRedisplay();
}