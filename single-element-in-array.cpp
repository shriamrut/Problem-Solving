#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

	int singleNonDuplicateBest(vector<int> &nums) {
		int n = nums.size();
		if(n == 1) {
			return nums[0];
		}
		else if(nums[0] != nums[1]) {
			return nums[0];
		}
		else if(nums[n-1] != nums[n-2]) {
			return nums[n-1];
		}
		else {
			int low = 1, high = n-2;
			// int lowe = low, highe = high;
			while(low <= high) {
				int mid = (low + high) / 2;
				if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
					return nums[mid];
				}
				else if((mid % 2 == 1 && nums[mid - 1] == nums[mid]) || (mid % 2 == 0 && nums[mid + 1] == nums[mid])) {
					low = mid + 1;
				}
				else {
					high = mid-1;
				}
				// if(lowe == low && highe == high) {
				// 	cout << "Loop is going forver!! break";
				// 	return -1;
				// }
			}
			return -1;
		}
	}

	int singleNonDuplicateBetter(vector<int>& nums) {
        int xorOfNums = 0;
        for(int &val: nums) {
            xorOfNums = xorOfNums ^ val;
        }
        return xorOfNums;
    }

    int singleNonDuplicateBrute(vector<int> &nums) {
        int n = nums.size();
        if(n == 1) {
            return nums[0];
        }

        // cout << "n: " << n << "\n";
        for(int i = 0; i < n; i++) {
        	// cout << "A " << i << "\n";
            if(i == (n - 1) && nums.at(n - 2) != nums.at(n - 1)) {
                return nums.at(i);
            }
            // cout << "B " << i << "\n";
            if(i == 0 && nums.at(0) != nums.at(1)) {
                return nums.at(i);
            } 
            // cout << "C " << i << "\n";
            if(i >= 1 && i < n - 1 && nums.at(i) != nums.at(i-1) && nums.at(i) != nums.at(i + 1)) {
                return nums.at(i);   
            }
            // cout << "D " << i << "\n";
        }
        return -1;
    }
};

void assertEquals(int a, int b) {
	if(a == b) {
		cout << "PASS ( " << a << " == " << b << ")\n";
	}
	else {
		cout << "FAIL ( " << a << " != " << b << ")\n";
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
		int n; 
		cin >> n;
		vector<int> nums(n);
		for(int i = 0; i < n; i++) {
			cin >> nums[i];
		}
		Solution s;
		assertEquals(s.singleNonDuplicateBetter(nums), s.singleNonDuplicateBest(nums));

	}
	return 0;
}