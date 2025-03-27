#include <bits/stdc++.h>
using namespace std;

class UnionFind{
public:
	vector<int> rank, parent;
	UnionFind(int n) {
		parent.resize(n);
		rank.resize(n);
		for(int i = 0; i < n; i++) {
			parent[i] = i;
			rank[i] = 0;
		}
	}

	int find(int u) {
		if(parent[u] == u) {
			return u;
		}
		parent[u] = find(parent[u]);
		return parent[u];
	}

	void joinByRank(int u, int v) {
		int pu = parent[u];
		int pv = parent[v];
		if(pu != pv) {
			if(rank[pu] < rank[pv]) {
				parent[pu] = pv;
			}
			else if(rank[pu] > rank[pv]) {
				parent[pv] = pu;
			}
			else {
				parent[pu] = pv;
				rank[pv]++;
			}
		}
	}
};

class Solution {
  public:
  	static bool cmp(const vector<int> &a, const vector<int> &b) {
  		return a[2] < b[2];
  	}

    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int kriskalMSP(int V, vector<vector<int>> adj[]) {
       vector<vector<int>> edges;
       for(int u = 0; u < V; u++) {
       	for(vector<int> &edgeData: adj[u]) {
       		edges.push_back({u, edgeData[0], edgeData[1]});
       	}
       }
       sort(edges.begin(), edges.end(), cmp);
       int mspEdgeSum = 0, count = 0;

       UnionFind unionFind(V);

       for(vector<int> &edge: edges) {

       	//if both of them have different parent, then they are different
       	if(unionFind.find(edge[0]) != unionFind.find(edge[1])) {
       		unionFind.joinByRank(edge[0], edge[1]);
       		mspEdgeSum += edge[2];
       		count++;
       	}
       	if(count == V - 1) {
       		break;
       	}
       }

       return mspEdgeSum;
    }

    int primsMsp(int V, vector<vector<int>> adj[]) {
    	int mspEdgeSum = 0;
    	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    	pq.push({0, 0});

    	vector<bool> vis(V + 1, false);
    	int counter = 0;
    	while(!pq.empty()) {
    		pair<int, int> u = pq.top();
    		pq.pop();
    		if(vis[u.second]) {
    			continue;
    		}
    		vis[u.second] = true;
    		mspEdgeSum += u.first;
    		for(vector<int> &v: adj[u.second]) {
    			if(!vis[v[0]]) {
    				pq.push({v[1], v[0]});
    			}
    		}
    	}
    	return mspEdgeSum;
    }
};

bool assertEquals(int a, int b) {
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
		vector<vector<int>> adj[n];
		for(int i = 0; i < m; i++) {
			int u, v, wt;
			cin >> u >> v >> wt;
			adj[u].push_back({v, wt});
			adj[v].push_back({u, wt});
		}

		Solution s;
		assertEquals(s.kriskalMSP(n, adj) ,s.primsMsp(n, adj));
	}
	return 0;
}