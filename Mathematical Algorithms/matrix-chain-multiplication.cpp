#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        int mcount = n - 1;
        vector<vector<int>> cost(mcount + 1, vector<int> (mcount + 1, INT_MAX));
        //Single matrix
        for(int i = 1; i <= mcount; i++) {
        	cost[i][i] = 0;
        }

        // Multplying every pair matrix
        for(int i = 1; i <= mcount - 1; i++) {
        	cost[i][i + 1] = arr[i - 1] * arr[i] * arr[i + 1];
        }

        // cout << "Mcount: " << mcount << "\n"; 
        // Multiplying every length `l` matrix 
    	for(int len = 3; len <= mcount; len++) {
    		 for(int i = 1; i + len - 1 <= mcount; i++) {
    		 	int j = i + len - 1;
    		 	// cout << "For computing cost: cost[" << i << "," << j << "] \n"; 
    		 	for(int k = i; k < j; k++) {
    		 		//compute the cost
    		 		// cout << "[" << i << "," << k << "]" << "[" << k + 1 << "," << j << "]";
    		 		int computedCost = cost[i][k] + cost[k+1][j] + arr[i - 1] * arr[k] * arr[j];
    		 		// cout << "- " << computedCost << "\n";
    		 		cost[i][j] = min(cost[i][j], computedCost);
     		 	}
    		 }
    	}
        
        // for(int i = 0; i <= mcount; i++) {
        // 	for(int j = 0; j <= mcount; j++) {
        // 		cout << cost[i][j] << " ";
        // 	}
        // 	cout << "\n";
        // }
        return cost[1][mcount];
    }
};

vector<int> convertToVec(string s) {
	vector<int> res;
	string t = "";
	for(int i = 0; i < s.length(); i++) {
		if(s[i] >= '0' && s[i] <= '9' || s[i] == '-') {
			t += s[i];
		}
		else if(!t.empty()) {
			res.push_back(stoi(t));
			t = "";
		}
	}
	return res;
}

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
	//freopen("output.txt", "w", stdout);
	#endif
	string s;
	while(getline(cin, s)) {
		vector<int> nums = convertToVec(s);
		Solution sol;
		cout << sol.matrixMultiplication(nums) << "\n";
		// break;
	}
	return 0;
}