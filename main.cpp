#include "head.h"

int NODES, EDGES;
int U, V, WEIGHT;
int GRAPH[MAX][MAX];
int SOURCE = 0;
int CHOOSE = 1;

int x[MAX], y[MAX];
int prevNodeIndex[MAX];

//for Fixed Graph
int fixed_NODES, fixed_EDGES;
int fixed_U, fixed_V, fixed_WEIGHT;
int fixed_GRAPH[MAX][MAX];
int fixed_SOURCE = 0;

int fixed_NODES_2, fixed_EDGES_2;
int fixed_GRAPH_2[MAX][MAX];
int fixed_SOURCE_2 = 0;

//for Directed Fixed Graph
int directedFixed_NODES, directedFixed_EDGES;
int directedFixed_U, directedFixed_V, directedFixed_WEIGHT;
int directedFixed_GRAPH[MAX][MAX];
int directedFixed_SOURCE = 0;

int COUNT = 0;



int main()
{
    openGraphicalWindow();
    Graphics_MENU();
  //  BFS();
   // DFS();
  // topologicalsort();
 // void BellmanFord_algorithm();
//  void MST_Kruskals_Algorithm ();
//void MST_Prims_Algorithm ();
    return 0;
}

