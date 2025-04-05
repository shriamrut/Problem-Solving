//Problem: https://neetcode.io/problems/foreign-dictionary

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26);

        //Prepare adjacency list
        unordered_set<int> srcSet;
        for(int i = 0; i < words.size(); i++) {
        	for(int j = 0; j < words[i].length(); j++) {
        		srcSet.insert(words[i][j] - 'a');
        	}
        }
        for(int i = 0; i + 1 < words.size(); i++) {
        	string a = words[i];
        	string b = words[i+1];
        	int minLen = min(a.length(), b.length());
            bool found = false;
        	for(int j = 0; j < minLen; j++) {
        		if(a[j] != b[j]) {
        			adj[a[j] - 'a'].push_back(b[j] - 'a');
                    found = true;
        			break;
        		}
        	}
            if(!found && a.length() > b.length()) {
                return "";
            }
        }

        vector<int> color(26, 0);
        bool isCycle = false;
        string order = "";
        for(int src: srcSet) {
        	if(color[src] == 0) {
        		dfs(src, adj, color, isCycle, order);
        		if(isCycle) {
        			break;
        		}
        	}
        }
        reverse(order.begin(), order.end());
        return (isCycle)? "": order;
    }

    void dfs(int u, vector<vector<int>> &adj, vector<int> &color, bool &isCycle, string &order) {
    	color[u] = 1;
    	for(int &v: adj[u]) {
    		if(color[v] == 0) {
    			dfs(v, adj, color, isCycle, order);
    		}
    		else if(color[v] == 1) {
    			//cycle detected
    			isCycle = true;
    			return;
    		}
    	}
    	color[u] = 2;
    	order += (u + 'a');
    	return;
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
		int n;
		cin >> n;
		vector<string> words(n);
		for(int i = 0; i < n; i++) {
			cin >> words[i];
		}
		Solution sol;
		string order = sol.foreignDictionary(words);
		cout << order << "\n";
	}
	return 0;
}