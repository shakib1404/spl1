#include "head.h"
#include <graphics.h>

const int MAX_NODES = 6;

struct Node {
    int x, y;
};

struct MyStack {
    int top, size;
    int* items;

    MyStack(int maxSize) {
        top = -1;
        size = maxSize;
        items = new int[size];
    }

    void push(int value) {
        if (top == size - 1) {
            return; // Stack is full
        }
        top++;
        items[top] = value;
    }

    int pop() {
        if (top == -1) {
            return -1; // Stack is empty
        }
        int item = items[top];
        top--;
        return item;
    }

    bool isEmpty() {
        return top == -1;
    }
};

void visualizeGraph(const Node nodes[], int adjacencyList[MAX_NODES][MAX_NODES], int currentNode) {
    cleardevice();

    // Draw edges
    for (int i = 0; i < MAX_NODES; ++i) {
        for (int neighbor = 0; neighbor < MAX_NODES; ++neighbor) {
            if (adjacencyList[i][neighbor] == 1) {
                line(nodes[i].x, nodes[i].y, nodes[neighbor].x, nodes[neighbor].y);
            }
        }
    }

    // Draw nodes
    for (int i = 0; i < MAX_NODES; ++i) {
        circle(nodes[i].x, nodes[i].y, 20);
        char label[2];
        sprintf(label, "%d", i);
        outtextxy(nodes[i].x - 5, nodes[i].y - 5, label);
    }

    // Highlight current node
    setcolor(YELLOW);
    circle(nodes[currentNode].x, nodes[currentNode].y, 22);
    setcolor(WHITE);
}

void DFS1(int adjacencyList[MAX_NODES][MAX_NODES], Node nodes[MAX_NODES], int startNode) {
    MyStack s(MAX_NODES); // Create a custom stack

    int visited[MAX_NODES] = {0}; // 0 for unvisited, 1 for visited

    s.push(startNode); // Push the starting node onto the stack

    while (!s.isEmpty()) {
        int currentNode = s.pop(); // Pop the top node from the stack

        if (!visited[currentNode]) {
            visited[currentNode] = 1;
            visualizeGraph(nodes, adjacencyList, currentNode);
            delay(500);

            for (int neighbor = 0; neighbor < MAX_NODES; ++neighbor) {
                if (adjacencyList[currentNode][neighbor] == 1 && !visited[neighbor]) {
                    s.push(neighbor); // Push unvisited neighbors onto the stack
                }
            }
        }
    }
}

void DFS() {
   // int gd = DETECT, gm;
  //  initgraph(&gd, &gm, "");

    Node nodes[MAX_NODES] = {{200, 200}, {300, 200}, {400, 200}, {200, 300}, {300, 300}, {400, 300}};
    /*int adjacencyList[MAX_NODES][MAX_NODES] = {{0, 1, 0, 1, 0, 0},
                                               {1, 0, 0, 0, 1, 0},
                                               {0, 0, 0, 0, 1, 1},
                                               {1, 0, 0, 0, 0, 0},
                                               {0, 1, 1, 0, 0, 0},
                                               {0, 0, 1, 0, 0, 0}};*/

        int adjacencyList[MAX_NODES][MAX_NODES];
        for (int i = 0; i < MAX_NODES; i++){
            for (int j = 0; j < MAX_NODES; j++){
                adjacencyList[i][j] = GRAPH[i][j];
            }
        }

    int startNode = 0;
    DFS1(adjacencyList, nodes, startNode);

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
    outtextxy(300, 550, "Successfully ended...");
      prevWindowArrow();

    int x = mousex();
    int y = mousey();
    if (ismouseclick(WM_LBUTTONDOWN)) {
        clearmouseclick(WM_LBUTTONDOWN); // clear the mouse click event
        if (x > 50 && x < 110 && y > 50 && y < 90) {
            // button was clicked
            cleardevice();
            delay(100);
            showList();
        }
    }

    //delay(100000);
   // closegraph();
}
