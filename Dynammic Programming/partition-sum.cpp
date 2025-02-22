#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	bool canPartitionTableSpaceOptimized(vector<int> &nums) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if(sum & 1) {
			return false;
		}
		int requiredSum = sum / 2;
		int n = nums.size();
		vector<int> prev(requiredSum + 1, 0);
		prev[0] = 1;
		for(int i = 1; i <= n; i++) {
			vector<int> curr(requiredSum + 1);
			for(int j = 1; j <= requiredSum; j++) {
				if(j >= nums[i-1]) {
					curr[j] = prev[j - nums[i-1]] || prev[j];
				}
				else {
					curr[j] = prev[j];
				}
			}
			prev = curr;
		}
		return prev[requiredSum];
	}

	bool canPartitionTable(vector<int> &nums) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if(sum & 1) {
			return false;
		}
		int requiredSum = sum / 2;
		int n = nums.size();

		vector<vector<int>> dp(n + 1, vector<int> (requiredSum + 1));
		dp[0][0] = 1;
		for(int j = 1; j <= requiredSum; j++) {
			dp[0][j] = 0;
		}
		for(int i = 1; i <= n; i++) {
			dp[i][0] = 0;
		}

		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= requiredSum; j++) {
				if(j >= nums[i-1]) {
					dp[i][j] = (dp[i-1][j - nums[i-1]] || dp[i-1][j]);
				}
				else {
					dp[i][j] = dp[i-1][j];
				}
			}
		}
		return dp[n][requiredSum];
	}

	bool canPartitionMemo(vector<int> &nums) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if(sum & 1) {
			return false;
		}
		int requiredSum = sum / 2;
		vector<vector<int>> memo(nums.size(), vector<int> (requiredSum + 1, -1));
		return (canPartitionMemo(nums, memo, requiredSum, 0) == 1);
	}

	int canPartitionMemo(vector<int> &nums, vector<vector<int>> &memo, int requiredSum, int index) {
		if(requiredSum == 0) {
			return 1;
		}
		else if(index == nums.size() || requiredSum < 0) {
			return 0;
		}
		else if(memo[index][requiredSum] != -1) {
			return memo[index][requiredSum];
		}
		else {
			bool includeVal = canPartitionMemo(nums, memo, requiredSum - nums[index], index + 1);
			bool excludeVal = canPartitionMemo(nums, memo, requiredSum, index + 1);
			memo[index][requiredSum] = (int) (includeVal || excludeVal);
			return memo[index][requiredSum];
		}
	}

    bool canPartitionRecurse(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1)
        	return false;
        int requiredSum = sum / 2;
        return canPartitionRecurse(nums, requiredSum, 0);
    }

    bool canPartitionRecurse(vector<int> &nums, int requiredSum, int index) {
    	if(requiredSum == 0) {
    		return true;
    	}
    	else if(index == nums.size()) {
    		return false;
    	}
    	else {
    		return canPartitionRecurse(nums, requiredSum - nums[index], index + 1) ||
    			canPartitionRecurse(nums, requiredSum, index + 1);
    	}
    }
};

void printv(vector<int> &vec) {
	cout << "[";
	for(int &x: vec) {
		cout << x << " ";
	}
	cout << "]\n";
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

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif
	string s;

	while(getline(cin, s)) {
		vector<int> nums = convertToVec(s);
		Solution s;
		if(!assertEquals(s.canPartitionTable(nums), s.canPartitionTableSpaceOptimized(nums))) {
			printv(nums);
		}
	}
	return 0;
}