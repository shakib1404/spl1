#include "head.h"





void prevWindowArrow ()
{
    setcolor(GREEN);
    int x2 = 50;
    int y2 = 70;
    setlinestyle(0, 0, 2);
    line(x2, y2, x2 + 60, y2);
    line(x2, y2, x2 + 30, y2 - 20);
    line(x2, y2, x2 + 30, y2 + 20);
   // setcolor(WHITE);
}

void graphOptions ()
{
    prevWindowArrow();

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);

    outtextxy(100, 150, "1. Implement algorithm in a Fixed graph");
    outtextxy(100, 300, "2. Implement algorithm in a Random graph");
    outtextxy(100, 450, "3. Implement algorithm in a User Input graph");

    while (1) {

        int x = mousex();
        int y = mousey();

        if (ismouseclick(WM_LBUTTONDOWN)) {
            clearmouseclick(WM_LBUTTONDOWN);

            if (x > 50 && x < 110 && y > 50 && y < 90) {
                cleardevice();
                delay(100);
                showList();
            }

            else if (x > 100 && x < 620 && y > 150 && y < 170) {

                cleardevice();
                delay(100);

                CHOOSE = 1;

                return ;
            }

            else if (x > 100 && x < 620 && y > 300 && y < 320) {

                cleardevice();
                delay(100);

                CHOOSE = 2;

                return ;
            }

            else if (x > 100 && x < 620 && y > 450 && y < 470) {

                cleardevice();
                delay(100);

                CHOOSE = 3;

                return ;
            }
        }
    }
}

void drawButton(int x, int y, int width, int height)
{
    setlinestyle(0, 0, 2);
    line(x, y, width, height);
    line(x, y+20, width, height+20);
    line(x, y+40, width, height+40);
}

