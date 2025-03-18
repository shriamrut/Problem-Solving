#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> getTopologicalSortingOrderDfs(vector<vector<int>> &adj,
	 int n) {
		vector<bool> vis(n + 1, false);
		vector<int> order;
		for(int src = 1; src <= n; src++) {
			if(!vis[src]) {
				getTopologicalSortingOrderDfs(src, adj, vis, order);
			}
		}
		reverse(order.begin(), order.end());
		return order;
	}

	void getTopologicalSortingOrderDfs(int u, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &order) {
		vis[u] = true;
		for(int &v: adj[u]) {
			if(!vis[v]) {
				getTopologicalSortingOrderDfs(v, adj, vis, order);
			}
		}
		order.push_back(u);
		return;
	}

	vector<int> computeIndegree(vector<vector<int>> &adj, int n) {
		vector<int> indegree(n + 1, 0);
		for(int u = 1; u <= n; u++) {
			for(int &v: adj[u]) {
				indegree[v]++;
			}
		}
		return indegree;
	}
	vector<int> getTopologicalSortingOrderKahnsAlgorithm(vector<vector<int>> &adj, int n) {
		vector<int> order;
		vector<int> indegree = computeIndegree(adj, n);
		queue<int> q;
		for(int u = 1; u <= n; u++) {
			// indegree is 0, but it has outgoing edges - valid entry in the graph
			if(indegree[u] == 0) {
				q.push(u);
			}
		}

		while(!q.empty()) {
			int u = q.front();
			q.pop();
			order.push_back(u);
			for(int &v: adj[u]) {
				if(--indegree[v] == 0) {
					q.push(v);
				}
			}
		}

		return order;
	}

	vector<vector<int>> getAllTopologicalSortingOrders(vector<vector<int>> &adj, int n) {
		vector<vector<int>> result;
		vector<int> indegree = computeIndegree(adj, n);

		vector<int> order;
		vector<bool> vis(n + 1, false);
		getAllTopologicalSortingOrders(adj, n, indegree, result, order, vis);
		return result;
	}

	void getAllTopologicalSortingOrders(vector<vector<int>> &adj, int n, vector<int> &indegree,
		vector<vector<int>> &result,
		vector<int> &order,
		vector<bool> &vis) {
		if(order.size() == n) {
			result.push_back(order);
			return;
		}
		for(int u = 1; u <= n; u++) {
			if(indegree[u] == 0 && vis[u] == false) {
				for(int &v: adj[u]) {
					indegree[v]--;
				}
				order.push_back(u);
				vis[u] = true;
				getAllTopologicalSortingOrders(adj, n, indegree, result, order, vis);
				order.pop_back();
				vis[u] = false;
				for(int &v: adj[u]) {
					indegree[v]++;
				}
			}
		}
		return;
	}

	bool isUniqueTopologicalSortingOrder(vector<vector<int>> &adj, int n) {
		vector<int> indegree = computeIndegree(adj, n);
		queue<int> q;
		for(int u = 1; u <= n; u++) {
			if(indegree[u] == 0) {
				q.push(u);
			}
		}
		int count = 0;
		while(!q.empty()) {
			if(q.size() > 1) {
				return false;
			}
			int u = q.front();
			q.pop();
			count++;
			for(int &v: adj[u]) {
				if(--indegree[v] == 0) {
					q.push(v);
				}
			}
		}
		return (count == n);
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
		// Using DFS
		vector<int> order1 = s.getTopologicalSortingOrderDfs(adj, n);
		cout << "Order 1: [";
		for(int &vertex: order1) {
			cout << vertex << " ";
		}		
		cout << "]\n";

		//Using BFS / Kahn's algorithm
		vector<int> order2 = s.getTopologicalSortingOrderKahnsAlgorithm  (adj, n);
		cout << "Order 2: [";
		for(int &vertex: order2) {
			cout << vertex << " ";
		}		
		cout << "]\n";
		cout << "All orders \n";
		vector<vector<int>> allOrders = s.getAllTopologicalSortingOrders(adj, n);
		for(vector<int> &order: allOrders) {
			cout << "[";
			for(int &vertex: order) {
				cout << vertex << " ";
			}
			cout << "]\n";
		}	
		cout << "Is unique? " << s.isUniqueTopologicalSortingOrder(adj, n) << "\n";	
	}
	return 0;
}