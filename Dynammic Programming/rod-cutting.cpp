/*
Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:


Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

You should perform the cuts in order, you can change the order of the cuts as you wish.

The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

Return the minimum total cost of the cuts.

 

Example 1:


Input: n = 7, cuts = [1,3,4,5]
Output: 16
Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:

The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 (i.e. the second part of the first cut), the third is done to a rod of length 4 and the last cut is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20.
Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).
Example 2:

Input: n = 9, cuts = [5,6,1,4,2]
Output: 22
Explanation: If you try the given cuts ordering the cost will be 25.
There are much ordering with total cost <= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 which is the minimum possible.
 

Constraints:

2 <= n <= 106
1 <= cuts.length <= min(n - 1, 100)
1 <= cuts[i] <= n - 1
All the integers in cuts array are distinct.
*/

/*
Dry run first iteration for minCostTable

cuts = [1, 3, 4, 5]

after insertion,
cuts = [0, 1, 3, 4, 5, 7]
ind  = [0, 1, 2, 3, 4, 5]

m = 6

find minCost from 0 to 5

len = 3 (3 <= 6)

cost[i][j] = cost[0][2] 

k = 1 to 1

cost[0][2] = min(cost[0][2], cost[0][1] + cost[1][2] + cuts[2] - cuts[1])
cost[0][2] = min(inf, 0 + 0 + 3 - 0) = min(inf, 3) = 3

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 

    int minCostTable(int n, vector<int> &cuts) {
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int> (m, 0));
        for(int i = 0; i < m; i++) {
            dp[i][i] = 0; 
        }
        for(int i = 0; i + 1 < m; i++) {
            dp[i][i+1] = 0;
        }

        for(int len = 3; len <= m; len++) {
            for(int i = 0; i + len - 1 < m; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for(int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], 
                        dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
                }
            }
        }
        return dp[0][m-1];
    }

    int minCostMemo(int n, vector<int> &cuts) {
        vector<bool> canBeCut(n, false);
        for(int i = 0; i < cuts.size(); i++) {
            canBeCut[cuts[i]] = true;
        }
        vector<vector<int>> memo(n + 1, vector<int> (n + 1, -1));
        return minCostMemo(0, n, memo, canBeCut);
    }

    int minCostMemo(int beg, int end, vector<vector<int>> &memo, vector<bool> &canBeCut) {
        if(beg >= end) {
            return 0;
        }
        else if(memo[beg][end] != -1) {
            return memo[beg][end];
        }
        else {
            int currentMinCost = INT_MAX;
            for(int k = beg + 1; k < end; k++) {
                if(canBeCut[k]) {
                    canBeCut[k] = false;
                    currentMinCost = min(currentMinCost,
                        minCostMemo(beg, k, memo, canBeCut) + minCostMemo(k, end, memo, canBeCut) + (end - beg));
                    canBeCut[k] = true;
                }
            }
            currentMinCost = (currentMinCost == INT_MAX)? 0: currentMinCost;
            memo[beg][end] = currentMinCost;
            return currentMinCost;
        }
    }

    int minCost(int n, vector<int>& cuts) {
        vector<bool> canBeCut(n, false);
        for(int i = 0; i < cuts.size(); i++) {
            canBeCut[cuts[i]] = true;
        }
        return minCost(0, n, canBeCut);
    }

    int minCost(int beg, int end, vector<bool> &canBeCut) {
        if(beg >= end) {
            return 0;
        }
        else {
            int currentMinCost = INT_MAX;
            for(int k = beg + 1; k < end; k++) {
                if(canBeCut[k]) {
                    canBeCut[k] = false;
                    currentMinCost = min(currentMinCost,
                        minCost(beg, k, canBeCut) + minCost(k, end, canBeCut) + (end - beg));
                    canBeCut[k] = true;
                }
            }
            return (currentMinCost == INT_MAX)? 0: currentMinCost;
        }
    }
};

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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int size;
        cin >> size;
        vector<int> cuts(size);
        for(int i = 0; i < size; i++) {
            cin >> cuts[i];
        }
        Solution s;
        assertEquals(s.minCostMemo(n, cuts), s.minCostTable(n, cuts));
    }
    return 0;
}