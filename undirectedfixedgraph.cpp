#include "head.h"
int COUNT = 0;
int fixed_x[MAX], fixed_y[MAX];
int radius;
int prevColor;
int fixed_NODES, fixed_EDGES;
int fixed_U, fixed_V, fixed_WEIGHT;
int fixed_GRAPH[MAX][MAX];
int fixed_SOURCE = 0;
void showFixedNodeDistance(int node, int distance)
{
    string label;

    label = to_string(distance);
    setcolor(LIGHTCYAN);
    outtextxy(fixed_x[node]+6, fixed_y[node]-40, const_cast<char*>(label.c_str()));
    delay(500);

    setcolor(prevColor);
}

void showWeight ()
{
    int x, y;
    string label;

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

    label = to_string(5);
    x = (fixed_x[0] + fixed_x[1]) / 2 - 15;
    y = (fixed_y[0] + fixed_y[1]) / 2 - 15;
    outtextxy(x, y, const_cast<char*>(label.c_str()));
    delay(500);

    if (COUNT == 1){
      label = to_string(-3);
      x = (fixed_x[1] + fixed_x[2]) / 2;
      y = (fixed_y[1] + fixed_y[2]) / 2 - 20;
      outtextxy(x, y, const_cast<char*>(label.c_str()));
      delay(500);
    }
    else {
      label = to_string(4);
      x = (fixed_x[1] + fixed_x[2]) / 2;
      y = (fixed_y[1] + fixed_y[2]) / 2 - 20;
      outtextxy(x, y, const_cast<char*>(label.c_str()));
      delay(500);
    }

    label = to_string(3);
    x = (fixed_x[2] + fixed_x[3]) / 2 + 15;
    y = (fixed_y[2] + fixed_y[3]) / 2 - 10;
    outtextxy(x, y, const_cast<char*>(label.c_str()));
    delay(500);

    label = to_string(2);
    x = (fixed_x[3] + fixed_x[4]) / 2 + 10;
    y = (fixed_y[3] + fixed_y[4]) / 2;
    outtextxy(x, y, const_cast<char*>(label.c_str()));
    delay(500);

    if (COUNT == 1){
      label = to_string(-2);
      x = (fixed_x[4] + fixed_x[5]) / 2;
      y = (fixed_y[4] + fixed_y[5]) / 2 + 5;
      outtextxy(x, y, const_cast<char*>(label.c_str()));
      delay(500);
    }
    else{
      label = to_string(3);
      x = (fixed_x[4] + fixed_x[5]) / 2;
      y = (fixed_y[4] + fixed_y[5]) / 2 + 5;
      outtextxy(x, y, const_cast<char*>(label.c_str()));
      delay(500);
    }

    label = to_string(1);
    x = (fixed_x[0] + fixed_x[5]) / 2 - 20;
    y = (fixed_y[0] + fixed_y[5]) / 2 - 2;
    outtextxy(x, y, const_cast<char*>(label.c_str()));
    delay(500);

    label = to_string(2);
    x = (fixed_x[1] + fixed_x[5]) / 2 - 20;
    y = (fixed_y[1] + fixed_y[5]) / 2;
    outtextxy(x, y, const_cast<char*>(label.c_str()));
    delay(500);

    label = to_string(6);
    x = (fixed_x[1] + fixed_x[6]) / 2 + 10;
    y = (fixed_y[1] + fixed_y[6]) / 2 - 10;
    outtextxy(x, y, const_cast<char*>(label.c_str()));
    delay(500);

    label = to_string(5);
    x = (fixed_x[4] + fixed_x[6]) / 2 + 5;
    y = (fixed_y[4] + fixed_y[6]) / 2 - 20;
    outtextxy(x, y, const_cast<char*>(label.c_str()));
    delay(500);

    label = to_string(4);
    x = (fixed_x[2] + fixed_x[4]) / 2 + 10;
    y = (fixed_y[2] + fixed_y[4]) / 2;
    outtextxy(x, y, const_cast<char*>(label.c_str()));
    delay(500);
}

void fixedGraphConnection (int u, int v)
{
    setcolor(YELLOW);
    setlinestyle(0, 0, 2);
    line(fixed_x[u], fixed_y[u], fixed_x[v], fixed_y[v]);
    delay(1600);

    setcolor(prevColor);
}

