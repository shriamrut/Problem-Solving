#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool doesCycleExistUsingTime(vector<vector<int>> &adj, int n) {
		vector< pair<int,int> > vtime(n + 1, {-1, -1});
		bool cycleExists = false;
		for(int u = 1; u <= n; u++) {
			if(vtime[u].first == -1) {
				cycleExists = doesCycleExistUsingTime(u, adj, vtime);
			}
			if(cycleExists) {
				break;
			}
		}
		return cycleExists;
	}

	bool doesCycleExistUsingTime(int u, vector<vector<int>> &adj, vector<pair<int,int>> &vtime) {
		static int time = 0;
		vtime[u].first = time++;
		//cout << "intime of " << u << " " << vtime[u].first << "\n";
		bool cycleExists = false;
		for(int &v: adj[u]) {
			// not visited at all
			if(vtime[v].first == -1) {
				cycleExists = doesCycleExistUsingTime(v, adj, vtime);
			}
			else if(vtime[v].second == -1) {
				cycleExists = true;
				break;
			}
		}
		vtime[u].second = time++;
		//cout << "outtime of " << u << " " << vtime[u].second << "\n";
		return cycleExists;
	}

	bool doesCycleExistUsingColors(vector<vector<int>> &adj, int n) {
		vector<int> colors(n + 1, 0);
		bool cycleExists = false;
		for(int u = 1; u <= n; u++) {
			if(colors[u] == 0) {
				cycleExists = doesCycleExistUsingColors(adj, colors, u);
			}
			if(cycleExists) {
				break;
			}
		}
		return cycleExists;
	}

	bool doesCycleExistUsingColors(vector<vector<int>> &adj, vector<int> &colors, int u) {
		colors[u] = 1;
		bool cycleExists = false;
		for(int &v: adj[u]) {
			if(colors[v] == 0) {
				cycleExists = doesCycleExistUsingColors(adj, colors, v);
			}
			else if(colors[v] == 1) {
				//cout << "Cycle existing!! " << "edge " << u << " " << v << "\n";
				cycleExists = true;
				break;
			}
		}
		colors[u] = 2;
		return cycleExists;
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
		}
		Solution s;
		assertEquals(s.doesCycleExistUsingColors(adj, n), s.doesCycleExistUsingTime(adj, n));
	}
	return 0;
}