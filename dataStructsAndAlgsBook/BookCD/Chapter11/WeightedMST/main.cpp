/*
   Graphs - Weighted Minimum Spanning Trees
   Chapter 11
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<iostream>
#include"Graphs.h"

using namespace std;


int main(int args, char **argc)
{
   cout << "Graphs - Weighted MST" << endl;
   cout << "Chapter 11: Graphs" << endl;
   cout << endl;


   // Create the data structure and fill it in.
   Graph<char> demoGraph(5);
   string output;

   demoGraph.push('A');
   demoGraph.push('B');
   demoGraph.push('C');
   demoGraph.push('D');
   demoGraph.push('E');


   // Attach A to each other vertices.
   demoGraph.attachEdge(0, 1, 1);
   demoGraph.attachEdge(0, 2, 2);
   demoGraph.attachEdge(0, 3, 4);
   demoGraph.attachEdge(0, 4, 3);

   // Attach B to each other vertices.
   demoGraph.attachEdge(1, 2, 1);
   demoGraph.attachEdge(1, 3, 3);
   demoGraph.attachEdge(1, 4, 4);

   // Attach C to each other vertices.
   demoGraph.attachEdge(2, 3, 1);
   demoGraph.attachEdge(2, 4, 4);

   // Attach D to each other vertices.
   demoGraph.attachEdge(3, 4, 1);

   // Vertex E is already attached to all vertices.


   // Display the minimum spanning tree.
   demoGraph.DisplayMST(output);
   cout << "Minimum Spanning Tree: " << output;

   cout << endl << endl;

   return 1;
}