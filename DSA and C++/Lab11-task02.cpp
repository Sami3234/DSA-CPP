#include <iostream>
#include <queue>
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
void printGraph() {
    cout << "\nAdjacency Matrix:\n";
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}
void BFS(int start) {
    bool visited[V] = {false};
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int i=0; i<V; i++) {
            if(adjMatrix[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
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

    bool visited[V] = {false};
    cout << "\nBFS Traversal starting from node 0: ";
    BFS(0);

    return 0;
}
