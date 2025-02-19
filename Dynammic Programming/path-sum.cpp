#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	void printGrid(vector<vector<int>> &grid) {
		for(int i = 0; i < grid.size(); i++) {
			cout << "[";
			for(int j = 0; j < grid[0].size(); j++) {
				cout << grid[i][j] << " ";
			}
			cout << "]\n";
		}
		cout << "\n";
	}
	void computePath(vector<vector<int>> &pathSum) {
		int i = pathSum.size() - 1, j = pathSum[0].size() - 1;
		while(i >= 0 && j >= 0) {
			cout << "{" << i << ", " << j << "}" << "\n";
			int minI = -1, minJ = -1, val = INT_MAX;

			//check if top value is minimum
			if(i - 1 >= 0 && pathSum[i-1][j] < val) {
				minI = i - 1;
				minJ = j;
				val = pathSum[i-1][j];
			}

			// check if left value in minimum
			if(j - 1 >= 0 && pathSum[i][j-1] < val) {
				minI = i;
				minJ = j - 1;
				val = pathSum[i][j-1];
			}
			i = minI;
			j = minJ;
		}
	}

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> pathSum(m, vector<int> (n));

        // fill the first row
        pathSum[0][0] = grid[0][0];
        for(int j = 1; j < n; j++) {
        	pathSum[0][j] = pathSum[0][j-1] + grid[0][j];
        }

        // fill the first coloumn
        for(int i = 1; i < m; i++) {
        	pathSum[i][0] = pathSum[i-1][0] + grid[i][0];
        }

        for(int i = 1; i < m; i++) {
        	for(int j = 1; j < n; j++) {
        		pathSum[i][j] = min(pathSum[i-1][j], pathSum[i][j-1]) + grid[i][j];
        	}
        }

        //TODO print the path
        // printGrid(pathSum);
        computePath(pathSum);
        return pathSum[m-1][n-1];
    }
};

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--) {
		int m, n;
		cin >> m >> n;
		vector<vector<int>> grid(m, vector<int>(n));
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				cin >> grid[i][j];
			}
		}
		Solution s;
		cout << s.minPathSum(grid) << "\n";

 	}
	return 0;
}