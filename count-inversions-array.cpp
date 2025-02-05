/*
Given an array of integers arr[]. Find the Inversion Count in the array.
Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 

Examples:

Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

Input: arr[] = [2, 3, 4, 5, 6]
Output: 0

Explanation: As the sequence is already sorted so there is no inversion count.
Input: arr[] = [10, 10, 10]
Output: 0

Explanation: As all the elements of array are same, so there is no inversion count.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104


*/

#include <bits/stdc++.h>
//#define ONLINE_JUDGE
using namespace std;

void printv(vector<int> &arr, int i, int j) {
	cout <<"arr[" << i << ":" << j << "] - [";
	for(int k = i; k <= j; k++) {
		cout << arr[k] << " ";
	}
	cout << "]\n";
}

class Solution {
	public:
	int inversionCountBruteForce(vector<int> &arr) {
		int N = arr.size();
		int count = 0;
		for(int i = 0; i < N; i++) {
			//cout << "arr[" << i << "]: " << arr[i] <<  "\n";
			for(int j = i + 1; j < N; j++) {
				//cout << "arr[" << j << "]: " << arr[j] <<  "\n";
				if(arr[i] > arr[j]) {
					//cout << "found inversion - " << arr[i] << " " << arr[j] << "\n";
					count++;
				}
			}
		}
		return count;
	}
	int inversionCount(vector<int> &arr) {
        int count = 0;
        mergeSortUtil(arr, 0, arr.size() - 1, count);
        return count;
    }

	private:
    void mergeSortUtil(vector<int> &arr, int beg, int end, int &count) {
    	if(beg >= end) {
    		return;
    	}
    	else {
    		int mid = (beg + end) / 2;
    		mergeSortUtil(arr, beg, mid, count);
    		mergeSortUtil(arr, mid + 1, end, count);
    		merge(arr, beg, mid, end, count);
    	}
    }

    void merge(vector<int> &arr, int beg, int mid, int end, int &count) {
    	int N = (end - beg) + 1;
    	vector<int> res(N);
    	int i = beg, j = mid + 1, k = 0;
    	cout << "Before merging\n";
    	printv(arr, beg, mid);
    	printv(arr, mid + 1, end);
    	while(i <= mid && j <= end) {
    		if(arr[i] <= arr[j]) {
    			res[k] = arr[i];
    			i++;
    		}
    		else {
    			count++;
    			res[k] = arr[j];
    			j++;
    		}
    		k++;
    	}
    	while(i <= mid) {
    		/*
    		int t = ((mid + 1) - end) + 1;
    		cout << arr[i] << " is present, Incrementing count by " << t << "\n"; 
    		count += t;*/
    		res[k] = arr[i];
    		k++;
    		i++;
    	}
    	while(j <= end) {
    		res[k] = arr[j];
    		j++;
    		k++;
    	}

    	//Overwrite result to arr
    	for(int i = beg; i <= end; i++) {
    		arr[i] = res[i - beg];
    	}
    }
};


void printv(vector<int> &vec) {
	cout << "[";
	for(int &x: vec) {
		cout << x << " ";
	}
	cout << "]";
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

void assertEquals(int a, int b) {
	if(a == b) {
		cout << "(" << a << " == " << b << ")" << " - PASS \n";
	}
	else {
		cout << "(" << a << " != " << b << ")" << " - FAIL \n";
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
		printv(nums);
		cout <<"\n";
		Solution s;
		assertEquals(s.inversionCountBruteForce(nums), s.inversionCount(nums));
	}
}