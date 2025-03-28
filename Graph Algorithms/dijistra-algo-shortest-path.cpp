#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
	vector<int> computeShortestPathsUsingDijistra(int src, vector<vector<pair<int, int>>> &adj, int n) {
		vector<int> distance(n, INT_MAX);
		distance[src] = 0;
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;			
		pq.push({0, src});
		while(!pq.empty()) {
			pair<int, int> u = pq.top();
			pq.pop();
			for(pair<int, int> &v: adj[u.second]) {
				if(distance[u.second] + v.second < distance[v.first]) {
					distance[v.first] = distance[u.second] + v.second;
					pq.push({distance[v.first], v.first});
				}
			}
		}
		return distance;
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
		vector<vector<pair<int, int>>> adj(n);
		for(int i = 0; i < m; i++) {
			int u, v, wt;
			cin >> u >> v >> wt;
			adj[u].push_back({v, wt});
			adj[v].push_back({u, wt});
		}
		Solution s;
		int src;
		cin >> src;
		vector<int> shortestDistances = s.computeShortestPathsUsingDijistra(src, 
			adj, n);

		cout << "For source: " << src << "\n";
		for(int dest = 0; dest < n; dest++) {
			cout << dest << " " << shortestDistances[dest] << "\n";
		}
		cout << "\n";
	}
	return 0;
}