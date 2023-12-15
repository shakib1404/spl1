#include "head.h"

vector<vector<int>> graphkar;
int vertex12, edge12;

void UserInput_GraphConstruction2(vector<vector<int>>& graph, int nodes) {
    int radius = 20;
    setlinestyle(0, 0, 1);

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
    for (int i = 0; i < nodes; i++) {
        x[i] = (i + 1) * (800 / (nodes + 1));
        y[i] = rand() % 400 + 100;
        circle(x[i], y[i], radius);
        string label = to_string(i);
        outtextxy(x[i] - radius / 2, y[i] - radius / 2, const_cast<char*>(label.c_str()));
    }

    // Wait for a delay before proceeding to the next step
    delay(1500);

    // Draw edges as lines
    for (int i = 0; i < nodes; i++) {
        for (int j = i + 1; j < nodes; j++) {
            if (graph[i][j] == 1) {
                line(x[i], y[i], x[j], y[j]);
                delay(1500);
            }
        }
    }

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
    outtextxy(240, 550, "Please press any key to continue");

    // Wait for the user to close the window
    getch();
}

// Function to find the minimum cut using Karger's Algorithm
int kargerMinCut(vector<vector<int>>& graph, vector<pair<int, int>>& nodes, vector<pair<pair<int, int>, pair<int, int>>>& edges) {
    while (graph.size() > 2) {
        // Choose a random edge
        int u = rand() % graph.size();
        int v = rand() % graph[u].size();

        // Merge vertices u and v by appending v's adjacency list to u's
        graph[u].insert(graph[u].end(), graph[v].begin(), graph[v].end());

        // Remove self-loops
        graph[u].erase(remove(graph[u].begin(), graph[u].end(), u), graph[u].end());

        // Remove vertex v from the graph
        graph.erase(graph.begin() + v);

        // Update remaining vertices to remove references to v
        for (auto& neighbors : graph) {
            for (int& neighbor : neighbors) {
                if (neighbor == v) {
                    neighbor = u;
                }
            }
        }

        // Update nodes and edges for visualization
        nodes.erase(nodes.begin() + v);
        edges.push_back({nodes[u], nodes[v]});
        UserInput_GraphConstruction2(graph, graph.size());
    }

    // The remaining edges form a cut
    return graph[0].size();
}

int karger() {
    vertex12 = fixed_NODES;
    edge12 = fixed_EDGES;

    // Initialize graphkar and copy fixed_GRAPH
    graphkar.resize(vertex12, vector<int>(vertex12, 0));
    for (int i = 0; i < vertex12; i++) {
        for (int j = 0; j < vertex12; j++) {
            graphkar[i][j] = fixed_GRAPH[i][j];
            cout<<graphkar[i][j];
        }
    }

    vector<pair<int, int>> nodes;
    vector<pair<pair<int, int>, pair<int, int>>> edges;

    int minCut = kargerMinCut(graphkar, nodes, edges);

    // Display the result
    cout << "Minimum Cut: " << minCut << endl;

    getch();
    closegraph();
}
