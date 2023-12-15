#include "head.h"

const int MAX_NODES = 6;

struct Node {
    int x, y;
};

void visualizeGraph(struct Node nodes[], int adjacencyList[][MAX_NODES], int currentNode) {
    cleardevice();

    // Draw edges
    for (int i = 0; i < MAX_NODES; ++i) {
        for (int j = 0; j < MAX_NODES; ++j) {
            if (adjacencyList[i][j]) {
                line(nodes[i].x, nodes[i].y, nodes[j].x, nodes[j].y);
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

void topologicalSort(int adjacencyList[][MAX_NODES], struct Node nodes[]) {
    //initwindow(640, 480); // Initialize graphics window

    int s[MAX_NODES];
    int top = -1;

    int visited[MAX_NODES] = {0};

    for (int i = 0; i < MAX_NODES; ++i) {
        if (!visited[i]) {
            int localStack[MAX_NODES];
            int localTop = -1;
            localStack[++localTop] = i;

            while (localTop >= 0) {
                int currentNode = localStack[localTop--];

                if (!visited[currentNode]) {
                    visited[currentNode] = 1;
                    visualizeGraph(nodes, adjacencyList, currentNode);
                    delay(500);

                    for (int j = 0; j < MAX_NODES; ++j) {
                        if (adjacencyList[currentNode][j] && !visited[j]) {
                            localStack[++localTop] = j;
                        }
                    }

                    s[++top] = currentNode;
                    printf("Node %d processed\n", currentNode);
                }
            }
        }
    }

    printf("\nTopological Sort Order:\n");
    while (top >= 0) {
        int currentNode = s[top--];
        printf("%d ", currentNode);
        visualizeGraph(nodes, adjacencyList, currentNode);
        delay(500);
    }

   // delay(3000); // Delay before closing the window
   // closegraph(); // Close graphics window
}

void topologicalsort(){
    struct Node nodes[MAX_NODES] = {{200, 200}, {300, 200}, {400, 200}, {200, 300}, {300, 300}, {400, 300}};
   /* int adjacencyList[MAX_NODES][MAX_NODES] = {{0, 1, 0, 1, 0, 0},
                                              {0, 0, 0, 0, 1, 0},
                                              {0, 0, 0, 0, 1, 1},
                                              {0, 0, 0, 0, 0, 0},
                                              {0, 0, 0, 0, 0, 0},
                                              {0, 0, 0, 0, 0, 0}};*/

                                             // {0, 0, 1, 0, 0, 0}};
        int adjacencyList[MAX_NODES][MAX_NODES];
        for (int i = 0; i < MAX_NODES; i++){
            for (int j = 0; j < MAX_NODES; j++){
                adjacencyList[i][j] = GRAPH[i][j];
            }
        }

    topologicalSort(adjacencyList, nodes);

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
            //getch();
            showList();
        }
    }


}

