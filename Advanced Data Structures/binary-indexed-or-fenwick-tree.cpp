#include <bits/stdc++.h>
using namespace std;
class BIT{
	public:
	int n;
	vector<int> arr;
	vector<int> bit;

	BIT(vector<int> arr) {
		this->n = arr.size();
		this->arr = arr;
		bit.assign(n + 1, 0);
		buildTree();
	}

	void update(int index, int val) {
		//to use one based indexing
		index++;
		for(; index <= n; index += (index & -index)) {
			bit[index] += val;
		}
	}

	int query(int index) {
		index++;
		int result = 0;
		for(; index > 0; index -= (index & -index)) {
			// cout << "Adding " << bit[index] << "\n";
			result += bit[index];
		}
		return result;
	}

	private:
	void buildTree() {
		for(int i = 0; i < n; i++) {
			// cout << "updating " << i << " to " << arr[i] << "\n";
			update(i, arr[i]);
		}
	}

};


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
		vector<int> arr(n);
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		BIT bit(arr);
		int qIndex;
		cin >> qIndex;
		cout << bit.query(qIndex) << "\n";
	}
}