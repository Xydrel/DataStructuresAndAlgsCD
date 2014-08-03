/*
   Texture Compression
   Chapter 14
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include"OpenGL.h"
#include<stdio.h>
#include"DDSLoader.h"


void RenderScene();
void KeyDown(unsigned char key, int x, int y);
void Resize(int width, int height);
bool InitializeApp();
void ShutdownApp();


// DDS Texture.
GLuint g_texture;


int main(int arg, char **argc)
{
   glutInitWindowSize(800, 600);
   glutInitWindowPosition(100, 100);
   glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
   glutInit(&arg, argc);

   glutCreateWindow("Texture Compression");

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
	glEnable(GL_TEXTURE_2D);


   // Load DDS image.
   ImageInfoDDS info;
	unsigned char *image = LoadDDS("../image.dds", info);

   if(image == NULL)
      {
         image = LoadDDS("../../image.dds", info);

         if(image == NULL)
            return false;
      }

	glGenTextures(1, &g_texture);
   glBindTexture(GL_TEXTURE_2D, g_texture);
	
	int w = info.m_width;
   int h = info.m_height;
	int mipFactor = 0;

   if(info.m_type == DDS_DXT1)
      mipFactor = 8;
   else
      mipFactor = 16;

   int mipSize;
   int mipOffset = 0;

   int type = 0;

   switch(info.m_type)
      {
         case DDS_DXT1:
            type = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT;
            break;

         case DDS_DXT3:
            type = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;
            break;

         case DDS_DXT5:
            type = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT;
            break;
      }

   for(int i = 0; i < info.m_numMipMaps; i++)
      {
         mipSize = ((w + 3) / 4) * ((h + 3) / 4) * mipFactor;

         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                         GL_LINEAR);
	      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
	                      GL_LINEAR);

         glCompressedTexImage2DARB(GL_TEXTURE_2D, i, type, w, h,
                                   0, mipSize, image + mipOffset);

         // Half the image size for the next mip-map level...
         w >>= 1;
         h >>= 1;

         // Move the offset to the next mip map.
         mipOffset += mipSize;
      }

   delete[] image;

   return true;
}


void ShutdownApp()
{
   glDeleteTextures(1, &g_texture);
}


void RenderScene()
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();

   glTranslatef(0.0f, 0.0f, -3.0f);

   glBindTexture(GL_TEXTURE_2D, g_texture);

   glBegin(GL_QUADS);

      glTexCoord2f(0, 0); glVertex3f(-1, -1, 0);
      glTexCoord2f(1, 0); glVertex3f( 1, -1, 0);
      glTexCoord2f(1, 1); glVertex3f( 1,  1, 0);
      glTexCoord2f(0, 1); glVertex3f(-1,  1, 0);

   glEnd();

   glutSwapBuffers();
   glutPostRedisplay();
}
