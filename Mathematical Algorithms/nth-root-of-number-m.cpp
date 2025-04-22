#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int solveUsingMath(int n, int m) {
		int f = log(m) / log(n);
		if(pow(n, f) == m) {
			return f;
		}
		else {
			return -1;
		}
	}

	int powerCustom(int n, int m, int k) {
		int result = 1;
		while(m > 0) {
			if(m & 1) {
				result = result * n;
				m = m - 1;
				continue;
			}
			n = (n * n);
			m = m / 2;
			//cout << n << " " << m << " " << result << "\n";
			if(result > k || n > k) {
				return 1;
			}
		}
		return (result == k)? 0: (result > k)? 1: -1;
	}
	int solveUsingBinarySearch(int n, int m) {
		int low = 1, high = m;
		while(low <= high) {
			//cout << "Search space: " << low << " " << high << "\n";
			int mid = (low + high) / 2;
			int res = powerCustom(n, mid, m);
			//cout << n << " " << mid << " " << m << " " << res << "\n";
			if(res == 0) {
				return mid;
			} 
			else if(res == 1) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
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
		Solution s;
		assertEquals(s.solveUsingMath(n, m), s.solveUsingBinarySearch(n, m));
	}
	return 0;
}
