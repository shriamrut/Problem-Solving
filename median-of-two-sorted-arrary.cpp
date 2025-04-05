#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    double findMedianSortedArraysOptim(vector<int> nums1, vector<int> nums2) {
        if(nums1.size() > nums2.size()) {
        	return findMedianSortedArraysOptim(nums2, nums1);
        }
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1 + n2;
        int low = 0, high = n1;
        // int lowe = low, highe = high;
        while(low <= high) {
        	int m1 = (low + high) / 2;
        	int m2 = (n/2) - m1;
        	int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
        	if(m1 <= nums1.size() && m1 >= 1) {
        		l1 = nums1[m1 - 1];
        	}
        	if(m1 < nums1.size()) {
        		r1 = nums1[m1];
        	}
        	if(m2 <= nums2.size() && m2 >= 1) {
        		l2 = nums2[m2 - 1];
        	}
        	if(m2 < nums2.size()) {
        		r2 = nums2[m2];
        	}
        	if(l1 <= r2 && l2 <= r1) {
        		// we found the partition
        		if(n % 2 == 0) {
        			return (double) (max(l1, l2) + min(r1, r2)) / 2.0;
        		}
        		else {
        			return min(r1, r2);
        		}
        	}
        	else if(l1 > r2) {
        		high = m1 - 1;
        	}
        	else if(l2 > r1) {
        		low = m1 + 1;
        	}

        	// if(low == lowe && high == highe) {
        	// 	cout << "l1 l2\n";
        	// 	cout << l1 << " " << l2 << "\n";
        	// 	cout << "r1 r2\n";
        	// 	cout << r1 << " " << r2 << "\n";
        	// 	cout << "Screwed! infinite iteration\n";
        	// 	return -1;
        	// }
        }
        return 0.0;
    }

    double findMedianArraysBetter(vector<int> nums1, vector<int> nums2) {
    	vector<int> mergedArray = merge(nums1, nums2);
    	return computeMedian(mergedArray);
    }

    double findMedianBrute(vector<int> nums1, vector<int> nums2) {
    	nums1.insert(nums1.begin() + nums1.size(), nums2.begin(), nums2.end());
    	sort(nums1.begin(), nums1.end());
    	return computeMedian(nums1);
    }

    double computeMedian(vector<int> &nums) {
    	int n = nums.size();
    	int mid = n / 2;
    	if(n % 2 == 0) {
    		return (double) (nums[mid] + nums[mid-1]) / 2.0;
    	}
    	else {
    		return nums[mid];
    	}
    }

    vector<int> merge(vector<int> &nums1, vector<int> &nums2) {
    	int i = 0, j = 0;
    	vector<int> mergedArray;
    	int n1 = nums1.size(), n2 = nums2.size();

    	while(i < n1 && j < n2) {
    		if(nums1[i] < nums2[j]) {
    			mergedArray.push_back(nums1[i]);
    			i++;
    		}
    		else {
    			mergedArray.push_back(nums2[j]);
    			j++;
    		}
    	}
    	while(i < n1) {
    		mergedArray.push_back(nums1[i]);
    		i++;
    	}
    	while(j < n2) {
    		mergedArray.push_back(nums2[j]);
    		j++;
    	}
    	return mergedArray;
    }
};

void assertEquals(double a, double b) {
	if(a == b) {
		cout << "PASS  (" << a << " == " << b << ")\n";
	}
	else {
		cout << "FAIL  (" << a << " != " << b << ")\n";
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
		vector<int> arr1(n), arr2(m);
		for(int i = 0; i < n; i++) {
			cin >> arr1[i];
		}
		for(int i = 0; i < m; i++) {
			cin >> arr2[i];
		}
		Solution s;
		assertEquals(s.findMedianSortedArraysOptim(arr1, arr2), s.findMedianArraysBetter(arr1, arr2));
	}
	return 0;
}