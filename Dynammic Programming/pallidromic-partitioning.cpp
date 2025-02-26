#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

  	int palindromicPartitionTable(string &s) {
  		//TODO
  		vector<int> dp(s.length() + 1, 0);
  		for(int i = 1; i <= s.length(); i++) {
  			string t = "";
  			dp[i] = INT_MAX;
  			for(int j = i; j >= 1; j--) {
  				t += s[j-1];
  				if(isPallindrome(t)) {
  					dp[i] = min(dp[i], dp[j-1] + 1);
  				}
  			}
  		}
  		return dp[s.length()] - 1;
  	}

  	int palindromicPartitionMemo(string &s) {
  		int index = 0;
  		vector<int> memo(s.length(), -1);
  		return palindromicPartitionMemo(s, memo, index) - 1;
  	}

  	int palindromicPartitionMemo(string &s, vector<int> &memo, int index) {
  		if(index == s.length()) {
  			return 0;
  		}
  		else if(memo[index] != -1) {
  			return memo[index];
  		}
  		else {
  			string temp = "";
  			int count = INT_MAX;
  			for(int j = index; j < s.length(); j++) {
  				temp += s[j];
  				if(isPallindrome(temp)) {
    				count = min(count, 1 + palindromicPartitionMemo(s, memo, j + 1));
    			}
  			}
  			memo[index] = count;
  			return count;
  		}
  	}

    int palindromicPartition(string &s) {
        // code here
        int index = 0;
        return palindromicPartition(s, index) - 1;
    }

    int palindromicPartition(string &s, int index) {
    	if(index == s.length()) {
    		return 0;
    	}
    	else {
    		string temp = "";
    		int count = INT_MAX;
    		for(int j = index; j < s.length(); j++) {
    			temp += s[j];
    			if(isPallindrome(temp)) {
    				count = min(count, 1 + palindromicPartition(s, j + 1));
    			}
    		}
    		return count;
    	}
    }

    bool isPallindrome(string &s) {
    	int i = 0;
    	for(int i = 0; i < s.length() / 2; i++) {
    		if(s[i] != s[s.length() - i - 1]) {
    			return false;
    		}
    	}
    	return true;
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
    //freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--) {
    	string s;
    	cin >> s;
    	Solution sol;
    	assertEquals(sol.palindromicPartitionMemo(s),sol.palindromicPartitionTable(s));
    }
    return 0;
}