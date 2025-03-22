#include <bits/stdc++.h>
using namespace std;

void print2dVec(vector<vector<int>> &vecs) {
	for(vector<int> &vec: vecs) {
			cout << "[";
			for(int &element: vec) {
				cout << element << " ";
			}
			cout << "]\n";
		}
		cout << "\n";
}

class Solution {
public:

	vector<vector<int>> getSCCUsingTarjansAlgo(vector<vector<int>> &adj, int n) {
		vector<int> disc(n + 1, -1);
		vector<int> low(n + 1, -1);
		vector<bool> isPresentInStack(n + 1, false);
		vector< vector<int> > sccs;
		stack<int> stac;

		for(int src = 1; src <= n; src++) {
			if(disc[src] == -1) {
				getSCCUsingTarjansAlgo(src, 
					disc, 
					low, 
					adj, 
					sccs, 
					isPresentInStack,
					stac);
			}
		}
		return sccs;
	}

	void getSCCUsingTarjansAlgo(int u, 
		vector<int> &disc, 
		vector<int> &low,
		vector<vector<int>> &adj, 
		vector<vector<int>> &sccs,
		vector<bool> &isPresentInStack,
		stack<int> &stac) {

		static int time = 0;
		low[u] = disc[u] = time++;
		stac.push(u);
		isPresentInStack[u] = true;

		for(int &v: adj[u]) {
			if(disc[v] == -1) {
				getSCCUsingTarjansAlgo(v, 
					disc, low, 
					adj, sccs, 
					isPresentInStack, stac);
				low[u] = min(low[u], low[v]);
			}
			else if(isPresentInStack[v]) {
				low[u] = min(low[u], disc[v]);
			}
		}
		
		vector<int> scc;
		if(disc[u] == low[u]) {
			// found the start node
			while(u != stac.top()) {
				scc.push_back(stac.top());
				isPresentInStack[stac.top()] = false;
				stac.pop();
			}
			scc.push_back(stac.top());
			stac.pop();
			sccs.push_back(scc);
		}
		return;
	}

	void getSCCUsingKosarajuAlgDfs2(int u, 
		vector<vector<int>> &radj, 
		vector<bool> &vis, 
		vector<int> &component) {
		vis[u] = true;
		component.push_back(u);
		for(int &v: radj[u]) {
			if(!vis[v]) {
				getSCCUsingKosarajuAlgDfs2(v, radj, vis, component);
			}
		}
		return;
	}

	void getSCCUsingKosarajuAlgDfs1(int u,
	 vector<vector<int>> &adj, 
	 vector<bool> &vis, 
	 vector<int> &topologicalSortedOrder) {
		vis[u] = true;
		for(int &v: adj[u]) {
			if(!vis[v]) {
				getSCCUsingKosarajuAlgDfs1(v, adj, vis, topologicalSortedOrder);
			}
		}
		topologicalSortedOrder.push_back(u);
		return;		
	}
	vector<vector<int>> getSCCUsingKosarajuAlg(vector<vector<int>> &adj, 
		int n) {
		vector<vector<int>> sccs;
		vector<bool> vis(n + 1, false);
		
		// Step - 1 Get topological sorted order
		vector<int> topologicalSortedOrder;

		for(int src = 1; src <= n; src++) {
			if(!vis[src]) {
				getSCCUsingKosarajuAlgDfs1(src, adj, vis, topologicalSortedOrder);
			}
		}	
		reverse(topologicalSortedOrder.begin(), topologicalSortedOrder.end());
		
		// Step - 2 Reverse adjency list
		vector<vector<int>> radj(n + 1);
		for(int u = 1; u <= n; u++) {
			for(int &v : adj[u]) {
				radj[v].push_back(u);
			}
		}

		vis.assign(n + 1, false);
		for(int &src: topologicalSortedOrder) {
			if(!vis[src]) {
				vector<int> component;
				getSCCUsingKosarajuAlgDfs2(src, radj, vis, component);
				sccs.push_back(component);
			}
		}
		return sccs;
	}	

	vector<vector<int>> getStronglyConnectedComponentsBrute(vector<vector<int>> &adj, int n) {
		vector<bool> isScc(n + 1, false);
		vector<vector<int>> sccs;
		for(int src = 1; src <= n; src++) {
			if(!isScc[src]) {
				// not part of any scc
				vector<int> scc;
				scc.push_back(src); 
				for(int dest = 1; dest <= n; dest++) {
					if(dest != src && !isScc[dest]
						&& doesPathExist(src, dest, adj, n) 
						&& doesPathExist(dest, src, adj, n)) {
						scc.push_back(dest);
						isScc[dest] = true;
					}
				}
				sccs.push_back(scc);
			}
		}	
		return sccs;	
	}

	bool doesPathExist(int src, int dest, vector<vector<int>> &adj, int n) {
		vector<bool> vis(n + 1, false);	
		dfs(src, dest, adj, vis);
		return vis[dest];		
	}

	void dfs(int u, int dest, 
		vector<vector<int>> &adj, 
		vector<bool> &vis) {
		vis[u] = true;
		if(u == dest) {
			//found and hence stop traversing
			return;
		}
		for(int &v: adj[u]) {
			if(!vis[v]) {
				dfs(v, dest, adj, vis);
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
		}
		Solution s;
		vector<vector<int>> sccs = s.getStronglyConnectedComponentsBrute(adj, n);
		cout << "Strongly connected components Brute force\n";
		print2dVec(sccs);

		cout << "Strongly connected components Kosraju's Algorithm (2 DFS) \n";
		sccs = s.getSCCUsingKosarajuAlg(adj, n);
		print2dVec(sccs);

		cout << "Strongly connected components Tarjan's Algorithm (1 DFS) \n";
		sccs = s.getSCCUsingTarjansAlgo(adj, n);
		print2dVec(sccs);		
	}
	return 0;
}