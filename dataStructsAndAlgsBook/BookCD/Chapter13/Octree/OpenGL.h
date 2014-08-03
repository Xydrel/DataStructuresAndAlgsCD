/*
   Octree
   Chapter 13
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#ifdef _WIN32
   // Windows.
   #include<gl/glee.h>
   #include<gl/glut.h>
#else
#ifdef _MAC_OSX
   // Mac.
   #include<glut/glut.h>
   #include<stdlib.h>
#else
   // Linux.
   #include<GL/glut.h>
   #include<stdlib.h>
#endif
#endif
