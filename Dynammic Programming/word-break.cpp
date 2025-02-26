
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

	bool wordBreakTable(string s, vector<string> &wordDict) {
		unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
		vector<bool> dp(s.length() + 1, false);
		// dp[i] = dp[i - word.length()];
		dp[0] = true;
		for(int i = 1; i <= s.length(); i++) {
			string t = "";
			for(int j = i - 1; j >= 0; j--) {
				t = s[j] + t;
				if(wordSet.find(t) != wordSet.end()) {
					dp[i] = dp[i] || dp[i - t.length()];
				}
			}
		}
		return dp[s.length()];
	}

	bool wordBreakMemo(string s, vector<string> &wordDict) {
		unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        	int i = 0;
        	vector<int> memo(s.length() + 1, -1);
        	return wordBreakMemo(s, memo, wordSet, i);
	}

	bool wordBreakMemo(string &s, vector<int> &memo, unordered_set<string> &wordSet,
		int i) {
		if(i == s.length()) {
			return true;
		}
		else if(memo[i] != -1) {
 			return memo[i];
		}
		else {
    		bool isFound = false;
    		string substr = "";
    		for(int j = i; j < s.length(); j++) {
    			substr += s[j];
    			if(wordSet.find(substr) != wordSet.end()) {
    				isFound |= wordBreakMemo(s, memo, wordSet, j + 1);
    			}
    		}
    		memo[i] = isFound;
    		return memo[i];
		}
	}

    bool wordBreakRecurse(string &s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int i = 0;
        string word = "";
        return wordBreakRecurse(s, wordSet, i, word);
    }

    bool wordBreakRecurse(string &s, unordered_set<string> &wordSet, int i, string word) {
    	if(i == s.length() 
    		&& wordSet.find(word) != wordSet.end()) {
    		return true;
    	}
    	else if(i == s.length()) {
    		return false;
    	}
    	else {
    		word += s[i];
    		bool moveAhead = wordBreakRecurse(s, wordSet, i + 1, word);
    		//lets break the word
    		bool afterBreak = false;
    		if(wordSet.find(word) != wordSet.end()) {
    			afterBreak = wordBreakRecurse(s, wordSet, i + 1, "");
    		}
    		return moveAhead || afterBreak;
    	}
    }
};

bool assertEquals(bool expected, bool actual) {
	if(expected == actual) {
		 cout << "(" << expected << " == " << actual << ")" << " - PASS \n";
		 return true;
	}
	else {
		cout << "(" << expected << " != " << actual << ")" << " - FAIL \n";
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
		string s;
		cin >> s;
		int nItems;
		cin >> nItems;
		vector<string> wordDict(nItems);
		for(int i = 0; i < nItems; i++) {
			cin >> wordDict[i];
		}
		// cout << "Main str: " << s << "\n";
		// cout << "Dictionary items: \n";
		// for(string &word: wordDict) {
		// 	cout << word << " ";
		// } 
		// cout << "\n";
		Solution sol;
		assertEquals(sol.wordBreakMemo(s, wordDict), sol.wordBreakTable(s, wordDict));
	}
}
