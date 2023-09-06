#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <cmath>
#include <unistd.h> // For sleep function

const int INF = 9999;
const int V = 5; // Number of vertices

const int circleRadius = 60; // Increased circle radius
const int lineWidth = 5;    // Width of the edges
const int delayTime = 1000; // Delay time in milliseconds between steps (adjust as needed)

void drawWiderEdge(int x1, int y1, int x2, int y2, int width) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    for (int i = 0; i < width; i++) {
        line(x1 + i, y1, x2 + i, y2);
    }
    delay(delayTime); // Add a delay after drawing each edge
}

void drawGraph(int graph[V][V], int dist[], const char* stepText) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;

    // Draw vertices and distance labels
    for (int i = 0; i < V; i++) {
        int x = centerX + static_cast<int>(circleRadius * cos(2 * 3.14159 * i / V));
        int y = centerY + static_cast<int>(circleRadius * sin(2 * 3.14159 * i / V));
        circle(x, y, 20);
        char label[2];
        label[0] = 'A' + i;
        label[1] = '\0';
        outtextxy(x - 5, y - 5, label);

        char distText[10];
        sprintf(distText, "Dist: %d", dist[i]);
        outtextxy(x - 15, y + 20, const_cast<char*>(distText));
    }

    // Print the step text
    setcolor(YELLOW);
    outtextxy(10, 200, const_cast<char*>(stepText));
}

void dijkstra(int graph[V][V], int start) {
    int dist[V];
    bool visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[start] = 0;

    drawGraph(graph, dist, "Step 0: Initialization"); // Initial visualization

    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                char stepText[50];
                sprintf(stepText, "Step %d: %c - %d", count + 1, 'A' + v, dist[v]);
                drawGraph(graph, dist, stepText); // Update visualization after each step
            }
        }
    }

    // Print the final result on the graphics window
    setcolor(YELLOW);
    outtextxy(10, 10, "Final Result (Vertex - Distance from Source):");
    for (int i = 0; i < V; i++) {
        char result[50];
        sprintf(result, "%c - %d", 'A' + i, dist[i]);
        outtextxy(10, 30 + i * 20, const_cast<char*>(result));
    }
}

int main() {
    int graph[V][V] = {
        {0, 4, INF, INF, 5},
        {4, 0, 2, 7, INF},
        {INF, 2, 0, 6, INF},
        {INF, 7, 6, 0, 3},
        {5, INF, INF, 3, 0}
    };

    int startVertex = 0; // Starting vertex 'A'
    dijkstra(graph, startVertex);

    delay(5000);
    getch();
    // Delay before closing the graph window
    closegraph();
    getch();

    return 0;
}

