

#include "head.h"
int vertex10, edge10;
int graph_Ed[MAX][MAX];
int rGraph[MAX][MAX];


int edmondkarp(int s,int t)
{

    int u,v;

    int x, y;
    string label;

    for(int u=0; u<MAX; u++)
        for(int v=0; v<MAX; v++)
            rGraph[u][v]=graph_Ed[u][v];

    int parent[MAX];
    int max_flow=0;

    while(true)
    {



        bool visited[MAX];
        memset(visited,0,sizeof(visited));

        queue<int> q;
        q.push(s);
        visited[s]=true;
        parent[s]=-1;
        bool foundSink=false;

        while(!q.empty())
        {

            u=q.front();
            q.pop();


            for(v=0; v<MAX; v++)
            {

                if(visited[v]==false && rGraph[u][v]>0)
                {

                    if(v==t)
                    {
                        parent[v]=u;
                        foundSink=true;
                        break;
                    }

                    q.push(v);
                    parent[v]=u;
                    visited[v]=true;
                }
            }
            if(foundSink)
                break;

        }
        if(!foundSink)
            break;

        int path_flow=INT_MAX;
        for(v=t; v!=s; v=parent[v])
        {

            u=parent[v];
            if (CHOOSE == 1) fixedGraphConnection_1(u,v); // for fixed graph
            else if (CHOOSE == 2) graphConnection_1(u,v); // for random graph
            else graphConnection_1(u,v); // for user input graph

            drawDirectedLine_2(directedFixed_x[u], directedFixed_y[u], directedFixed_x[v], directedFixed_y[v]);
            path_flow=min(path_flow,rGraph[u][v]);
        }

        for(v=t; v!=s; v=parent[v])
        {

            u=parent[v];



            rGraph[u][v]-=path_flow;
            if (rGraph[u][v] >= 0)
            {
                // Calculate the midpoint of the edge for label placement
                x = (directedFixed_x[u] + directedFixed_x[v]) / 2;
                y = (directedFixed_y[u] + directedFixed_y[v]) / 2;
                setcolor(LIGHTCYAN);
                label = to_string(rGraph[u][v]);
                outtextxy(x, y, const_cast<char*>(label.c_str()));
                delay(500);
            }

            rGraph[v][u]+=path_flow;
            drawDirectedLine_3(directedFixed_x[v], directedFixed_y[v], directedFixed_x[u], directedFixed_y[u]);
            if (rGraph[v][u] >= 0)
            {
                // Calculate the midpoint of the edge for label placement
                x = (directedFixed_x[u] + directedFixed_x[v]) / 2+20;
                y = (directedFixed_y[u] + directedFixed_y[v]) / 2-20;
                setcolor(YELLOW);
                label = to_string(rGraph[v][u]);
                outtextxy(x, y, const_cast<char*>(label.c_str()));
                delay(500);
            }

        }

        max_flow += path_flow;
        outtextxy(700, 150, const_cast<char*>(("max flow: " + std::to_string(max_flow)).c_str()));


    }


    return max_flow;
}



void edmond()
{

    memset(graph_Ed, 0, sizeof(graph_Ed));

    //  int sreForBellman;

    if (CHOOSE == 1)
    {
        //for Fixed Graph
        vertex10 = directedFixed_NODES;
        edge10 = directedFixed_EDGES;
        cout<<vertex10<<edge10;
        for (int i = 0; i < vertex10; i++)
        {
            for (int j = 0; j < vertex10; j++)
            {
                graph_Ed[i][j] = directedFixed_GRAPH[i][j];


            }
        }
    }

    else if (CHOOSE == 2)
    {
        //for Random Input
        vertex10 = NODES;
        edge10 = EDGES;

        for (int i = 0; i < vertex10; i++)
        {
            for (int j = 0; j < vertex10; j++)
            {
                graph_Ed[i][j] = GRAPH[i][j];

            }
        }



    }
    else
    {
        //for User Input
        vertex10 = NODES;
        edge1 = EDGES;

        for (int i = 0; i < vertex10; i++)
        {
            for (int j = 0; j < vertex10; j++)
            {
                graph_Ed[i][j] = GRAPH[i][j];
                cout<< graph_Ed[i][j];

            }
        }



    }

    cout<< "maximum possible flow is:"<<edmondkarp(0,3);

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
    outtextxy(200, 550, "                  Successfully ended...            ");

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
