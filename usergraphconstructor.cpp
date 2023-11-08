#include "head.h"

//int x[MAX], y[MAX];

void showNodeDistance(int node, int distance)
{
    string label;

    label = to_string(distance);
    setcolor(LIGHTCYAN);
    outtextxy(x[node]+10, y[node]-40, const_cast<char*>(label.c_str()));
    delay(500);
}

void graphConnection (int u, int v)
{
    setcolor(YELLOW);
    setlinestyle(0, 0, 2);
    line(x[u], y[u], x[v], y[v]);
    delay(1600);
}

void graphConnection_1 (int u, int v)
{
    setcolor(GREEN);
    setlinestyle(0, 0, 2);
    line(x[u], y[u], x[v], y[v]);
    delay(1600);
}

void nodeColor (int u)
{
    setcolor(YELLOW);

    int radius = 20;
    circle(x[u], y[u], radius);
    string label = to_string(u);
    outtextxy(x[u]-radius/2, y[u]-radius/2, const_cast<char*>(label.c_str()));
    delay(1000);
}

void nodeColor_1 (int u)
{
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(x[u], y[u], 20, 20);

    string label = to_string(u);
    int textWidth = textwidth(const_cast<char*>(label.c_str()));
    int textHeight = textheight(const_cast<char*>(label.c_str()));

    setcolor(WHITE);
    outtextxy(x[u]-textWidth/2, y[u]-textHeight/2, const_cast<char*>(label.c_str()));
    //delay(1000);
}

void nodeColor_2 (int u)
{
    setfillstyle(SOLID_FILL, GREEN);
    fillellipse(x[u], y[u], 20, 20);

    string label = to_string(u);
    int textWidth = textwidth(const_cast<char*>(label.c_str()));
    int textHeight = textheight(const_cast<char*>(label.c_str()));

    setcolor(WHITE);
    outtextxy(x[u]-textWidth/2, y[u]-textHeight/2, const_cast<char*>(label.c_str()));
    //delay(1000);
}

void nodeColor_3 (int u)
{
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    fillellipse(x[u], y[u], 20, 20);

    string label = to_string(u);
    int textWidth = textwidth(const_cast<char*>(label.c_str()));
    int textHeight = textheight(const_cast<char*>(label.c_str()));

    setcolor(WHITE);
    outtextxy(x[u]-textWidth/2, y[u]-textHeight/2, const_cast<char*>(label.c_str()));
    //delay(1000);
}

void UserInput_GraphConstruction()
{
  int nodes, edges, srcNode;

  freopen("graph_input_BFS_DFS.txt", "r", stdin);

  cout << "Enter the number of nodes: ";
  cin >> nodes;
  NODES = nodes;

  cout << "Enter the number of edges: ";
  cin >> edges;
  EDGES = edges;

  int adj_matrix[nodes][nodes]; // Adjacency matrix to store the graph

  for (int i = 0; i < nodes; i++) {
    for (int j = 0; j < nodes; j++) {
      adj_matrix[i][j] = 0;
      GRAPH[i][j] = 0;
    }
  }

  int u, v;
  cout << "Enter edges (u v):\n";

  for (int i = 0; i < edges; i++) {
    cin >> u >> v;

    adj_matrix[u][v] = 1;
    adj_matrix[v][u] = 1; // we have to Comment this line for directed graph
    GRAPH[u][v] = GRAPH[v][u] = 1;
  }

  cout << "Enter the source node: ";
  cin >> srcNode;
  SOURCE = srcNode;

//Graphical Works

  // Draw nodes as circles with numbers
  int radius = 20;
  setlinestyle(0, 0, 1);

  settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
  for (int i = 0; i < nodes; i++) {
    x[i] = (i+1) * (800 / (nodes+1));
    y[i] = rand() % 400 + 100;
    circle(x[i], y[i], radius);
    string label = to_string(i);
    outtextxy(x[i]-radius/2, y[i]-radius/2, const_cast<char*>(label.c_str()));
  }

  // Wait for a delay before proceeding to the next step
  delay(1500);

  // Draw edges as lines
  for (int i = 0; i < nodes; i++) {
    for (int j = i+1; j < nodes; j++) {
      if (adj_matrix[i][j] == 1) {
        line(x[i], y[i], x[j], y[j]);
        delay(1500);
      }
    }
  }

  settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
  outtextxy(240, 550, "Please press any key to continue");

  // Wait for user to close the window
  getch();

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
