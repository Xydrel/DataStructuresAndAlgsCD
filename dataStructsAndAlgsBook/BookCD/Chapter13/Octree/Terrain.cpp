/*
   Octree
   Chapter 13
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include"Terrain.h"
#include<stdio.h>


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


Terrain::Terrain() : m_rootNode(NULL)
{

}


Terrain::~Terrain()
{
   ShutDown();
}


bool Terrain::LoadMap(char *filename)
{
   if(filename == NULL)
      return false;

   FILE *fp = fopen(filename, "rb");

   if(fp == NULL)
      return false;

   ENDIAN e = GetEndian();
   bool byteSwap = false;

   if(e == ENDIAN_BIG)
      byteSwap = true;

   // FILE FORMAT:
   //   1.  Total number of vertices
   //   2.  Vertices (Vector3D list).

   int totalVerts;

   // 1.  Read total number of vertices.
   fread(&totalVerts, 1, sizeof(int), fp);

   if(byteSwap == true)
      SwapBytes((char*)&totalVerts, sizeof(int));

   Vector3D *mesh = new Vector3D[totalVerts];

   // 2.  Read mesh.
   fread(mesh, 1, sizeof(Vector3D) * totalVerts, fp);

   char *ptr = (char*)mesh;

   if(byteSwap == true)
      {
         for(int i = 0; i < totalVerts * 3; i++)
            {
               SwapBytes(ptr, sizeof(float));
               ptr += sizeof(float);
            }
      }

   // Delete if already exist (loading new map).
   if(m_rootNode)
      delete m_rootNode;

   m_rootNode = new OctreeNode();
   m_rootNode->Initialize(mesh, totalVerts, 5, 1000);

   delete[] mesh;

   fclose(fp);
   return true;
}


void Terrain::ShutDown()
{
   if(m_rootNode)
      {
         // Will recursivly delete.
         m_rootNode->Shutdown();
         delete m_rootNode;
         m_rootNode = NULL;
      }
}