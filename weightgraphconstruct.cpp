#include "head.h"

//int x[MAX], y[MAX];

void showWeight_2 (int weight, int i, int j)
{
    int x1, y1;
    string label;

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

    label = to_string(weight);
    x1 = (x[i] + x[j]) / 2 - 25;
    y1 = (y[i] + y[j]) / 2 - 25;
    outtextxy(x1, y1, const_cast<char*>(label.c_str()));
    delay(500);
}

void Weighted_GraphConstruction()
{
  int nodesWeighted, edgesWeighted, srcNodeWeighted;

  freopen("graph_input_weighted.txt", "r", stdin);

  cout << "Enter the number of nodes: ";
  cin >> nodesWeighted;
  NODES = nodesWeighted;

  cout << "Enter the number of edges: ";
  cin >> edgesWeighted;
  EDGES = edgesWeighted;

  int adj_matrix[nodesWeighted][nodesWeighted]; // Adjacency matrix to store the graph

  for (int i = 0; i < nodesWeighted; i++) {
    for (int j = 0; j < nodesWeighted; j++) {
      adj_matrix[i][j] = 0;
      GRAPH[i][j] = 0;
    }
  }

  int u, v;
  cout << "Enter edges (u v) and it's weight:\n";

  for (int i = 0; i < edgesWeighted; i++) {
    cin >> u >> v;
    cin >> adj_matrix[u][v]; //weight

    adj_matrix[v][u] = adj_matrix[u][v]; // we have to Comment this line for directed graph

    GRAPH[u][v] = GRAPH[v][u] = adj_matrix[u][v];


  }

//Graphical Works

  // Draw nodes as circles with numbers
  int radius = 20;

  settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
  for (int i = 0; i < nodesWeighted; i++) {
    x[i] = (i+1) * (800 / (nodesWeighted+1));
    y[i] = rand() % 400 + 100;
    circle(x[i], y[i], radius);
    string label = to_string(i);
    outtextxy(x[i]-radius/2, y[i]-radius/2, const_cast<char*>(label.c_str()));
  }

  // Wait for a delay before proceeding to the next step
  delay(1500);

  // Draw edges as lines
  for (int i = 0; i < nodesWeighted; i++) {
    for (int j = i+1; j < nodesWeighted; j++) {
      if (adj_matrix[i][j] != 0) {
        line(x[i], y[i], x[j], y[j]);
        delay(1500);

        showWeight_2(adj_matrix[i][j], i, j);
      }
    }
  }

}

/*
9
14
0 1
1 2
2 3
3 4
4 5
5 6
6 7
7 8
0 7
1 7
2 8
6 8
2 5
3 5
*/
