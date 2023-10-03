#include<iostream>

using namespace std;

#define SIZE 100
#define INFINITY 1000000

int w[SIZE][SIZE], p[SIZE][SIZE];
int n = 0;
string name[SIZE];

void prepareMatrix(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(w[i][j] == 0 && i!=j)
                w[i][j] = INFINITY;

            if(i==j || w[i][j] == INFINITY)
                p[i][j] = -1;
            else p[i][j] = i;
        }
    }
}

void readInput(){
    int u, v;
    string s;
    while (cin>>s){
        if(s == "END")
            break;

        for(u = 0; u < n; u++){
            if(name[u] == s)
                break;
        }
        if (u == n){
            name[n] = s;
            n++;
        }

        cin >> s;
        for(v = 0; v < n; v++){
            if(name[v] == s)
                break;
        }
        if (v == n){
            name[n] = s;
            n++;
        }

        cin >> w[u][v];

    }

    prepareMatrix();
}


void printMatrices(){
    cout<<"Weight-Matrix is: "<<endl;
    int u, v;
    for (u = 0; u < n; u++ ){
        for(v = 0; v < n; v++){
            if(w[u][v] == INFINITY)
                cout<<"INF"<<"\t";
            else
                cout << w[u][v] << "\t";
        }
        cout << "\n";
    }

    cout<<"k's Index-Matrix is: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<p[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void floydWarshall(){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(w[i][j] > w[i][k] + w[k][j]){
                    w[i][j] = w[i][k] + w[k][j];
                    p[i][j] = p[k][j];
                }
            }
        }
    }
}

void traverse(int i, int j){
    if(p[i][j] == -1){
        cout<<name[j]<<" -> ";
        return;
    }
    traverse(i, p[i][j]);
    cout<<name[j]<<" -> ";
}

void printPath(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<"Shortest path from "<< name[i]<<" to "<<name[j]<<" : ";
            if( i == j)
                cout<<"It is itself so no path needed!";
            else
                traverse(i, j);
            cout<<endl;
        }
    }
}

int main(){
    freopen("floydinput.txt", "r", stdin);
    readInput();
    printMatrices();

    floydWarshall();
    cout<<"After Floyd Warshall algorithm: "<<endl;
    printMatrices();

    printPath();
}
