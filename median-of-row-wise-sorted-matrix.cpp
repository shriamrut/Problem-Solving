#include <bits/stdc++.h>
using namespace std;

void printv(vector<int> &vec) {
	cout << "[";
	for(int &element: vec) {
		cout << element << " ";
	}
	cout << "]\n";
}
class Solution{
public:

	vector<int> flatten(vector<vector<int>> &matrix) {
		vector<int> flattened;
		int rows = matrix.size();
		for(int i = 0; i < rows; i++) {
			int cols = matrix[i].size();
			for(int j = 0; j < cols; j++) {
				flattened.push_back(matrix[i][j]);
			}
		}
		return flattened;
	}

	int upperBound(vector<int> &vec, int k) {
		int low = 0, high = vec.size() - 1;
		while(low <= high) {
			int mid = (low + high) / 2;
			if(vec[mid] >= k) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		return low;
	}
	int countOfElementsLessThan(vector<vector<int>> &matrix, int k) {
		int rows = matrix.size();
		int cols = matrix[0].size();
		int res = 0;
		// cout << "countOfLessThan: " << k << "\n";
		for(int i = 0; i < rows; i++) {
			int uB = upperBound(matrix[i], k);
			res += uB;
			// cout << "row " << i << " " << uB << "\n";
		}
		return res;
	}
	int findMedianBest(vector<vector<int>> &matrix) {
		int low = INT_MAX, high = INT_MIN;
		int rows = matrix.size();
		int col = matrix[0].size();
		for(int i = 0; i < rows; i++) {
			low = min(low, matrix[i][0]);
			high = max(high, matrix[i][col - 1]);
		}
		int req = ((rows * col) / 2);
		// cout << "Req: " << req << "\n";
		while(low <= high) {
			int mid = (low + high) / 2;
			int count = countOfElementsLessThan(matrix, mid);
			if(count == req) {
				return mid;
			}
			else if(count > req) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		return high;
	}
	
    int findMedianBrute(vector<vector<int>>&matrix) {
      	vector<int> flattened = flatten(matrix);
      	sort(flattened.begin(), flattened.end());
      	return computeMedian(flattened);
    }

    int computeMedian(vector<int> &array) {
    	int size = array.size();
    	int mid = size / 2;
    	return array[mid];
    }

    vector<int> merge(vector<int> &a, vector<int> &b) {
    	vector<int> mergedArray;
    	int i = 0, j = 0;
    	while(i < a.size() && j < b.size()) {
    		if(a[i] < b[j]){
    			mergedArray.push_back(a[i]);
    			i++;
    		}
    		else {
    			mergedArray.push_back(b[j]);
    			j++;
    		}
    	}
    	while(i < a.size()) {
    		mergedArray.push_back(a[i]);
    		i++;
    	}
    	while(j < b.size()) {
    		mergedArray.push_back(b[j]);
    		j++;
    	}
    	return mergedArray;
    }

    int findMedianBetter1(vector<vector<int>> &matrix) {
    	int rows = matrix.size();
    	for(int i = 1; i < rows; i++) {
    		matrix[i] = merge(matrix[i], matrix[i - 1]);
    	}
    	return computeMedian(matrix[rows - 1]);
    }

    int findMedianBetter2(vector<vector<int>> &matrix) {
    	int rows = matrix.size();
    	recursiveMerge(matrix, 0, rows - 1);
    	return computeMedian(matrix[rows - 1]);
    }

    void recursiveMerge(vector<vector<int>> &matrix, int beg, int end) {
    	if(beg >= end) {
    		return;
    	}
    	int mid = (beg + end) / 2;
    	recursiveMerge(matrix, beg, mid);
    	recursiveMerge(matrix, mid + 1, end);
    	matrix[end] = merge(matrix[mid], matrix[mid + 1]);
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
		vector<vector<int>> matrix(n, vector<int> (m));
		vector<vector<int>> cmatrix(n, vector<int> (m));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> matrix[i][j];
				cmatrix[i][j] = matrix[i][j];
			}
		}
		Solution s;
		assertEquals(s.findMedianBetter2(matrix), s.findMedianBest(cmatrix));
	}
	return 0;
}
	