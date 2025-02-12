/*
Max Sum Increasing Subsequence
Difficulty: MediumAccuracy: 40.02%
Submissions: 202K+
Points: 4
Average Time: 25m
Given an array of positive integers arr. Find the maximum sum subsequence of the given array such that the integers in the subsequence are sorted in strictly increasing order i.e. a strictly increasing subsequence. 

Examples:

Input: arr[] = [1, 101, 2, 3, 100]
Output: 106
Explanation: The maximum sum of a increasing sequence is obtained from [1, 2, 3, 100].

Input: arr[] = [4, 1, 2, 3]
Output: 6
Explanation: The maximum sum of a increasing sequence is obtained from {1, 2, 3}.

Input: arr[] = [4, 1, 2, 4]
Output: 7
Explanation: The maximum sum of a increasing sequence is obtained from {1, 2, 4}.

Constraints:
1  ≤  arr.size()  ≤  103
1  ≤  arr[i]  ≤  105
*/  

#include <bits/stdc++.h>
//#define ONLINE_JUDGE
using namespace std;

void printv(vector<int> &vec) {
	cout << "[";
	for(int &x: vec) {
		cout << x << " ";
	}
	cout << "]";
}

class Solution {
public:

	int maxSumISTable(vector<int> &arr) {
		int n = arr.size();
		vector<int> dp(n + 1, 0);
		int result = 0;
		for(int ix = 1; ix <= n; ix++) {
			dp[ix] = arr[ix - 1];
			for(int lastIx = 1; lastIx < ix; lastIx++) {
				if(arr[ix-1] > arr[lastIx-1]) {
					dp[ix] = max(dp[ix], dp[lastIx] + arr[ix-1]);
				}
			}
			result = max(result, dp[ix]);
		}
		return result;
	}


	int maxSumISRecurseMemo2(vector<int> &arr) {
		arr.push_back(INT_MAX);
		int ix = arr.size() - 1, lastIx = arr.size() - 1;
		vector<vector<int>> memo(arr.size(), vector<int> (arr.size(), -1));
		return maxSumISRecurseMemo2(arr, memo, ix, lastIx);
	}

	int maxSumISRecurseMemo2(vector<int> &arr, vector<vector<int>> &memo, int ix, int lastIx) {
		if(ix < 0) {
			return 0;
		}
		else if(memo[ix][lastIx] != -1) {
			return memo[ix][lastIx];
		}
		else {
			int maxSum = maxSumISRecurseMemo2(arr, memo, ix - 1, lastIx);
			if(arr[ix] < arr[lastIx]) {
				maxSum = max(maxSumISRecurseMemo2(arr, memo, ix - 1, ix) + arr[ix],
					maxSum);
			}
			memo[ix][lastIx] = maxSum;
			return memo[ix][lastIx];
		}
	}

	int maxSumISRecurseMemo(vector<int> &arr) {
		int ix = 0, lastIx = -1;
		vector<vector<int>> memo(arr.size(), vector<int> (arr.size(), -1));
		return maxSumISRecurseMemo(arr, memo, ix, lastIx);
	}

	int maxSumISRecurseMemo(vector<int> &arr, vector<vector<int>> &memo, int ix, int lastIx) {
		if(ix >= arr.size()) {
			return 0;
		}
		else if(lastIx == -1) {
			return max(maxSumISRecurseMemo(arr, memo, ix + 1, lastIx), 
				maxSumISRecurseMemo(arr, memo, ix + 1, ix) + arr[ix]);
		}
		else if(memo[ix][lastIx] != -1) {
			return memo[ix][lastIx];
		}
		else {
			memo[ix][lastIx] = maxSumISRecurseMemo(arr, memo, ix + 1, lastIx);
			if(arr[ix] > arr[lastIx]) {
				memo[ix][lastIx] = max(memo[ix][lastIx], maxSumISRecurseMemo(arr, memo, ix + 1, ix) + arr[ix]);
				return memo[ix][lastIx];
			}
			return memo[ix][lastIx];
		}
		
	}

	int maxSumISRecurse(vector<int>& arr) {
        int ix = 0, lastIx = -1;
        return maxSumISRecurse(arr, ix, lastIx);
    }

    int maxSumISRecurse(vector<int> &arr, int ix, int lastIx) {
    	if(ix >= arr.size()) {
    		return 0;
    	}
    	else {
    		int sumWithOutIx = maxSumISRecurse(arr, ix + 1, lastIx);
    		int sumWithIx = INT_MIN;
    		if(lastIx == -1) {
    			sumWithIx = maxSumISRecurse(arr, ix + 1, ix) + arr[ix];
    		}
    		else if(lastIx != -1 && arr[ix] > arr[lastIx]) {
    			sumWithIx = maxSumISRecurse(arr, ix + 1, ix) + arr[ix];
    		}
    		return max(sumWithIx, sumWithOutIx);
    	}
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
		Solution s;
		if(!assertEquals(s.maxSumISTable(nums), s.maxSumISRecurseMemo2(nums))) {
			printv(nums);
		}
	}
	return 0;
}