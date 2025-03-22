#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	vector<vector<pair<int, int>>> getBiconnectedComponents(vector<vector<int>> &adj, int n) {
		vector<int> disc(n + 1, -1);
		vector<int> low(n + 1, -1);

		vector<vector<pair<int,int>>> components;
		stack<pair<int, int>> stac;

		for(int src = 1; src <= n; src++) {
			if(disc[src] == -1) {
				getBiconnectedComponents(src,
				 -1,
				 adj,
				 disc, 
				 low, 
				 components, 
				 stac);
				vector<pair<int,int>> component;
				while(!stac.empty()) {
					component.push_back(stac.top());
					stac.pop();
				}
				if(!component.empty()) {
					components.push_back(component);
				}
			}
		}
		return components;
	}

	void getBiconnectedComponents(int u,
	 int parent,
	 vector<vector<int>> &adj, 
	 vector<int> &disc,
	 vector<int> &low, 
	 vector<vector<pair<int, int>>> &components,
	 stack<pair<int, int>> &stac) {
	 	static int time = 0;
		low[u] = disc[u] = time++;
		int children = 0;
		for(int &v: adj[u]) {
			if(disc[v] == -1) {
				children++;
				stac.push({u, v});
				getBiconnectedComponents(v, u,
					adj, 
					disc, low, components, 
					stac);
				low[u] = min(low[u], low[v]);
				if((disc[u] == -1 && children > 1) || 
					(low[v] >= disc[u] && disc[u] >= 0)) {
					vector<pair<int, int>> component;
					while(stac.top().first != u || stac.top().second != v) {
						component.push_back(stac.top());
						stac.pop();
					}
					component.push_back(stac.top());
					stac.pop(); 
					components.push_back(component);
				}
			}
			else if(parent != v) {
				low[u] = min(low[u], disc[v]);
				if(disc[v] < disc[u]) {
					stac.push({u, v});
				}
			}
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
		cout << "Biconnected component\n";
		vector<vector<pair<int, int>>> biconnectedComponents = s.getBiconnectedComponents(adj, n);
		for(vector<pair<int,int>> &biconnectedComponent: biconnectedComponents) {
			cout << "[";
			for(pair<int, int> &edge: biconnectedComponent) {
				cout << edge.first << "-" << edge.second << " ";
			}
			cout << "]\n";
		}
		cout << "\n";
	}
	return 0;
}