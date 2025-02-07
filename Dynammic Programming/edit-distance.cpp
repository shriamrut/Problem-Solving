/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

*/
#include <bits/stdc++.h>
//#define ONLINE_JUDGE
using namespace std;

class Solution {
public:

	int minDistanceTableMemoryOptimized(string &word1, string &word2) {
		int n = word1.length(), m = word2.length();

		vector<int> prev(m + 1);

		for(int j = 0; j <= m; j++) {
			prev[j] = j;
		}

		for(int i = 1; i <= n; i++) {
			vector<int> curr(m + 1);
			curr[0] = i;
			for(int j = 1; j <= m; j++) {
				if(word1[i-1] == word2[j-1]) {
					curr[j] = prev[j-1];
				}
				else {
					curr[j] = min(prev[j], min(curr[j-1], prev[j-1])) + 1;
				}
			}
			prev = curr;
		}
		return prev[m];
	}

	int minDistanceTable(string &word1, string &word2) {
		int n = word1.length(), m = word2.length();
		vector<vector<int>> dp(n + 1, vector<int> (m + 1));
		//Intialize the table
		for(int i = 0; i <= n; i++) {
			dp[i][0] = i;
		}

		for(int j = 0; j <= m; j++) {
			dp[0][j] = j;
		}

		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if(word1[i-1] == word2[j-1]) {
					dp[i][j] = dp[i-1][j-1];
				}
				else {
					dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
				}
			}
		}
		return dp[n][m];
	}

	int minDistanceMemo(string &word1, string &word2) {
		vector<vector<int>> memo(word1.length(), vector<int> (word2.length(), -1));
		return minDistanceMemo(word1, word2, memo, word1.length() - 1, word2.length() - 1);
	}

	int minDistanceMemo(string &word1, string &word2, vector<vector<int>> &memo, int i, int j) {
		if(i < 0 && j >= 0) {
			return j + 1;
		}
		else if(j < 0 && i >= 0) {
			return i + 1;
		}
		else if(i < 0 && j < 0) {
			return 0;
		}
		else if(memo[i][j] != -1) {
			return memo[i][j];
		}
		else if(word1[i] == word2[j]) {
			memo[i][j] = minDistanceMemo(word1, word2, memo, i - 1, j - 1);
			return memo[i][j];
		}
		else {
			memo[i][j] = min(minDistanceMemo(word1, word2, memo, i - 1, j - 1) + 1, 
    				   min(minDistanceMemo(word1, word2, memo, i - 1, j) + 1,
    				   minDistanceMemo(word1, word2, memo, i, j - 1) + 1));
			return memo[i][j];
		}
	}

    int minDistanceRecurse(string &word1, string &word2) {
        return minDistanceRecurse(word1, word2, word1.length() - 1, word2.length() - 1);
    }

    int minDistanceRecurse(string &word1, string &word2, int i, int j) {
    	if(i < 0 && j >= 0) {
    		return j + 1;
    	}
    	else if(j < 0 && i >= 0) {
    		return i + 1;
    	}
    	else if(i < 0 && j < 0) {
    		return 0;
    	}
    	else if(word1[i] == word2[j]) {
    		//equal case
    		return minDistanceRecurse(word1, word2, i - 1, j - 1);
    	}
    	else {
    		/*
    			word1[i] != word2[j]
    			options available for word1[i]
    			1) Replace - you have replaced word1[i] with word2[j]
    				minDistance(word1, word2, i - 1, j - 1) + 1;
    			2) Remove - you removed word1[i]
    				minDistance(word1, word2, i - 1, j) + 1
    			3) Insert a character - you insert word2[j] in word1[i]. 
    			Note your i doesn't change see an example
    			s = s[0], s[1], s[2]; assume i = 1
    			t = t[0], t[1], t[2]; assume j = 2
    			when you insert t[2] as a character between s[1] and s[2]
    			then
    			s = s[0], s[1], s[2], s[3]
    			but your i doesn't change here as we are yet to overcome it, but j changes and we have satisfied t[j] / t[2].
    				minDistance(word1, word2, i, j - 1) + 1
    		*/
    		return min(minDistanceRecurse(word1, word2, i - 1, j - 1) + 1, 
    				   min(minDistanceRecurse(word1, word2, i - 1, j) + 1,
    				   minDistanceRecurse(word1, word2, i, j - 1) + 1));
    	}
    }
};

void assertEquals(int a, int b) {
	if(a == b) {
		//printf("(%d == %d) - PASS\n", a, b);
		cout << "(" << a << " == " << b << ")" << " - PASS \n";
	}
	else {
		//printf("(%d != %d) - FAIL\n", a, b);
		cout << "(" << a << " != " << b << ")" << " - FAIL \n";
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
		string word1, word2;
		cin >> word1 >> word2;
		Solution s;
		assertEquals(s.minDistanceMemo(word1, word2), s.minDistanceTableMemoryOptimized(word1, word2));
	}
	return 0;
}