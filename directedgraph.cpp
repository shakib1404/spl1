#include "head.h"

#define M_PI 3.14159265358979323846

int directedFixed_x[MAX], directedFixed_y[MAX];
int radiusForDirected;
int prevNodeColorForDirected;

void drawDirectedLine(int startX, int startY, int endX, int endY) {

    //setlinestyle(0, 0, 2);
    // Draw the line
    line(startX, startY, endX, endY);

    // Calculate the arrowhead position
    int arrowSize = 15;  // Adjust the size of the arrowhead as needed
    float angle = atan2(endY - startY, endX - startX);
    int arrowEndX = endX - arrowSize * cos(angle);
    int arrowEndY = endY - arrowSize * sin(angle);

    // Draw the arrowhead
    line(arrowEndX, arrowEndY, arrowEndX - arrowSize * cos(angle + M_PI / 6), arrowEndY - arrowSize * sin(angle + M_PI / 6));
    line(arrowEndX, arrowEndY, arrowEndX - arrowSize * cos(angle - M_PI / 6), arrowEndY - arrowSize * sin(angle - M_PI / 6));
}


void showWeightDirectedGraph ()
{
    int x, y;
    string label;

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

    label = to_string(5);
    x = (directedFixed_x[0] + directedFixed_x[1]) / 2 - 15;
    y = (directedFixed_y[0] + directedFixed_y[1]) / 2 - 15;
    outtextxy(x, y, const_cast<char*>(label.c_str()));
    delay(500);

    if (COUNT == 1){
      label = to_string(-3);
      x = (directedFixed_x[1] + directedFixed_x[2]) / 2;
      y = (directedFixed_y[1] + directedFixed_y[2]) / 2 - 20;
      outtextxy(x, y, const_cast<char*>(label.c_str()));
      delay(500);
    }
    else {
      label = to_string(4);
      x = (directedFixed_x[1] + directedFixed_x[2]) / 2;
      y = (directedFixed_y[1] + directedFixed_y[2]) / 2 - 20;
      outtextxy(x, y, const_cast<char*>(label.c_str()));
      delay(500);
    }

    label = to_string(3);
    x = (directedFixed_x[2] + directedFixed_x[3]) / 2 + 15;
    y = (directedFixed_y[2] + directedFixed_y[3]) / 2 - 10;
    outtextxy(x, y, const_cast<char*>(label.c_str()));
    delay(500);

    label = to_string(2);
    x = (directedFixed_x[3] + directedFixed_x[4]) / 2 + 10;
    y = (directedFixed_y[3] + directedFixed_y[4]) / 2;
    outtextxy(x, y, const_cast<char*>(label.c_str()));
    delay(500);

    if (COUNT == 1){
      label = to_string(-2);
      x = (directedFixed_x[4] + directedFixed_x[5]) / 2;
      y = (directedFixed_y[4] + directedFixed_y[5]) / 2 + 5;
      outtextxy(x, y, const_cast<char*>(label.c_str()));
      delay(500);
    }
    else{
      label = to_string(3);
      x = (directedFixed_x[4] + directedFixed_x[5]) / 2;
      y = (directedFixed_y[4] + directedFixed_y[5]) / 2 + 5;
      outtextxy(x, y, const_cast<char*>(label.c_str()));
      delay(500);
    }

    label = to_string(1);
    x = (directedFixed_x[0] + directedFixed_x[5]) / 2 - 20;
    y = (directedFixed_y[0] + directedFixed_y[5]) / 2 - 2;
    outtextxy(x, y, const_cast<char*>(label.c_str()));
    delay(500);

    label = to_string(2);
    x = (directedFixed_x[1] + directedFixed_x[5]) / 2 - 20;
    y = (directedFixed_y[1] + directedFixed_y[5]) / 2;
    outtextxy(x, y, const_cast<char*>(label.c_str()));
    delay(500);

    label = to_string(6);
    x = (directedFixed_x[1] + directedFixed_x[6]) / 2 + 10;
    y = (directedFixed_y[1] + directedFixed_y[6]) / 2 - 10;
    outtextxy(x, y, const_cast<char*>(label.c_str()));
    delay(500);

    label = to_string(5);
    x = (directedFixed_x[4] + directedFixed_x[6]) / 2 + 5;
    y = (directedFixed_y[4] + directedFixed_y[6]) / 2 - 20;
    outtextxy(x, y, const_cast<char*>(label.c_str()));
    delay(500);

    label = to_string(4);
    x = (directedFixed_x[2] + directedFixed_x[4]) / 2 + 10;
    y = (directedFixed_y[2] + directedFixed_y[4]) / 2;
    outtextxy(x, y, const_cast<char*>(label.c_str()));
    delay(500);
}


