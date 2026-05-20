#include <iostream>
using namespace std;

#define V 5

int adjMatrix[V][V];

void initGraph() {
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

// Print adjacency matrix
void printGraph() {
    cout << "\nAdjacency Matrix:\n";
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void DFS(int start, bool visited[]) {
    cout << start << " ";
    visited[start] = true;

    for(int i=0; i<V; i++) {
        if(adjMatrix[start][i] == 1 && !visited[i]) {
            DFS(i, visited);  
        }
    }
}

int main() {
    initGraph();
    addEdge(0,1);
    addEdge(0,2);
    addEdge(1,3);
    addEdge(2,4);

    printGraph();

    cout << "\nDFS Traversal starting from node 0: ";
    bool visited[V] = {false};
    DFS(0, visited);

    return 0;
}