void fixedGraphConnection_1 (int u, int v)
{
    setcolor(GREEN);
    setlinestyle(0, 0, 2);
    line(fixed_x[u], fixed_y[u], fixed_x[v], fixed_y[v]);
    delay(1600);

    setcolor(prevColor);
}

void fixedNodeColor (int u)
{
    setcolor(YELLOW);

    string label = to_string(u);
    outtextxy(fixed_x[u]-radius/2, fixed_y[u]-radius/2, const_cast<char*>(label.c_str()));
    delay(1000);

    setcolor(prevColor);
}

void fixedNodeColor_1 (int u)
{
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(fixed_x[u], fixed_y[u], 20, 20);

    string label = to_string(u);
    int textWidth = textwidth(const_cast<char*>(label.c_str()));
    int textHeight = textheight(const_cast<char*>(label.c_str()));

    setcolor(WHITE);
    outtextxy(fixed_x[u]-textWidth/2, fixed_y[u]-textHeight/2, const_cast<char*>(label.c_str()));
    //delay(1000);
}

void fixedNodeColor_2 (int u)
{
    setfillstyle(SOLID_FILL, GREEN);
    fillellipse(fixed_x[u], fixed_y[u], 20, 20);

    string label = to_string(u);
    int textWidth = textwidth(const_cast<char*>(label.c_str()));
    int textHeight = textheight(const_cast<char*>(label.c_str()));

    setcolor(WHITE);
    outtextxy(fixed_x[u]-textWidth/2, fixed_y[u]-textHeight/2, const_cast<char*>(label.c_str()));
    //delay(1000);
}

void fixedNodeColor_3 (int u)
{
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    fillellipse(fixed_x[u], fixed_y[u], 20, 20);

    string label = to_string(u);
    int textWidth = textwidth(const_cast<char*>(label.c_str()));
    int textHeight = textheight(const_cast<char*>(label.c_str()));

    setcolor(WHITE);
    outtextxy(fixed_x[u]-textWidth/2, fixed_y[u]-textHeight/2, const_cast<char*>(label.c_str()));
    //delay(1000);
}

