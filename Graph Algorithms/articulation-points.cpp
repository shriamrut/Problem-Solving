#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<pair<int,int>> getBridges(vector<vector<int>> &adj, int n) {
		vector<pair<int,int>> bridges;
		vector<int> low(n + 1, -1), disc(n + 1, -1);
		vector<bool> vis(n + 1, false);
		for(int src = 1; src <= n; src++) {
			if(!vis[src]) {
				getBridges(src, -1, adj, low, disc, vis, bridges);
			}
		}
		return bridges;
	}

	void getBridges(int u,
		int parent,
		vector<vector<int>> &adj, 
		vector<int> &low,
		vector<int> &disc, 
		vector<bool> &vis, 
		vector<pair<int, int>> &bridges) {
		vis[u] = true;
		static int time = 0;
		disc[u] = low[u] = time++;
		// int children = 0;
		for(int &v: adj[u]) {
			if(!vis[v]) {
				getBridges(v, 
						   u,  
						   adj, 
						   low, 
						   disc, 
						   vis, 
						   bridges);
				low[u] = min(low[u], low[v]);
				if(low[v] > disc[u]) {
					//u-v is a bridge
					bridges.push_back({u, v});
				}
			}
			else if(parent != v){
				 low[u] = min(low[u], disc[v]);
			}
		}

	}
	vector<int> getArticulationPoints(vector<vector<int>> &adj, 
		int n) {
		vector<int> low(n + 1, -1), disc(n + 1, -1);
		vector<bool> vis(n + 1, false), isAp(n + 1, false);

		for(int src = 1; src <= n; src++) {
			if(vis[src] == false) {
				getArticulationPoints(src, 
					-1, 
					adj, 
					low, 
					disc, 
					vis, 
					isAp);
			}
		}
		vector<int> articulationPoints;
		for(int u = 1; u <= n; u++) {
			if(isAp[u]) {
				articulationPoints.push_back(u);
			}
		}
		return articulationPoints;
	}

	void getArticulationPoints(int u,
		int parent,
		vector<vector<int>> &adj, 
		vector<int> &low, 
		vector<int> &disc,
		vector<bool> &vis, 
		vector<bool> &isAp) {

		vis[u] = true;
		int children = 0;
		static int time = 0;
		low[u] = disc[u] = time++;
		for(int &v: adj[u]) {
			if(vis[v] == false) {
				getArticulationPoints(v, 
					u, 
					adj, 
					low, 
					disc,
					vis, 
					isAp);
				low[u] = min(low[u], low[v]);
				if(parent != -1 && low[v] >= disc[u]) {
					isAp[u] = true;
				}
			}
			else if(parent != v) {
				low[u] = min(low[u], disc[v]);
			}
		}
		if(parent == -1 && children > 1) {
			isAp[u] = true;
		}
	}
};
int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> adj(n + 1);
		for(int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution s;
		vector<int> articulationPoints = s.getArticulationPoints(adj, n);
		cout << "Articulation points\n";
		cout << "[";
		for(int &vertex: articulationPoints) {
			cout << vertex << " ";
		}
		cout << "]\n";

		cout << "Bridges\n";
		vector<pair<int, int>> bridges = s.getBridges(adj, n);
		for(pair<int, int> &edge: bridges) {
			cout << edge.first << " - " << edge.second << "\n";
		}
	}
	return 0;
}
