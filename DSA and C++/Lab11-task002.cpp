#include <iostream>
#include <queue>
using namespace std;

#define V5
int adj
atric {

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