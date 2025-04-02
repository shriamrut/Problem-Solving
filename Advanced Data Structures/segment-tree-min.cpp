/*
Problem: Minimum Element in Range [l,r] with multiple queries
Time Complexity for Segment Tree:
    Query: O(log(n))
    Update: O(log(n))
    Build: O(nlog(n))
*/

#include <bits/stdc++.h>
using namespace std;

int getSegTreeSize(int n) {
	int lg = (int) ceil((float) log2(n)) + 1;
	int size = pow(2, lg)-1;
	return size;
}

int buildTree(vector<int> &segTree, vector<int> &arr, int idx, int beg, int end) {
	if(beg == end) {
		segTree[idx] = arr[beg];
		return arr[beg];
	}
	else {
		int mid = (beg + end) / 2;
		segTree[idx] = min(buildTree(segTree, arr, 2 * idx + 1, beg, mid), buildTree(segTree, arr, 2 * idx + 2, mid + 1, end));
		return segTree[idx];
	}
}

int query(vector<int> &segTree, 
	int beg, int end, int idx, int l, int r) {
	//cout << beg << " " << end << " " << idx << " " << l << " " << r << "\n";
	if(beg == end || beg >= l && end <= r) {
		return segTree[idx];
	}
	else if(l > end || r < beg) {
		return INT_MAX;
	}
	else {
		int mid = (beg + end) / 2;
		int leftVal = query(segTree, beg, mid, 2 * idx + 1, l, r);
		int rightVal = query(segTree, mid + 1, end, 2 * idx + 2, l, r);
		return min(leftVal, rightVal);
	}
}

void update(vector<int> &segTree, vector<int> &arr, int idx, int beg, int end, int pos, int val) {
	if(pos < beg || pos > end) {
		return;
	}
	else if(beg == end) {
		arr[pos] = val;
		segTree[idx] = val;
		return;
	}
	else {
		int mid = (beg + end) / 2;
		if(pos >= beg && pos <= mid) {
			update(segTree, arr, 2 * idx + 1, beg, mid, pos, val);
		}
		else {
			update(segTree, arr, 2 * idx + 2, mid + 1, end, pos, val);
		}
		segTree[idx] = min(segTree[2 * idx + 1], segTree[2 * idx + 2]);
		return;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;
	int sTreeSize = getSegTreeSize(n);
	vector<int> arr(n);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> segTree(sTreeSize, INT_MAX);
	buildTree(segTree, arr, 0, 0, n - 1);
	int q;
	cin >> q;
	while(q--) {
		int type;
		cin >> type;
		if(type == 1) {
			int l, r;
			cin >> l >> r;
			int result = query(segTree, 0, n - 1, 0, l, r);
			cout << result << "\n";
		}
		else {
			int pos, val;
			cin >> pos >> val;
			update(segTree, arr, 0, 0, n - 1, pos, val);
		}
	}
	return 0;
}