void Graph_FixedNodesAndEdges() {

    int nodes = 7, edges = 10;

    fixed_NODES = nodes;
    fixed_EDGES = edges;

    int adj_matrix[nodes][nodes]; // Adjacency matrix to store the graph

    for (int i = 0; i < nodes; i++) {
      for (int j = 0; j < nodes; j++) {
        adj_matrix[i][j] = 0;

        fixed_GRAPH[i][j] = 0;
      }
    }

  //edge -> connection with vertices
    adj_matrix[0][1] = 5;
    adj_matrix[1][0] = 5;  // we have to Comment this line for directed graph
    fixed_GRAPH[0][1] = fixed_GRAPH[1][0] = 5;

    if (COUNT == 1){
      adj_matrix[1][2] = -3;
      adj_matrix[2][1] = -3;  // we have to Comment this line for directed fixed_GRAPH
      fixed_GRAPH[1][2] = fixed_GRAPH[2][1] = -3;
    }
    else{
      adj_matrix[1][2] = 4;
      adj_matrix[2][1] = 4;  // we have to Comment this line for directed fixed_GRAPH
      fixed_GRAPH[1][2] = fixed_GRAPH[2][1] = 4;
    }


    adj_matrix[2][3] = 3;
    adj_matrix[3][2] = 3;  // we have to Comment this line for directed fixed_GRAPH
    fixed_GRAPH[2][3] = fixed_GRAPH[3][2] = 3;

    adj_matrix[3][4] = 2;
    adj_matrix[4][3] = 2;  // we have to Comment this line for directed fixed_GRAPH
    fixed_GRAPH[3][4] = fixed_GRAPH[4][3] = 2;

    if(COUNT == 1) {
      adj_matrix[4][5] = -2;
    adj_matrix[5][4] = -2;  // we have to Comment this line for directed fixed_GRAPH
    fixed_GRAPH[4][5] = fixed_GRAPH[5][4] = -2;
    }
    else{
      adj_matrix[4][5] = 3;
      adj_matrix[5][4] = 3;  // we have to Comment this line for directed fixed_GRAPH
      fixed_GRAPH[4][5] = fixed_GRAPH[5][4] = 3;
    }

    adj_matrix[0][5] = 1;
    adj_matrix[5][0] = 1;  // we have to Comment this line for directed fixed_GRAPH
    fixed_GRAPH[0][5] = fixed_GRAPH[5][0] = 1;

    adj_matrix[1][5] = 2;
    adj_matrix[5][1] = 2;  // we have to Comment this line for directed fixed_GRAPH
    fixed_GRAPH[1][5] = fixed_GRAPH[5][1] = 2;

    adj_matrix[1][6] = 6;
    adj_matrix[6][1] = 6;  // we have to Comment this line for directed fixed_GRAPH
    fixed_GRAPH[1][6] = fixed_GRAPH[6][1] = 6;

    adj_matrix[6][4] = 5;
    adj_matrix[4][6] = 5;  // we have to Comment this line for directed fixed_GRAPH
    fixed_GRAPH[6][4] = fixed_GRAPH[4][6] = 5;

    adj_matrix[2][4] = 4;
    adj_matrix[4][2] = 4;  // we have to Comment this line for directed fixed_GRAPH
    fixed_GRAPH[2][4] = fixed_GRAPH[4][2] = 4;

    setcolor(WHITE);
    prevColor = getcolor();

    setlinestyle(0, 0, 1);

    // Draw fixed nodes as circles with numbers
    radius = 20;

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
    string label;

    //1st node
    fixed_x[0] = 150;
    fixed_y[0] = 300;
    circle(fixed_x[0], fixed_y[0], radius);
    label = to_string(0);
    outtextxy(fixed_x[0]-radius/2, fixed_y[0]-radius/2, const_cast<char*>(label.c_str()));
    delay(300);

    //2nd node
    fixed_x[1] = 330;
    fixed_y[1] = 150;
    circle(fixed_x[1], fixed_y[1], radius);
    label = to_string(1);
    outtextxy(fixed_x[1]-radius/2, fixed_y[1]-radius/2, const_cast<char*>(label.c_str()));
    delay(300);

    //3rd node
    fixed_x[2] = 330 + 220;
    fixed_y[2] = 150;
    circle(fixed_x[2], fixed_y[2], radius);
    label = to_string(2);
    outtextxy(fixed_x[2]-radius/2, fixed_y[2]-radius/2, const_cast<char*>(label.c_str()));
    delay(300);

    //4th node
    fixed_x[3] = 330 + 220 + 180;
    fixed_y[3] = 300;
    circle(fixed_x[3], fixed_y[3], radius);
    label = to_string(3);
    outtextxy(fixed_x[3]-radius/2, fixed_y[3]-radius/2, const_cast<char*>(label.c_str()));
    delay(300);

    //5th node
    fixed_x[4] = 330 + 220;
    fixed_y[4] = 450;
    circle(fixed_x[4], fixed_y[4], radius);
    label = to_string(4);
    outtextxy(fixed_x[4]-radius/2, fixed_y[4]-radius/2, const_cast<char*>(label.c_str()));
    delay(300);

    //6th node
    fixed_x[5] = 330;
    fixed_y[5] = 450;
    circle(fixed_x[5], fixed_y[5], radius);
    label = to_string(5);
    outtextxy(fixed_x[5]-radius/2, fixed_y[5]-radius/2, const_cast<char*>(label.c_str()));
    delay(300);

    //7th node
    fixed_x[6] = 440;
    fixed_y[6] = 300;
    circle(fixed_x[6], fixed_y[6], radius);
    label = to_string(6);
    outtextxy(fixed_x[6]-radius/2, fixed_y[6]-radius/2, const_cast<char*>(label.c_str()));

    // Wait for a delay before proceeding to the next step
    delay(1000);

    // Draw edges as lines
    for (int i = 0; i < nodes; i++) {
      for (int j = i+1; j < nodes; j++) {
        if (adj_matrix[i][j] != 0) {
          line(fixed_x[i], fixed_y[i], fixed_x[j], fixed_y[j]);
          delay(300);
        }
      }
    }


}

