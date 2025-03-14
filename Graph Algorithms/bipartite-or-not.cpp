#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isBipartiteDfs(vector<vector<int>> &adj, int n) {
		bool isBipartiteOrNot = true;
		vector<int> colors(n + 1, -1);
		for(int u = 1; u <= n; u++) {
			if(colors[u] == -1) {
				isBipartiteOrNot = isBipartiteDfs(u, adj, colors, 1);
			}
			if(!isBipartiteOrNot) {
				break;
			}
		}
		return isBipartiteOrNot;
	}

	bool isBipartiteDfs(int u, vector<vector<int>> &adj, vector<int> &colors, int color) {
		colors[u] = color;
		for(int &v: adj[u]) {
			if(colors[v] == -1) {
				int nextColor = (color == 1)? 2: 1;
				return isBipartiteDfs(v, adj, colors, nextColor);
			}
			else if(color == colors[v]) {
				return false;
			}
		}
		return true;
	}

	bool isBipartite(vector<vector<int>> &adj, int n) {
		bool isBipartiteOrNot = true;
		vector<int> colors(n + 1, -1);
		// we can allocate colors - 1, 2
		for(int u = 1; u <= n; u++) {
			if(colors[u] == -1) {
				isBipartiteOrNot = isBipartite(u, adj, colors);
			}
			if(!isBipartiteOrNot) {
				break;
			}
		}
		return isBipartiteOrNot;
	}	

	bool isBipartite(int src, vector<vector<int>> &adj, vector<int> &colors) {
		queue<int> q;
		colors[src] = 1;
		q.push(src);
		bool isBipartiteOrNot = true;
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(int &v: adj[u]) {
				if(colors[v] == -1) {
					colors[v] = (colors[u] == 1)? 2: 1;
					q.push(v);
				}
				else if(colors[v] == colors[u]) {
					isBipartiteOrNot = false;
					break;
				} 
			}
		}
		return isBipartiteOrNot;
	}
};

bool assertEquals(bool a, bool b) {
	if(a == b) {
		cout << "(" << a << " == " << b << ")" << " - PASS \n";
		return true;
	}
	else {
		cout << "(" << a << " != " << b << ")" << " - FAIL \n";
		return false;
	}
}

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
		assertEquals(s.isBipartite(adj, n), s.isBipartiteDfs(adj, n));
	}
	return 0;
}