#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct Edge {
    int src, dest, weight;
};

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

int findParent(int vertex, int parent[]) {
    if (parent[vertex] == -1)
        return vertex;
    return findParent(parent[vertex], parent);
}

void kruskal(struct Edge edges[], int numEdges, int numVertices) {
     qsort(edges, numEdges, sizeof(struct Edge), compareEdges);

    int* parent = (int*)malloc(numVertices * sizeof(int));
    struct Edge mst[numVertices - 1];

    for (int i = 0; i < numVertices; i++)
        parent[i] = -1;

    int mstIndex = 0;
    for (int i = 0; i < numEdges; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;

        int uParent = findParent(u, parent);
        int vParent = findParent(v, parent);

        if (uParent != vParent) {
            mst[mstIndex++] = edges[i];
            parent[uParent] = vParent;
        }
    }

    printf("Minimum Spanning Tree:\n");
    int sum = 0;
    for (int i = 0; i < numVertices - 1; i++) {
        printf("%d - %d : %d\n", mst[i].src, mst[i].dest, mst[i].weight);
        sum += mst[i].weight;
    }

    printf("Total path: %d\n", sum);
    free(parent);


}

void drawFrame(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("*");
}

void animate() {
    int x = 10, y = 10;
    int dx = 1, dy = 1;

    for (int i = 0; i < 1000; i++) {
        system("cls");  // Clear the console screen
        drawFrame(x, y);
        x += dx;
        y += dy;

        if (x > 79 || x < 0)
            dx = -dx;
        if (y > 23 || y < 0)
            dy = -dy;

        Sleep(1000000);  // Pause for a short while
    }
}

int main() {
    int numVertices = 6;
    struct Edge edges[] = {
        {0, 1, 4}, {0, 2, 4}, {1, 2, 2}, {1, 0, 4}, {2, 0, 4}, {2, 1, 2},
        {2, 3, 3}, {2, 5, 2}, {2, 4, 4}, {3, 2, 3}, {3, 4, 3}, {4, 2, 4},
        {4, 3, 3}, {5, 2, 2}
    };

    int numEdges = sizeof(edges) / sizeof(edges[0]);

    kruskal(edges, numEdges, numVertices);

    animate();

    return 0;
}
