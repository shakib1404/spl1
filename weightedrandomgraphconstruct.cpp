#include "head.h"


void WeightedRandom_GraphConstruction() {
    int nodes, edges;

    cout << "Enter the number of nodes: ";
    cin >> nodes;
    NODES = nodes;

    cout << "Enter the number of edges: ";
    cin >> edges;
    EDGES = edges;

    int adj_matrix[nodes][nodes]; // Adjacency matrix to store the graph

    for (int i = 0; i < nodes; i++) {
      for (int j = 0; j < nodes; j++) {
        adj_matrix[i][j] = 0;
        GRAPH[i][j] = 0;
      }
    }

    srand(time(0));

    /* time(0) is a function from the ctime header file
    that returns the current calendar time as the number of seconds
    elapsed since the epoch (00:00:00 UTC, January 1, 1970).
    This ensures that a different set of random numbers is generated every time the code is run.*/

    /* When used as an argument for srand,
    time(0) serves as a seed for the random number generator rand()
    to ensure that a different set of random numbers is generated
    every time the code is run.*/

    int u, v;
    int count = 0;

    while (count < edges) {
      u = rand() % nodes;
      v = rand() % nodes;

      if (u != v && adj_matrix[u][v] == 0) {
        adj_matrix[u][v] = rand() % 10 + 1; // generates random value from 1 to 20

        adj_matrix[v][u] = adj_matrix[u][v]; // Comment this line for directed graph
        GRAPH[u][v] = GRAPH[v][u] = adj_matrix[u][v];

        count++; //keeping track of the number of edges added to the graph.
      }

    }

    SOURCE = 0;

    // Draw nodes as circles with numbers
    int radius = 20;

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
    for (int i = 0; i < nodes; i++) {
      x[i] = (i+1) * (800 / (nodes+1));
      y[i] = rand() % 400 + 100;
      circle(x[i], y[i], radius);
      string label = to_string(i);
      outtextxy(x[i]-radius/2, y[i]-radius/2, const_cast<char*>(label.c_str()));
    }

    // Wait for a delay before proceeding to the next step
    delay(1500);

    // Draw edges as lines
    for (int i = 0; i < nodes; i++) {
      for (int j = i+1; j < nodes; j++) {
        if (adj_matrix[i][j] != 0) {
          line(x[i], y[i], x[j], y[j]);
          delay(1500);

          showWeight_2(adj_matrix[i][j], i, j);
        }
      }
    }

}



/* RANDOM RAW code

the function rand_num implements a linear congruential generator (LCG)
and returns a random number. The seed value seed is updated every time rand_num is called,
so the function generates a different random number each time it is called.
The a, c, and m values are the multiplier, increment, and modulus, respectively,
that are used in the LCG formula. The rest of the code is similar to the previous example,
with the exception of using rand_num instead of rand() to generate random numbers.



unsigned int seed = 0; // initialize seed value
unsigned int a = 1103515245; // multiplier
unsigned int c = 12345; // increment
unsigned int m = 0xffffffff; // modulus

unsigned int rand_num(unsigned int &seed) {
  seed = (a * seed + c) % m;
  return seed;
}

int u, v;
int count = 0;
while (count < edges) {
  u = rand_num(seed) % nodes;
  v = rand_num(seed) % nodes;
  if (u != v && adj_matrix[u][v] != 1) {
    adj_matrix[u][v] = 1;
    adj_matrix[v][u] = 1; // Comment this line for directed graph
    count++;
  }
}

*/
