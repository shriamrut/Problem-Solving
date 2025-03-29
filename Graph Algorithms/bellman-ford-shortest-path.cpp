#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int src, int vertexCount, vector<vector<int>> &edges) {
	vector<int> distance(vertexCount, INT_MAX);
	distance[src] = 0;
	for(int count = 0; count <= vertexCount; count++) {
		for(vector<int> &edge: edges) {
			int u = edge[0], v = edge[1], wt = edge[2];
			
			if(distance[u] != INT_MAX && distance[u] + wt < distance[v]) {
				if(count == vertexCount) {
					return {-1};
				}
				distance[v] = distance[u] + wt;
			}
		}
	}
	return distance;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--) {
		int vertexCount, edgeCount;
		cin >> vertexCount >> edgeCount;
		vector<vector<int>> edges(edgeCount, vector<int> (3));
		for(int i = 0; i < edgeCount; i++) {
			cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
		}
		int src; 
		cin >> src;
		vector<int> distance = bellmanFord(src, vertexCount, edges);
		cout << "From source: " << src << "\n";
		for(int v = 0; v < min((int) distance.size(), vertexCount); v++) {
			cout << v << " - " << distance[v] << endl;
		}

	}
	return 0;
}