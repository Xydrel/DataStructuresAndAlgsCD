/*
   Graphs - Topological Sorting
   Chapter 11
   Data Structures for Game Developers
   Created by Allen Sherrod
*/


#include<iostream>
#include"Graphs.h"

using namespace std;


int main(int args, char **argc)
{
   cout << "Graphs - Topological Sorting" << endl;
   cout << "Chapter 11: Graphs" << endl;
   cout << endl;


   // Create the data structure and fill it in.
   Graph<char> demoGraph(6);

   demoGraph.push('A'); // 0
   demoGraph.push('B'); // 1
   demoGraph.push('C'); // 2
   demoGraph.push('D'); // 3
   demoGraph.push('E'); // 4
   demoGraph.push('F'); // 5


   // Attach A:B A:C B:D C:E D:E E:F.
   demoGraph.attachDirectedEdge(0, 1);
   demoGraph.attachDirectedEdge(0, 2);
   demoGraph.attachDirectedEdge(1, 3);
   demoGraph.attachDirectedEdge(2, 4);
   demoGraph.attachDirectedEdge(3, 4);
   demoGraph.attachDirectedEdge(4, 5);


   // Perform breadth first search for a path from A to D.
   cout << "BreadthFirstSearch Nodes Visited: ";

   bool result = demoGraph.BreadthFirstSearch(0, 3);
   cout << endl << endl;

   if(result == 1)
      cout << "Path from A to D found!";
   else
      cout << "Path from A to D NOT found!";

   cout << endl << endl;


   // Display the minimum spanning tree.
   cout << "Minimum Spanning Tree: ";
   demoGraph.DisplayMST();

   cout << endl << endl;


   list<char> tsResult;

   if(demoGraph.topologicalSort(tsResult) == true)
      {   
         cout << "Topological Sort: ";
         ostream_iterator<char> output(cout, " ");
         copy(tsResult.begin(), tsResult.end(), output);
      }
   else
      {
         cout << "There are cycles in the graph!";
      }

   cout << endl << endl;

   return 1;
}