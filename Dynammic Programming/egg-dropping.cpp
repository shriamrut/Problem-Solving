/*
You are given n identical eggs and you have access to a k-floored building from 1 to k.

There exists a floor f where 0 <= f <= k such that any egg dropped from a floor higher than f will break, and any egg dropped from or below floor f will not break.
There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the egg breaks on a certain floor, it will break on any floor above.
Return the minimum number of moves you need to determine the value of f with certainty.

Examples:

Input: n = 1, k = 2
Output: 2
Explanation: Drop the egg from floor 1. If it breaks, we know that f = 0. Otherwise, drop the egg from floor 2.If it breaks, we know that f = 1.  If it does not break, then we know f = 2. Hence, we need at minimum 2 moves to determine with certainty what the value of f is.

Input: n = 10, k = 5
Output: 3
Explanation: Drop the egg from floor 2. If it breaks, test floor 1 with a remaining egg.If it doesn’t break, drop from floor 4. If it breaks, test floor 3. If it still doesn’t break, we know the critical floor is 5.Hence, with a minimum of 3 moves, we can find the critical floor.

Input: n = 2, k = 10
Output: 4
Explanation: Drop the egg from floor 4. If it breaks, we only need to test floors 1 to 3 with the remaining egg.If it doesn't break, drop the egg from floor 7. If it breaks, we only need to test floors 5 and 6. If it doesn't break again, drop the egg from floor 9. If it breaks, test floor 8. If it still doesn’t break, we know the critical floor is 10.Hence, with a minimum of 4 moves, we can determine the critical floor.

Constraints:
1<= n <=100
1<= k <=100
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.

    int eggDropTableSpaceOptimized2(int n, int k) {
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        int m = 0;
        while(curr[n] < k) {
            m++;
            for(int x = 1; x <= n; x++) {
                curr[x] = 1 + prev[x - 1] + prev[x];
            }
            prev = curr;
        }
        return m;
    }
    int eggDropTableSpaceOptimized(int n, int k) {
        // moves, n eggs -> floors
        vector< vector<int> > dp(k + 1, vector<int> (n + 1, 0));
        int m = 0;
        while(dp[m][n] < k) {
            m++;
            for(int x = 1; x <= n; x++) {
                dp[m][x] = 1 + dp[m-1][x-1] + dp[m-1][x];
            }
        }
        return m;
    }

    int eggDropTable(int n, int k) {

        vector<vector<int>> dp(n + 1, vector<int> (k + 1));
        for(int f = 1; f <= k; f++) {
            dp[1][f] = f; // 1 egg, f floor, worst case you try dropping the 1 egg from all floors 0..f hence f
        }

        for(int e = 1; e <= n; e++) {
            dp[e][0] = 0; // e eggs, 0 floors, 0 moves
            dp[e][1] = 1; // e eggs, 1 floors, 1 move is required as only 1 floor exists
        }

        for(int e = 2 ; e <= n; e++) {
            for(int f = 2; f <= k; f++) {
                dp[e][f] = INT_MAX;
                for(int x = 1; x <= f; x++) {
                    //dp[e-1][x-1] - egg is gets broken at floor x, then move to x - 1
                    //dp[e][f-x] - egg is not broken, check f-x floors
                    dp[e][f] = min(dp[e][f], max(dp[e-1][x-1], dp[e][f-x]) + 1);
                }
            }
        }
        return dp[n][k];
    }

    int eggDropMemo(int n, int k) {
        vector< vector<int> > memo(n + 1, vector<int> (k + 1, -1));
        return eggDropMemo(memo, n, k);
    }

    int eggDropMemo(vector< vector<int> > &memo, int n, int k) {
        if(k == 0) {
            return 0;
        }
        else if(n == 0) {
            return INT_MAX;
        }
        else if(memo[n][k] != -1) {
            return memo[n][k];
        }
        else {
            int result = INT_MAX;
            for(int f = 1; f <= k; f++) {
                int moves = max(eggDropMemo(memo, n - 1, f - 1), eggDropMemo(memo, n, k - f));
                if(moves != INT_MAX) {
                    moves++;
                }
                result = min(moves, result);
            }
            memo[n][k] = result;
            return result;
        }
    }

    int eggDropRecurse(int n, int k) {
        // N - eggs, K floors
        if(k == 0) {
            return 0;
        }
        else if(n == 0) {
            return INT_MAX;
        }
        else {
            int result = INT_MAX;
            for(int f = 1; f <= k; f++) {
                // egg drops
                int moves = max(eggDropRecurse(n - 1, f - 1), eggDropRecurse(n, k - f));
                if(moves != INT_MAX) {
                    moves++;
                }
                result = min(result, moves);
            }
            return result;
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
        int n, k;
        cin >> n >> k;
        Solution s;
        assertEquals(s.eggDropTableSpaceOptimized(n, k) ,s.eggDropTableSpaceOptimized2(n, k));
    }
    return 0;
}
