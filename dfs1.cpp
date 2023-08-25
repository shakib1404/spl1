#include <graphics.h>
#include <vector>
#include <cmath>
#include <cstdio>
#include <conio.h>
using namespace std;

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

void visualizeGraph(const vector<Node>& nodes, const vector<vector<int>>& adjacencyList, int currentNode) {
    cleardevice();

    // Draw edges
    for (int i = 0; i < adjacencyList.size(); ++i) {
        for (int neighbor : adjacencyList[i]) {
            line(nodes[i].x, nodes[i].y, nodes[neighbor].x, nodes[neighbor].y);
        }
    }

    // Draw nodes
    for (int i = 0; i < nodes.size(); ++i) {
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

void DFS(const vector<vector<int>>& adjacencyList, const vector<Node>& nodes, int startNode) {
    MyStack s(MAX_NODES); // Create a custom stack

    vector<bool> visited(MAX_NODES, false);

    s.push(startNode); // Push the starting node onto the stack

    while (!s.isEmpty()) {
        int currentNode = s.pop(); // Pop the top node from the stack

        if (!visited[currentNode]) {
            visited[currentNode] = true;
            visualizeGraph(nodes, adjacencyList, currentNode);
            delay(500);

            for (int neighbor : adjacencyList[currentNode]) {
                if (!visited[neighbor]) {
                    s.push(neighbor); // Push unvisited neighbors onto the stack
                }
            }
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    vector<Node> nodes = {{100, 100}, {200, 100}, {300, 100}, {100, 200}, {200, 200}, {300, 200}};
    vector<vector<int>> adjacencyList = {{1, 3}, {0, 4}, {4, 5}, {0}, {1, 2}, {2}};

    int startNode = 0;
    DFS(adjacencyList, nodes, startNode);

    delay(100000);
    closegraph();
    getch();

    return 0;
}

