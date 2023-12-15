#include "head.h"



int Graph[MAX][MAX];
char Color[MAX]; //to keep track of the Color of each node.
int Level[MAX]; //to keep track of the Level of each node.
int Parent[MAX]; //to keep track of the Parent node of each node.

void BFS_UPDATE()
{
    // settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
    // outtextxy(400, 30, "BFS");

    //Graph_FixedNodesAndEdges();

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

    int nodeCount, edgeCount;
    int sourceNode;

    if (CHOOSE == 2){
        //for Fixed Graph
        nodeCount = fixed_NODES;
        edgeCount = fixed_EDGES;

        for (int i = 0; i < nodeCount; i++){
            for (int j = 0; j < nodeCount; j++){
                Graph[i][j] = fixed_GRAPH[i][j];
            }
        }

        sourceNode = fixed_SOURCE;
    }



    else {
        //for User Input
        nodeCount = NODES;
        edgeCount = EDGES;

        for (int i = 0; i < nodeCount; i++){
            for (int j = 0; j < nodeCount; j++){
                Graph[i][j] = GRAPH[i][j];
            }
        }

        sourceNode = SOURCE;
    }



    //step-1
    for (int i = 0; i < nodeCount; ++i) {
        Color[i] = 'w';
        Level[i] = 99999999;
        Parent[i] = -1;
    }

    //step-2
    int queue[nodeCount];
    int start, end;

    start = 0;
    end = 0;
    queue[end] = sourceNode;
    end++;

    Color[sourceNode] = 'g';

    if (CHOOSE == 2) fixedNodeColor_1 (sourceNode); //for fixed graph

    else nodeColor_1 (sourceNode); // for user input graph

    delay(1500);

    Level[sourceNode] = 0;
    Parent[sourceNode] = -1;


    while (end - start > 0) { //continues until the queue is empty.
        int u = queue[start];

        for (int i = 0; i < nodeCount; ++i) {
            int v = i;

            if (Graph[u][v] != 0 && Color[v] == 'w') {

                queue[end] = v;
                end++;
                Color[v] = 'g';

                if (CHOOSE == 2) fixedGraphConnection(u, v); // for fixed graph

                else graphConnection(u, v); // for user input graph

                if (CHOOSE == 2) fixedNodeColor_1 (v); // for fixed graph

                else nodeColor_1 (v); // for user input graph

                delay(1500);

                Level[v] = Level[u] + 1;
                Parent[v] = u;
            }
        }

        start++;
        Color[u] = 'b';

        if (CHOOSE == 2) fixedNodeColor_2 (u); // for fixed graph

        else nodeColor_2 (u); // for user input graph

        delay(1500);
    }

    cout << "Level, Parent and Color of each node:" << endl;
    for (int i = 0; i < nodeCount; ++i) {

        cout << "Level[" << i << "] = " << Level[i] << endl;
        cout << "Parent[" << i << "] = " << Parent[i] << endl;
        cout << "Color[" << i << "] = " << Color[i] << endl;
        cout << endl;
    }

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
