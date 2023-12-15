#include "head.h"



int nodecount, edgecount;
int sourcenode;

int graph_tp[MAX][MAX];
char colo[MAX];
int paren[MAX];
int timestamp = 0;
int finishingTime[MAX]; // Array to store finishing time of each node

bool compareFinishingTime(int a, int b) {
    return finishingTime[a] > finishingTime[b];
}

void visualizeTopologicalOrder() {
    // Sort nodes based on finishing times
    vector<int> nodes;
    for (int i = 0; i < nodecount; ++i) {
        nodes.push_back(i);
    }
    sort(nodes.begin(), nodes.end(), compareFinishingTime);

    // Visualize the topological order
    cout << "Topological Order: ";
    for (int i : nodes) {
        cout << i << " ";
        if (CHOOSE == 2) fixedNodeColor_3 (i); // for fixed graph

    else nodeColor_3 (i);
    delay(500);

    }
    cout << endl;
}




void DFS_algorithm_2(int node) { //'node' as an argument, which represents the node to be visited

    cout << "Visiting node " << node << endl;
    cout << "Parent array: [ ";

    for (int i = 0; i < nodecount; ++i) {
        cout << paren[i] << " ";
    }

    cout << "]" << endl;
    cout << "Color array: [ ";

    for (int i = 0; i < nodecount; ++i) {
        cout << colo[i] << " ";
    }

    cout << "]" << endl;
    cout << "-----------------------------------------------" << endl;

    colo[node] = 'g';

    if (CHOOSE == 2) fixedNodeColor_1 (node); // for fixed graph

    else nodeColor_1 (node); // for user input graph

    delay(1500);

    //This loop iterates over all the nodes in the graph.
    for (int i = 0; i < nodecount; ++i) {
        int adj = i;

        if (graph_tp[node][adj] != 0 && colo[adj] == 'w') {
            paren[adj] = node;

            if (CHOOSE == 2) fixedGraphConnection(i, node); // for fixed graph

            else graphConnection(i, node); // for user input graph

            DFS_algorithm_2(adj);
        }
    }

    colo[node] = 'b';
     finishingTime[node] = timestamp++; // Record finishing time


    if (CHOOSE == 2) fixedNodeColor_2 (node); // for fixed graph


    else nodeColor_2 (node); // for user input graph

    delay(1500);
}

void TOPOLOGICAL_UPDATE()
    {
    // settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
    // outtextxy(400, 30, "DFS");

    // Graph_FixedNodesAndEdges();

    setfillstyle(SOLID_FILL, BLACK); // to erase the line "Please press any key to continue"
    bar(230, 500, 230 + 500, 500 + 600); // draws a rectangle over the text

    circle(750, 70, 15);
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(750, 70, 15, 15);
    outtextxy(770, 58, "visiting");

    circle(750, 120, 15);
    setfillstyle(SOLID_FILL, GREEN);
    fillellipse(750, 120, 15, 15);
    outtextxy(770, 108, "invented");

    circle(750, 170, 15);
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    fillellipse(750, 170, 15, 15);
    outtextxy(770, 158, "dagorder");

    circle(750, 220, 15);
    setfillstyle(SOLID_FILL, BLUE);
    fillellipse(750, 220, 15, 15);
    outtextxy(770, 208, "khan order");

    if (CHOOSE == 2){
        //for Fixed Graph
        nodecount = fixed_NODES;
        edgecount = fixed_EDGES;

        for (int i = 0; i < nodecount; i++){
            for (int j = 0; j < nodecount; j++){
                graph_tp[i][j] = fixed_GRAPH[i][j];
            }
        }

        sourcenode = fixed_SOURCE;
    }


    else {
        //for User Input
        nodecount = NODES;
        edgecount = EDGES;

        for (int i = 0; i < nodecount; i++){
            for (int j = 0; j < nodecount; j++){
                graph_tp[i][j] = GRAPH[i][j];
            }
        }

        sourcenode = SOURCE;
    }


    for (int i = 0; i < nodecount; ++i) {
        colo[i] = 'w';
        paren[i] = -1;
    }


    DFS_algorithm_2(sourcenode);
    visualizeTopologicalOrder();

    paren[sourcenode] = -1;

    cout << "Final parent array: [ ";

    for (int i = 0; i < nodecount; ++i) {
        cout << paren[i] << " ";
    }

    cout << "]" << endl;
    cout << "Final color array: [ ";

    for (int i = 0; i < nodecount; ++i) {
        cout << colo[i] << " ";
    }

    cout << "]" << endl;

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
            //break;
        }
    }

}

/*
7
10
0 1
1 2
2 3
3 4
4 5
0 5
1 5
1 6
6 4
2 4
0
*/
