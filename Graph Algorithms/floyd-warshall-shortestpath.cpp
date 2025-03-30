#include <bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>> &graph) {
	int V = graph.size();
	for(int k = 0; k < V; k++) {
		for(int u = 0; u < V; u++) {
			for(int v = 0; v < V; v++) {
				if(graph[u][k] != -1 && graph[k][v] != -1 && ((graph[u][v] == -1) ||
				graph[u][v] > graph[u][k] + graph[k][v])) {
					graph[u][v] = graph[u][k] + graph[k][v];
				}

			}
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	vector<vector<int>> graph = {
        {0, 4, -1, 5, -1},
        {-1, 0, 1, -1, 6},
        {2, -1, 0, 3, -1},
        {-1, -1, 1, 0, 2},
        {1, -1, -1, 4, 0}
    };

    floydWarshall(graph);
    for(int i = 0; i<graph.size(); i++) {
        for(int j = 0; j<graph.size(); j++) {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}