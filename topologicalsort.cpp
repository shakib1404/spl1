#include <graphics.h>
#include <vector>
#include <cmath>
#include <cstdio>
#include <stack>
#include <conio.h>
#include<iostream >
using namespace std;

const int MAX_NODES = 6;

struct Node {
    int x, y;
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

void topologicalSort(const vector<vector<int>>& adjacencyList, const vector<Node>& nodes) {
    initwindow(640, 480); // Initialize graphics window

    stack<int> s; // Using std::stack

    vector<bool> visited(MAX_NODES, false);

    for (int i = 0; i < nodes.size(); ++i) {
        if (!visited[i]) {
            stack<int> localStack;
            localStack.push(i);

            while (!localStack.empty()) {
                int currentNode = localStack.top();
                localStack.pop();

                if (!visited[currentNode]) {
                    visited[currentNode] = true;
                    visualizeGraph(nodes, adjacencyList, currentNode);
                    delay(500);

                    for (int neighbor : adjacencyList[currentNode]) {
                        if (!visited[neighbor]) {
                            localStack.push(neighbor);
                        }
                    }

                    s.push(currentNode); // Push to main stack after visiting all neighbors
                    cout << "Node " << currentNode << " processed\n";
                }
            }
        }
    }

    cout << "\nTopological Sort Order:\n";
    while (!s.empty()) {
        int currentNode = s.top();
        s.pop();
        cout << currentNode << " ";
        visualizeGraph(nodes, adjacencyList, currentNode);
        delay(500);
    }

    delay(3000); // Delay before closing the window
    closegraph(); // Close graphics window
}

int main() {
    vector<Node> nodes = {{100, 100}, {200, 100}, {300, 100}, {100, 200}, {200, 200}, {300, 200}};
    vector<vector<int>> adjacencyList = {{1, 3}, {4}, {4, 5}, {0}, {1, 2}, {2}};

    topologicalSort(adjacencyList, nodes);

    return 0;
}