void Directed_FixedGraph ()
{

    int nodes = 7, edges = 11;

    directedFixed_NODES = nodes;
    directedFixed_EDGES = edges;

    int adj_matrix[nodes][nodes]; // Adjacency matrix to store the graph

    for (int i = 0; i < nodes; i++) {
      for (int j = 0; j < nodes; j++) {
        adj_matrix[i][j] = 0;

        directedFixed_GRAPH[i][j] = 0;
      }
    }

  //edge -> connection with vertices
    adj_matrix[0][1] = 5;
    directedFixed_GRAPH[0][1]  = 5;
    if (COUNT == 1){
      adj_matrix[1][2] = -3;
      directedFixed_GRAPH[1][2] = -3;
    }
    else{
      adj_matrix[1][2] = 4;
      directedFixed_GRAPH[1][2] = 4;
    }

    adj_matrix[2][3] = 3;
    directedFixed_GRAPH[2][3] = 3;

    adj_matrix[4][3] = 2;
    directedFixed_GRAPH[4][3] = 2;

    if(COUNT == 1) {
      adj_matrix[4][5] = -2;
      directedFixed_GRAPH[4][5] = -2;
    }
    else{
      adj_matrix[4][5] = 3;
      directedFixed_GRAPH[4][5] = 3;
    }

    adj_matrix[5][0] = 1;
    directedFixed_GRAPH[5][0] = 1;

    adj_matrix[0][5] = 1;
    directedFixed_GRAPH[0][5] = 1;

    adj_matrix[1][5] = 2;
    directedFixed_GRAPH[1][5] = 2;

    adj_matrix[6][1] = 6;
    directedFixed_GRAPH[6][1] = 6;

    adj_matrix[4][6] = 5;
    directedFixed_GRAPH[4][6] = 5;

    adj_matrix[2][4] = 4;
    directedFixed_GRAPH[2][4] = 4;

    setcolor(WHITE);
    prevNodeColorForDirected = getcolor();

    setlinestyle(0, 0, 1);

    // Draw fixed nodes as circles with numbers
    radiusForDirected = 20;

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
    string label;

    //1st node
    directedFixed_x[0] = 150;
    directedFixed_y[0] = 300;
    circle(directedFixed_x[0], directedFixed_y[0], radiusForDirected);
    label = to_string(0);
    outtextxy(directedFixed_x[0]-radiusForDirected/2, directedFixed_y[0]-radiusForDirected/2, const_cast<char*>(label.c_str()));
    delay(300);

    //2nd node
    directedFixed_x[1] = 330;
    directedFixed_y[1] = 150;
    circle(directedFixed_x[1], directedFixed_y[1], radiusForDirected);
    label = to_string(1);
    outtextxy(directedFixed_x[1]-radiusForDirected/2, directedFixed_y[1]-radiusForDirected/2, const_cast<char*>(label.c_str()));
    delay(300);

    //3rd node
    directedFixed_x[2] = 330 + 220;
    directedFixed_y[2] = 150;
    circle(directedFixed_x[2], directedFixed_y[2], radiusForDirected);
    label = to_string(2);
    outtextxy(directedFixed_x[2]-radiusForDirected/2, directedFixed_y[2]-radiusForDirected/2, const_cast<char*>(label.c_str()));
    delay(300);

    //4th node
    directedFixed_x[3] = 330 + 220 + 180;
    directedFixed_y[3] = 300;
    circle(directedFixed_x[3], directedFixed_y[3], radiusForDirected);
    label = to_string(3);
    outtextxy(directedFixed_x[3]-radiusForDirected/2, directedFixed_y[3]-radiusForDirected/2, const_cast<char*>(label.c_str()));
    delay(300);

    //5th node
    directedFixed_x[4] = 330 + 220;
    directedFixed_y[4] = 450;
    circle(directedFixed_x[4], directedFixed_y[4], radiusForDirected);
    label = to_string(4);
    outtextxy(directedFixed_x[4]-radiusForDirected/2, directedFixed_y[4]-radiusForDirected/2, const_cast<char*>(label.c_str()));
    delay(300);

    //6th node
    directedFixed_x[5] = 330;
    directedFixed_y[5] = 450;
    circle(directedFixed_x[5], directedFixed_y[5], radiusForDirected);
    label = to_string(5);
    outtextxy(directedFixed_x[5]-radiusForDirected/2, directedFixed_y[5]-radiusForDirected/2, const_cast<char*>(label.c_str()));
    delay(300);

    //7th node
    directedFixed_x[6] = 440;
    directedFixed_y[6] = 300;
    circle(directedFixed_x[6], directedFixed_y[6], radiusForDirected);
    label = to_string(6);
    outtextxy(directedFixed_x[6]-radiusForDirected/2, directedFixed_y[6]-radiusForDirected/2, const_cast<char*>(label.c_str()));

    // Wait for a delay before proceeding to the next step
    delay(1000);

    // Draw edges as lines
    for (int i = 0; i < nodes; i++) {
      for (int j = 0; j < nodes; j++) {
        if (adj_matrix[i][j] != 0) {
          drawDirectedLine(directedFixed_x[i], directedFixed_y[i], directedFixed_x[j], directedFixed_y[j]);
          delay(300);
        }
      }
    }

}
