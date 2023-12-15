#include "head.h"


int grapH[MAX][MAX];
int nodes_P, edges_P;

int selectMinVertex (vector<int>& value, vector<bool>& setMST)
{
	int minimum = INT_MAX;
	int vertex;

	for (int i = 0; i < nodes_P; i++)
	{
		if (setMST[i] == false && value[i] < minimum)
		{
			vertex = i;
			minimum = value[i];
		}
	}

	return vertex;
}

int findMST (int grapH[MAX][MAX])
{
	int parent[nodes_P], sum = 0;
	vector<int> value (nodes_P, INT_MAX); //used edged relaxation
	vector<bool> setMST (nodes_P, false); //TRUE -> vertex is included in MST

	//Assuming start point as Node -> 0
	parent[0] = -1; // start node has no parent
	value[0] = 0; // start node has value = 0 to get picked 1st

	//from MST with (v-1) edges
	for (int i = 0; i < nodes_P-1; i++)
	{
		//select best vertex applying greedy method
		int u = selectMinVertex (value, setMST);

		setMST[u] = true; //include new vertex in MST

		//relax adjacent vertices (noy yet included in MST)
		for (int j = 0; j < nodes_P; j++)
		{

			if (grapH[u][j] != 0 && setMST[j] == false && grapH[u][j] < value[j])
			{
				value[j] = grapH[u][j];
				parent[j] = u;
			}
		}
	}

	//print MST
	for (int i = 1; i < nodes_P; i++)
	{
		cout << "u -> v : " << parent[i] << "->" << i << ", weight = " << grapH[parent[i]][i] << endl;

		if (CHOOSE == 1) fixedGraphConnection(parent[i], i); // for fixed graph
        else if (CHOOSE == 2) graphConnection(parent[i], i); // for random graph
        else graphConnection(parent[i], i); // for user input graph

		if (CHOOSE == 1) fixedNodeColor_1 (parent[i]); // for fixed graph
        else if (CHOOSE == 2) nodeColor_1 (parent[i]); //for random graph
        else nodeColor_1 (parent[i]); // for user input graph

        if (CHOOSE == 1) fixedNodeColor_1 (i); // for fixed graph
        else if (CHOOSE == 2) nodeColor_1 (i); //for random graph
        else nodeColor_1 (i); // for user input graph

		delay(1000);
	}

	for (int i = 1; i < nodes_P; i++)
	{
		sum += grapH[parent[i]][i];
	}

	return sum;

}

void MST_Prims_Algorithm ()
{
	// settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
    // outtextxy(400, 30, "Prims");

	// Graph_FixedNodesAndEdges();

	setfillstyle(SOLID_FILL, BLACK); // to erase the line "Please press any key to continue"
    bar(230, 500, 230 + 500, 500 + 600); // draws a rectangle over the text

	circle(715, 70, 15);
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(715, 70, 15, 15);
    outtextxy(735, 47, "minimum");
    outtextxy(735, 68, "spanning tree");

	if (CHOOSE == 1){
        //for Fixed Graph
        nodes_P = fixed_NODES;
        edges_P = fixed_EDGES;

        for (int i = 0; i < nodes_P; i++){
            for (int j = 0; j < nodes_P; j++){
                grapH[i][j] = fixed_GRAPH[i][j];
            }
        }

    }

    else if (CHOOSE == 2){
		//for Random Input
        nodes_P = NODES;
        edges_P = EDGES;

        int k = 0;
        for (int i = 0; i < nodes_P; i++){
            for (int j = 0; j < nodes_P; j++){
                grapH[i][j] = GRAPH[i][j];
            }
        }

    }

    else {
        //for User Input
        nodes_P = NODES;
        edges_P = EDGES;

        int k = 0;
        for (int i = 0; i < nodes_P; i++){
            for (int j = 0; j < nodes_P; j++){
                grapH[i][j] = GRAPH[i][j];
            }
        }

    }


	cout << "MST cost is : " << findMST(grapH) << endl;

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

//time complexity : O(V^2)
//if we use adjacency list : O(E log V)
/*
9
14
0 1 4
1 2 8
2 3 7
3 4 9
4 5 10
5 6 2
6 7 1
7 8 7
0 7 8
1 7 11
2 8 2
6 8 6
2 5 4
3 5 14
*/
