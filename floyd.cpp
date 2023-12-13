#include "head.h"



const int INF=1e9;

vector<vector<int>> graph(100, vector<int>(100, INF));
int vertex9, edge9;


void floyd()
{

    setfillstyle(SOLID_FILL, BLACK); // to erase the line "Please press any key to continue"
    bar(230, 500, 230 + 500, 500 + 600); // draws a rectangle over the text

    circle(700, 70, 15);
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    fillellipse(700, 70, 15, 15);
    outtextxy(720, 58, "selected node");

    circle(700, 120, 15);
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(700, 120, 15, 15);
    outtextxy(720, 108, "source");

    circle(700, 170, 15);
    setfillstyle(SOLID_FILL, GREEN);
    fillellipse(700, 170, 15, 15);
    outtextxy(720, 158, "destination");


    /* vector<vector<int>> graph= { {0,5,INF,10},
                                 {INF,0,3,INF},
                                 {INF,INF,0,1},
                                 {INF,INF,INF,0}
                              };*/
    if (CHOOSE == 1)
    {
        //for Fixed Graph
        vertex9 =fixed_NODES;
        edge9= fixed_EDGES;
        cout<<vertex9<<edge9;

        for (int i = 0; i < vertex9; i++)
        {
            for (int j = 0; j < vertex9; j++)
            {
                graph[i][j] = fixed_GRAPH[i][j];
               // cout<<graph[i][j];
                if(graph[i][j]==0)
                    graph[i][j]=INF;
                   // if(i==j)
                     //   graph[i][j]==0;


            }
           // cout<<endl;
        }
    }

    else if (CHOOSE == 2)
    {
        //for Random Input
        vertex9 = NODES;
        edge9 = EDGES;

        for (int i = 0; i < vertex9; i++)
        {
            for (int j = 0; j < vertex9; j++)
            {
                graph[i][j] = GRAPH[i][j];
                if(graph[i][j]==0)
                    graph[i][j]=INF;

            }
        }


    }
    else
    {
        //for User Input
        vertex9 = NODES;
        edge9 = EDGES;

        for (int i = 0; i < vertex9; i++)
        {
            for (int j = 0; j < vertex9; j++)
            {
                graph[i][j] = GRAPH[i][j];
                if(graph[i][j]==0)
                    graph[i][j]=INF;

            }
        }



    }





    int n = vertex9;//graph.size();
   // cout<<n;


    vector<vector<int>> dist = graph;

    vector<vector<int>> next(n, vector<int>(n, -1));
     // Keep track of next vertex for path reconstruction
     //updating distance value for Source
    if (CHOOSE == 1) showFixedNodeDistance(0, 0); // for fixed graph
    else if (CHOOSE == 2) showNodeDistance(0,0); // for random graph
    else showNodeDistance(0,0); // for user input graph

    for(int k = 0; k < n; k++)
    {
        if (CHOOSE == 1) fixedNodeColor_3 (k); // for fixed graph
        else if (CHOOSE == 2) nodeColor_3 (k); //for random graph
        else nodeColor_3 (k); // for user input graph

        delay(1000);
        for(int i = 0; i < n; i++)
        {

                if (CHOOSE == 1) fixedNodeColor_1 (i); // for fixed graph
                else if (CHOOSE == 2) nodeColor_1 (i); //for random graph
                else nodeColor_1 (i); // for user input graph
                delay(500);
            for(int j = 0; j < n; j++)
            {
                 if (CHOOSE == 1) fixedNodeColor_2 (j); // for fixed graph
        else if (CHOOSE == 2) nodeColor_2 (j); //for random graph
        else nodeColor_2 (j);
        // for user input graph
        delay(500);
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = k; // Update next vertex
                     //updating distance value
                if (CHOOSE == 1) showFixedNodeDistance(i,j); // for fixed graph
                else if (CHOOSE == 2) showNodeDistance(i,j); // for random graph
                else showNodeDistance(i,j);
                }

                 if (CHOOSE == 1) fixedNodeColor_4 (j); // for fixed graph
        else if (CHOOSE == 2) nodeColor_4 (j); //for random graph
        else nodeColor_4 (j);
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i != j)
            {
                cout << "Shortest path from vertex " << i << " to " << j << ": ";
                int u = i, v = j;
                while (next[u][v] != -1)
                {
                    cout << u << " -> ";
                    u = next[u][v];
                }
                cout << u << " -> " << v << " (Distance: ";
                if (dist[i][j] == INF)
                    cout << "INF";
                else
                    cout << dist[i][j];
                cout << ")" << endl;
            }
        }
    }

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
    outtextxy(300, 550, "Successfully ended...");

    COUNT = 0;
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
