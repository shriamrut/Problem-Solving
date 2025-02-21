#include <bits/stdc++.h>
using namespace std;

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

class Solution {
public:
	int coinChangeTableSpaceOptimized(vector<int>& coins, int amount) {
		int n = coins.size();
		vector<int> prev(amount + 1, INT_MAX);
		for(int i = 1; i <= n; i++) {
			vector<int> curr(amount + 1);
			for(int j = 1; j <= amount; j++) {
				if(j >= coins[i-1]) {
					int r1 = prev[j];
					int r2 = curr[j - coins[i-1]];
					int r3 = prev[j - coins[i-1]];
					if(r2 != INT_MAX)
        				r2++;
        			if(r3 != INT_MAX)
        				r3++;
        			curr[j] = min(r1, min(r2, r3));
				}
				else {
					curr[j] = prev[j];
				}
			}
			prev = curr;
		}
		int result = prev[amount];
		return (result == INT_MAX)? -1: result;
    }

	int coinChangeTable(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int> (amount + 1));

        for(int j = 0; j <= amount; j++) {
        	dp[0][j] = INT_MAX;
        }
        for(int i = 0; i <= n; i++) {
        	dp[i][0] = 0;
        }

        for(int i = 1; i <= n; i++) {
        	for(int j = 1; j <= amount; j++) {
        		if(j >= coins[i-1]) {
        			int r1 = dp[i-1][j];
        			int r2 = dp[i][j - coins[i-1]];
        			int r3 = dp[i-1][j - coins[i-1]];
        			if(r2 != INT_MAX)
        				r2++;
        			if(r3 != INT_MAX)
        				r3++;
        			dp[i][j] = min(r1, min(r2, r3));
        		}
        		else {
        			dp[i][j] = dp[i-1][j];
        		}
        	}
        }
        int result = dp[n][amount];
        return (result == INT_MAX)? -1: result;
    }

	int coinChangeMemo(vector<int>& coins, int amount) {
        vector<vector<int>> memo(coins.size(), vector<int> (amount + 1, -1));
        int result = coinChangeMemo(coins, memo, amount, 0);
        return (result == INT_MAX)? -1: result;
    }

    int coinChangeMemo(vector<int> &coins, 
    	vector<vector<int>> &memo, int amount, int index) {
    	if(amount == 0) {
    		return 0;
    	}
    	else if(index == coins.size() || amount < 0) {
    		return INT_MAX;
    	}
    	else if(memo[index][amount] != -1) {
    		return memo[index][amount];
    	}
    	else {
    		int r1 = coinChangeMemo(coins, memo, amount, index + 1);
    		int r2 = coinChangeMemo(coins, memo, amount - coins[index], index);
    		int r3 = coinChangeMemo(coins, memo, amount - coins[index], index + 1);
    		// avoid the integer overflow
    		if(r2 != INT_MAX)
    			r2 += 1;
    		if(r3 != INT_MAX)
    			r3 += 1;

    		int result = min(r1, min(r2, r3));
    		memo[index][amount] = result;
    		return result;
    	}
    }

    int coinChangeRecurse(vector<int>& coins, int amount) {
    	int result = INT_MAX, count = 0;
        coinChangeRecurse(coins, amount, 0, count, result);
        return (result == INT_MAX) ? -1: result;
    }

    void coinChangeRecurse(vector<int> &coins, int amount, int index, int count, 
    	int &result) {
    	// cout << "amount,count,index: " << amount << " " << count << " " << index  << "\n";
    	if(amount == 0) {
    		result = min(count, result);
    		return;
    	}
    	else if(index == coins.size()) {
    		return;
    	}
    	else if(amount < 0) {
    		return;
    	}
    	else {
    		coinChangeRecurse(coins, amount, index + 1, count, result);
    		coinChangeRecurse(coins, amount - coins[index], index, count + 1, result);
    		coinChangeRecurse(coins, amount - coins[index], index + 1, count + 1, result);
    		return;
    	}
    }
};

void printv(vector<int> &elements) {
	cout << "[";
	for(int &element: elements) {
		cout << element << " ";
	}
	cout << "]\n";
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin >> t;
	while(t--) {
		int n, amount;
		cin >> n >> amount;
		vector<int> coins(n);
		for(int i = 0; i < n; i++)
			cin >> coins[i];
		// cout << amount << "\n";
		// printv(coins);
		Solution s;
		assertEquals(s.coinChangeTableSpaceOptimized(coins, amount), s.coinChangeTable(coins, amount));
	}
	return 0;
}