void showList()
{
    int y = 50;
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);

    setcolor(YELLOW);
    outtextxy(400, y, "MENU");
    y += 130;

    prevWindowArrow ();

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
    setcolor(WHITE);

    outtextxy(100, y, "BFS");
    y += 40;
    outtextxy(100, y, "DFS");
    y += 40;
    outtextxy(100, y, "Shortest path (Dijkstra's)");
    y += 40;
    outtextxy(100, y, "Shortest path (Bellman Ford)");
    y += 40;
    outtextxy(100, y, "Minimum spanning tree (Prim's)");
    y += 40;
    outtextxy(100, y, "Minimum spanning tree (Kruskal's)");
    y += 40;
    outtextxy(100, y, "TOPOLOGICAL SORT");
    y += 40;
    outtextxy(100, y, "Strongly Connected Components (Tarjan's)");
    y += 40;
    outtextxy(100, y, "Isomorphism (VF2)");



     while (1) {

        int x = mousex();
        int y = mousey();

        if (ismouseclick(WM_LBUTTONDOWN)) {
            clearmouseclick(WM_LBUTTONDOWN); // clear the mouse click event

            ////this part is for to go back to the previous window
            if (x > 50 && x < 110 && y > 50 && y < 90) {
                // button was clicked
                cleardevice();
                delay(100);
                //getch();
                Graphics_MENU();
                //break;
            }


             else if (x > 100 && x < 170 && y > 180 && y < 200) {
                // button was clicked
                cleardevice();
                delay(100);

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "BFS");

               // graphOptions();

               // settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
               // outtextxy(400, 30, "BFS");

               // if (CHOOSE == 1){
                   // Graph_FixedNodesAndEdges();
               // }
              //  else if (CHOOSE == 2){
                  //  Random_GraphConstruction();
               // }
               // else{
                //    UserInput_GraphConstruction();
                //}

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                outtextxy(240, 550, "Please press any key to continue");

                getch(); // waits for user to press any key

                BFS();
                break;
            }

             else if (x > 100 && x < 170 && y > 220 && y < 240) {
                // button was clicked
                cleardevice();
                delay(100);

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "DFS");

               // graphOptions();

              //  settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
              //  outtextxy(400, 30, "DFS");

             //   if (CHOOSE == 1){
               //     Graph_FixedNodesAndEdges();
             //   }
             //   else if (CHOOSE == 2){
                 //   Random_GraphConstruction();
                //}
              //  else{
                  //  UserInput_GraphConstruction();
                //}

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                outtextxy(240, 550, "Please press any key to continue");

                getch(); // waits for user to press any key

                DFS();
                break;
            }
                        else if (x > 100 && x < 420 && y > 260 && y < 280) {

                COUNT = 0;

                // button was clicked
                cleardevice();
                delay(100);

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "Dijkstras");

                graphOptions();

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "Dijkstras");

                if (CHOOSE == 1){
                    Graph_FixedNodesAndEdges();
                    showWeight();
                }
                else if (CHOOSE == 2){
                  WeightedRandom_GraphConstruction();
                    //showWeight();
                }
                else{
                    Weighted_GraphConstruction();
                    //showWeight();
                }

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                outtextxy(240, 550, "Please press any key to continue");

                getch(); // waits for user to press any key

                Dijkstras_algorithm();
                break;
            }

              else if (x > 100 && x < 500 && y > 300 && y < 320) {

                COUNT = 1; // COUNT changed beacuse it will indicate that it will
                           // be a negative weighted fixed graph

                // button was clicked
                cleardevice();
                delay(100);

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "Bellman Ford");

                graphOptions();

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "Bellman Ford");

                if (CHOOSE == 1){
                    Directed_FixedGraph();
                    showWeightDirectedGraph();
                }
                else if (CHOOSE == 2){
                    Random_GraphConstruction();
                    //showWeight();
                }
                else{
                    UserInput_GraphConstruction();
                    //showWeight();
                }

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                outtextxy(240, 550, "Please press any key to continue");

                getch(); // waits for user to press any key

                BellmanFord_algorithm();
                break;
            }

             else if (x > 100 && x < 550 && y > 340 && y < 360) {
                // button was clicked
                cleardevice();
                delay(100);

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "Prims");

                graphOptions();

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "Prims");

                if (CHOOSE == 1){
                    Graph_FixedNodesAndEdges();
                    showWeight();
                }
                else if (CHOOSE == 2){
                   // WeightedRandom_GraphConstruction();
                    //showWeight();
                }
                else{
                    Weighted_GraphConstruction();
                    //showWeight();
                }

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                outtextxy(240, 550, "Please press any key to continue");

                getch(); // waits for user to press any key

                MST_Prims_Algorithm();
                break;
            }

             else if (x > 100 && x < 550 && y > 380 && y < 400) {
                // button was clicked
                cleardevice();
                delay(100);

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "Kruskals");

                graphOptions();

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "Kruskals");

                if (CHOOSE == 1){
                    Graph_FixedNodesAndEdges();
                    showWeight();
                }
                else if (CHOOSE == 2){
                    WeightedRandom_GraphConstruction();
                    //showWeight();
                }
                else{
                    Weighted_GraphConstruction();
                    //showWeight();
                }

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                outtextxy(240, 550, "Please press any key to continue");

                getch(); // waits for user to press any key

                MST_Kruskals_Algorithm();
                break;
            }



             else if (x > 100 && x < 680 && y > 420 && y < 440) {
                // button was clicked
                cleardevice();
                delay(100);

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "topological sort");

                //graphOptions();

                //settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
               // outtextxy(400, 30, "topological sort");

               // if (CHOOSE == 1){
                 //   Graph_FixedNodesAndEdges();
                    //showWeight();
               // }
               // else if (CHOOSE == 2){
                  //  Random_GraphConstruction();
                    //showWeight();
                //}
               // else{
               //     UserInput_GraphConstruction();
                    //showWeight();
              //  }

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                outtextxy(240, 550, "Please press any key to continue");

                getch(); // waits for user to press any key

                topologicalsort();
                break;
            }



        }
}
}
void openGraphicalWindow()
{
    int gd = DETECT, gm;
    initwindow(920, 680, "Graph Algorithm Implementation & Visualization");
}

void Graphics_MENU()
{
    setcolor(LIGHTGRAY);
    drawButton(50, 50, 100, 50);

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);

    outtextxy(200, 190, "***************************");
    for (int i = 205; i < 440; i += 15){
        outtextxy(200, i, "*");
    }

    setcolor(GREEN);
    outtextxy(350, 260, "look");
    outtextxy(425, 310, "how");
    outtextxy(260, 350, "Graph Algorithms ");
     outtextxy(300, 390, "works");


    setcolor(LIGHTGRAY);
    for (int i = 205; i < 440; i += 15){
        outtextxy(668, i, "*");
    }
    outtextxy(200, 445, "***************************");

    setcolor(WHITE);
    while (1) {
        int x = mousex();
        int y = mousey();
        if (ismouseclick(WM_LBUTTONDOWN)) {
            clearmouseclick(WM_LBUTTONDOWN);
            if (x > 50 && x < 100 && y > 50 && y < 90) {
                cleardevice();
                delay(100);
                showList();
            }
        }
    }


    getch();
    closegraph();
}
