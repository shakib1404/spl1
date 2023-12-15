#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#include<bits/stdc++.h>

#include<stdio.h>
#include<graphics.h>
#include <cstdlib> //it's used for the srand(), rand() functions, which generates random numbers.
#include <ctime>
#include<queue> //for time(0) function
#include<limits.h>


#define MAX 100

using namespace std;
//for User Iput & Randomly created graphs
//for User Iput & Randomly created graphs
extern int CHOOSE;
extern int NODES, EDGES;
extern int U, V, WEIGHT;
extern int GRAPH[MAX][MAX];
extern int SOURCE ;


extern int x[MAX], y[MAX];
extern int prevNodeIndex[MAX];

//for Fixed Graph
extern int fixed_NODES, fixed_EDGES;
extern int fixed_U, fixed_V, fixed_WEIGHT;
extern int fixed_GRAPH[MAX][MAX];
extern int fixed_SOURCE ;

extern int fixed_NODES_2, fixed_EDGES_2;
extern int fixed_GRAPH_2[MAX][MAX];
extern int fixed_SOURCE_2 ;

//for Directed Fixed Graph
extern int directedFixed_NODES, directedFixed_EDGES;
extern int directedFixed_U, directedFixed_V, directedFixed_WEIGHT;
extern int directedFixed_GRAPH[MAX][MAX];
extern int directedFixed_SOURCE ;
extern int directedFixed_x[MAX], directedFixed_y[MAX];
extern int radiusForDirected;
extern int prevNodeColorForDirected;

extern int COUNT ;


extern int vertex1, edge1;
extern int graphForBellman[MAX][MAX];
extern int Cost[MAX][MAX];

void BFS();
void BFS_UPDATE();
void DFS() ;
void DFS_UPDATE();
void topologicalsort();
void TOPOLOGICAL_UPDATE();

void prevWindowArrow ();
void graphOptions ();
void graphOptionsbfsdfstopo ();
void drawButton(int x, int y, int width, int height);
void showList();
void openGraphicalWindow();
void Graphics_MENU();
void showFixedNodeDistance(int node, int distance);
void showFixedNodeDistanceagain(int node, int distance);
void showWeight ();
void fixedGraphConnection (int u, int v);
void fixedGraphConnection_1 (int u, int v);
void fixedNodeColor (int u);
void fixedNodeColor_1 (int u);
void fixedNodeColor_2 (int u);
void fixedNodeColor_3 (int u);
void fixedNodeColor_4 (int u);
void fixedNodeColor_5 (int u);
void Graph_FixedNodesAndEdges();
void Random_GraphConstruction();
void showNodeDistance(int node, int distance);
void graphConnection (int u, int v);
void graphConnection_1 (int u, int v);
void nodeColor (int u);
void nodeColor_1 (int u);
void nodeColor_2 (int u);
void nodeColor_3 (int u);
void nodeColor_4 (int u);
void nodeColor_5 (int u);
void UserInput_GraphConstruction();

void drawDirectedLine(int startX, int startY, int endX, int endY);
void showWeightDirectedGraph ();
void Directed_FixedGraph ();
void showWeight_2 (int weight, int i, int j);
void Weighted_GraphConstruction();
void drawDirectedLine_2(int startX, int startY, int endX, int endY);
void drawDirectedLine_3(int startX, int startY, int endX, int endY);

int minDistance(int distance[], bool sptSet[]);
void dijkstra(int src);
void Dijkstras_algorithm();
void printSolutionBellmanFord(int src, int distance[]);
void bellmanFord(int src);
void BellmanFord_algorithm();

void MST_Kruskals_Algorithm ();
void MST_Prims_Algorithm ();

void WeightedRandom_GraphConstruction();

void MST_Kruskals_Algorithm ();
void floyd();
void edmond();
void khanTopologicalSortWrapper();
void TarjansAlgorithm_SCC();
int karger();
void MST_Prims_Algorithm2 ();


//void floydWarshall(int dist[][vertex2]);

#endif // HEAD_H_INCLUDED
