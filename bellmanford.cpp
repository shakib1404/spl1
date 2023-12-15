#include "head.h"


//structure can be used here
int vertex1, edge1;
int graphForBellman[MAX][MAX];
int Cost[MAX][MAX];


void printSolutionBellmanFord(int src, int distance[])
{
    for (int i = 1; i < vertex1; i++)
    {
        if (distance[i] == INT_MAX)
        {
            cout << "There is no path from vertex " << src << " to vertex " << i << endl;
        }

        else
        {
            cout << "SoureVertex \t DestinationVertex \t Distance from Source" << endl;
            cout << "     " << src << " \t\t\t" << i << " \t\t\t" << distance[i] << endl;
        }
    }
}


void bellmanFord(int src)
{
    int distance[vertex1];

    // Initializes all distances as INFINITE
    for (int i = 0; i < vertex1; i++)
    {
        distance[i] = INT_MAX;
    }

    // Distance of source vertex1 from itself is always 0
    distance[src] = 0;

    //updating distance value for Source
    if (CHOOSE == 1) showFixedNodeDistanceagain(src, distance[src]); // for fixed graph
    else if (CHOOSE == 2) showNodeDistance(src, distance[src]); // for random graph
    else showNodeDistance(src, distance[src]); // for user input graph

    for (int count = 1; count <= vertex1-1; count++)
    {

        // Updating distance value of the adjacent vertices of the picked vertex1.
        for (int u = 0; u < vertex1; u++)
        {

            if (CHOOSE == 1) fixedNodeColor_3 (u); // for fixed graph
            else if (CHOOSE == 2) nodeColor_3 (u); //for random graph
            else nodeColor_3 (u); // for user input graph

            for (int v = 0; v < vertex1; v++)
            {

                if ((graphForBellman[u][v] != 0) && (distance[u] != INT_MAX) && (distance[u] + Cost[u][v] < distance[v]))
                {

                    distance[v] = distance[u] + Cost[u][v];
                    prevNodeIndex[v] = u;

                    if (CHOOSE == 1) fixedGraphConnection(u, v); // for fixed graph
                    else if (CHOOSE == 2) graphConnection(u, v); // for random graph
                    else graphConnection(u, v); // for user input graph

                    delay(500);

                    if (CHOOSE == 1) fixedNodeColor_1 (v); // for fixed graph
                    else if (CHOOSE == 2) nodeColor_1 (v); //for random graph
                    else nodeColor_1 (v); // for user input graph

                    //updating distance value
                    if (CHOOSE == 1) showFixedNodeDistanceagain(v, distance[v]); // for fixed graph
                    else if (CHOOSE == 2) showNodeDistance(v, distance[v]); // for random graph
                    else showNodeDistance(v, distance[v]); // for user input graph
                    //delay(500);
                }
            }

            delay(400);

            if (CHOOSE == 1) fixedNodeColor_2 (u); // for fixed graph
            else if (CHOOSE == 2) nodeColor_2 (u); //for random graph
            else nodeColor_2 (u); // for user input graph

            delay(1000);
        }



    }


    // Step 3: check for negative-weight cycles.  The above
    // step guarantees shortest distances if graph doesn't
    // contain negative weight cycle.  If we get a shorter
    // path, then there is a cycle.
    for (int u = 0; u < vertex1; u++)
    {
        for (int v = 0; v < vertex1; v++)
        {

            if ((graphForBellman[u][v] != 0) && (distance[u] != INT_MAX) && (distance[u] + Cost[u][v] < distance[v]))
            {

                cout << "Graph contains negative weight cycle!" << endl;
                return ; // If negative cycle is detected, simply returned
            }
        }
    }


    printSolutionBellmanFord(src, distance);
}


void BellmanFord_algorithm()
{
    // settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
    // outtextxy(400, 30, "Dijkstras");

    // Graph_FixedNodesAndEdges();

    setfillstyle(SOLID_FILL, BLACK); // to erase the line "Please press any key to continue"
    bar(230, 500, 230 + 500, 500 + 600); // draws a rectangle over the text

    circle(700, 70, 15);
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    fillellipse(700, 70, 15, 15);
    outtextxy(720, 58, "selected node");

    circle(700, 120, 15);
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(700, 120, 15, 15);
    outtextxy(720, 108, "neighbour");

    circle(700, 170, 15);
    setfillstyle(SOLID_FILL, GREEN);
    fillellipse(700, 170, 15, 15);
    outtextxy(720, 158, "shortest path");


    memset(Cost, INT_MAX, sizeof(Cost));
    memset(graphForBellman, 0, sizeof(graphForBellman));

    int sreForBellman;

    if (CHOOSE == 1)
    {
        //for Fixed Graph
        vertex1 = fixed_NODES;
        edge1 = fixed_EDGES;
        cout<<vertex1<<edge1;
        for (int i = 0; i < vertex1; i++)
        {
            for (int j = 0; j < vertex1; j++)
            {
                graphForBellman[i][j] = fixed_GRAPH[i][j];

                if (graphForBellman[i][j] != 0)
                {
                    Cost[i][j] = graphForBellman[i][j];
                }
            }
        }

        sreForBellman = SOURCE;

    }

    else if (CHOOSE == 2)
    {
        //for Random Input
        vertex1 = NODES;
        edge1 = EDGES;

        for (int i = 0; i < vertex1; i++)
        {
            for (int j = 0; j < vertex1; j++)
            {
                graphForBellman[i][j] = GRAPH[i][j];
                if (graphForBellman[i][j] != 0) Cost[i][j] = graphForBellman[i][j];
            }
        }

        sreForBellman = SOURCE;

    }

    else
    {
        //for User Input
        vertex1 = NODES;
        edge1 = EDGES;

        for (int i = 0; i < vertex1; i++)
        {
            for (int j = 0; j < vertex1; j++)
            {
                graphForBellman[i][j] = GRAPH[i][j];
                if (graphForBellman[i][j] != 0) Cost[i][j] = graphForBellman[i][j];
            }
        }

        sreForBellman = SOURCE;

    }

    // Function call
    bellmanFord(sreForBellman);


    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
    outtextxy(300, 550, "Successfully ended...");

    COUNT = 0;
    prevWindowArrow();

    int x = mousex();
    int y = mousey();
    if (ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN); // clear the mouse click event
        if (x > 50 && x < 110 && y > 50 && y < 90)
        {
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
example-1:

6
9
0 1 6
0 2 4
0 3 5
1 4 -1
2 1 -2
2 4 3
3 2 -2
3 5 -1
4 5 3
0 5

the answer will be 3 for this case

example-2:

5
8
0 1 -1
0 2 4
1 4 2
1 3 2
1 2 3
3 1 1
3 2 5
4 3 -3
0 3

the answer will be -2 for this case

example-3 (Cycle in Graph):

4
5
0 1 1
0 2 2
1 2 2
2 3 2
3 1 -5
0 3

cycle in the graph
*/
