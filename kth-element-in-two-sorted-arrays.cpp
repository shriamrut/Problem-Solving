#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> merge(vector<int> &nums1, vector<int> &nums2) {
		vector<int> mergedArray;
		int i = 0, j = 0;
		while(i < nums1.size() && j < nums2.size()) {
			if(nums1[i] < nums2[j]) {
				mergedArray.push_back(nums1[i]);
				i++;
			}
			else {
				mergedArray.push_back(nums2[j]);
				j++;
			}
		}
		while(i < nums1.size()) {
			mergedArray.push_back(nums1[i]);
			i++;
		}

		while(j < nums2.size()) {
			mergedArray.push_back(nums2[j]);
			j++;
		}

		return mergedArray;
	}

	int findKthElementBetterSolution1(vector<int> &nums1,
	 vector<int> &nums2, int k) {
		vector<int> mergedArray = merge(nums1, nums2);
		return mergedArray.at(k);
	}

	int findKthElementBestSolution(vector<int> &nums1, 
		vector<int> &nums2, int k) {
		if(nums1.size() > nums2.size()) {
			return findKthElementBestSolution(nums2, nums1, k);
		}
		int n1 = nums1.size(), n2 = nums2.size();
		int n = n1 + n2;
		int low = 0, high = k;
		// int lowe = low, highe = high;
		while(low <= high) {
			int m1 = (low + high) / 2;
			int m2 = k - m1;
			int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
			if(m1 - 1 >= 0) {
				l1 = nums1[m1 - 1];
			} 
			if(m1 < nums1.size()) {
				r1 = nums1[m1];
			}
			if(m2 - 1 >= 0) {
				l2 = nums2[m2 - 1];
			}
			if(m2 < nums2.size()) {
				r2 = nums2[m2];
			}

			if(l1 <= r2 && l2 <= r1) {
				//found the partition
				// cout << m1 << " from nums1 \n" << m2 << " from nums2\n"; 
				return min(r1, r2);
			}
			else if(l1 > r2) {
				high = m1 - 1;
			}
			else if(l2 > r1) {
				low = m1 + 1;
			}

			// if(lowe == low && highe == high) {
			// 	cout << "Going for infinte loop, exiting early!";
			// 	return -1;
			// }
		}
		return 0;
	}

	int findKthElementBetterSolution2(vector<int> &nums1, vector<int> &nums2, int k) {
		//merge here but only keep track of indices
		int i = 0, j = 0, ik = 0;
		while(i < nums1.size() && j < nums2.size()) {
			if(nums1[i] < nums2[j]) {
				if(ik == k) {
					return nums1[i];
				}
				i++;
			}
			else {
				if(ik == k) {
					return nums2[j];
				}
				j++;
			}
			ik++;
		}
		while(i < nums1.size()) {
			if(ik == k) {
				return nums1[i];
			}
			i++;
			ik++;
		}
		while(j < nums2.size()) {
			if(ik == k) {
				return nums2[j];
			}
			j++;
			ik++;
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
		int n, m;
		cin >> n >> m;
		vector<int> nums1(n), nums2(m);
		for(int i = 0; i < n; i++) {
			cin >> nums1[i];
		}

		for(int i = 0; i < m; i++) {
			cin >> nums2[i];
		}

		int k;
		cin >> k;
		Solution sol;
		assertEquals(sol.findKthElementBestSolution(nums1, nums2, k), sol.findKthElementBetterSolution2(nums1, nums2, k));
	}
	return 0;
}