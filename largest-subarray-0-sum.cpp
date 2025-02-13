/*
Given an array arr containing both positive and negative integers, the task is to compute the length of the largest subarray that has a sum of 0.

Examples:

Input: arr[] = [15, -2, 2, -8, 1, 7, 10, 23]
Output: 5
Explanation: The largest subarray with a sum of 0 is [-2, 2, -8, 1, 7].
Input: arr[] = [2, 10, 4]
Output: 0
Explanation: There is no subarray with a sum of 0.
Input: arr[] = [1, 0, -4, 3, 1, 0]
Output: 5
Explanation: The subarray is [0, -4, 3, 1, 0].
Constraints:
1 ≤ arr.size() ≤ 106
−103 ≤ arr[i] ≤ 103, for each valid i
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
	int maxLen(vector<int>& arr) {
        unordered_map<int, int> sumToIndex;
        int currentSum = 0, result = 0;
        for(int i = 0; i < arr.size(); i++) {
            currentSum += arr[i];
            if(currentSum == 0) {
                result = i + 1;
            }
            else if(sumToIndex.find(currentSum) != sumToIndex.end()) {
                result = max(result, i - sumToIndex[currentSum]);
            }
            else {
                sumToIndex[currentSum] = i;
            }
        }
        return result;
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
	vector<int> results = {5, 0, 5, 1};
	int i = 0;
	while(getline(cin, s)) {
		vector<int> nums = convertToVec(s);
		Solution s;
		if(!assertEquals(results[i++], s.maxLen(nums))) {
			cout << "	Failed for input ==> ";
			printv(nums);
			cout << "\n";
		}
	}
	return 0;
}