
#include "head.h"
const int MAX_NODES = 6;

struct Node
{
    int x, y;
};

struct MyQueue
{
    int front, rear, size;
    int items[MAX_NODES];

    MyQueue(int maxSize)
    {
        front = rear = -1;
        size = maxSize;
    }

    void enqueue(int value)
    {
        if (rear == size - 1)
        {
            return; // Queue is full
        }
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        items[rear] = value;
    }

    int dequeue()
    {
        if (front == -1)
        {
            return -1; // Queue is empty
        }
        int item = items[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
        return item;
    }

    bool isEmpty()
    {
        return front == -1;
    }
};

void visualizeGraph(const Node nodes[], const int adjacencyList[][MAX_NODES], int currentNode)
{
    cleardevice();

    // Draw edges
    for (int i = 0; i < MAX_NODES; ++i)
    {
        for (int j = 0; j < MAX_NODES; ++j)
        {
            if (adjacencyList[i][j] == 1)
            {
                line(nodes[i].x, nodes[i].y, nodes[j].x, nodes[j].y);
            }
        }
    }

    // Draw nodes
    for (int i = 0; i < MAX_NODES; ++i)
    {
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

void BFS1(const int adjacencyList[][MAX_NODES], const Node nodes[], int startNode)
{
    MyQueue q(MAX_NODES); // Create a custom queue

    bool visited[MAX_NODES] = {false};

    q.enqueue(startNode); // Enqueue the starting node
    visited[startNode] = true;

    while (!q.isEmpty())
    {
        int currentNode = q.dequeue(); // Dequeue the front node

        visualizeGraph(nodes, adjacencyList, currentNode);
        delay(1000);

        for (int neighbor = 0; neighbor < MAX_NODES; ++neighbor)
        {
            if (adjacencyList[currentNode][neighbor] == 1 && !visited[neighbor])
            {
                q.enqueue(neighbor); // Enqueue the unvisited neighbor
                visited[neighbor] = true;
            }
        }
    }
}

void BFS()
{
    // int gd = DETECT, gm;
    //  initgraph(&gd, &gm, "");

    Node nodes[MAX_NODES] = {{200, 200}, {300, 200}, {400, 200}, {200, 300}, {300, 300}, {400, 300}};
    /*  int adjacencyList[MAX_NODES][MAX_NODES] = {{0, 1, 0, 1, 0, 0},
                                                  {1, 0, 0, 0, 1, 0},
                                                  {0, 0, 0, 0, 1, 1},
                                                  {1, 0, 0, 0, 0, 0},
                                                  {0, 1, 1, 0, 0, 0},
                                                  {0, 0, 1, 0, 0, 0}};*/
    int adjacencyList[MAX_NODES][MAX_NODES];
    for (int i = 0; i < MAX_NODES; i++)
    {
        for (int j = 0; j < MAX_NODES; j++)
        {
            adjacencyList[i][j] = GRAPH[i][j];
        }
    }


    int startNode = 0;
    BFS1(adjacencyList, nodes, startNode);

    // delay(100000);
    // closegraph();

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
    outtextxy(300, 550, "Successfully ended...");
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
        }
    }
    //closegraph();
    // getch();


}
