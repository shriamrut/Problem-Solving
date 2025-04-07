/*
Tries Data Structure
Used for checking if a certain prefix exist in a set of strings or to print the set of strings with a certain prefix.
Time Complexity:
search: O(|t|) where t is length of the prefix
*/

#include <bits/stdc++.h>
#define ALPHA_SIZE 26
#define ONLINE_JUDGE

using namespace std;

class Node {
public:
	Node *next[ALPHA_SIZE];
	bool isEnd;
	Node() {
		for(int i = 0; i < 26; i++) {
			this->next[i] = NULL;
		}
		isEnd = false;
	}
};

class Trie{
public:
	Node *root;
	Trie() {
		root = new Node();
	}

	void insert(string s) {
		Node *curr = root;
		for(int i = 0; i < s.length(); i++) {
			if(curr->next[s[i] - 'a'] == NULL) {
				curr->next[s[i] - 'a'] = new Node();
			}
			curr = curr->next[s[i] - 'a'];
		}
		curr->isEnd = true;
	}

	bool searchPrefix(string prefix) {
		Node *curr = root;
		for(int i = 0; i < prefix.length(); i++) {
			if(curr->next[prefix[i] - 'a'] == NULL) {
				return false;
			}
			curr = curr->next[prefix[i] - 'a'];
		}
		return true;
	}

	bool search(string str) {
		Node *curr = root;
		for(int i = 0; i < str.length(); i++) {
			if(curr->next[str[i] - 'a'] == NULL) {
				return false;
			}
			curr = curr->next[str[i] - 'a'];
		}
		return curr->isEnd;
	}

	void printAll() {
		string temp = "";
		Node *curr = root;
		printAll(curr, temp);
	}	
	void printAll(Node *curr, string temp) {
		if(curr->isEnd) {
			cout << temp << "\n";
			return;
		}

		for(int i = 0; i < ALPHA_SIZE; i++) {
			if(curr->next[i] != NULL) {
				char ch = (i + 'a');
				printAll(curr->next[i], temp + ch);
			}
		}
	}
};

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	Trie trie;
	trie.insert("apple");
	trie.insert("banana");
	trie.insert("orange");
	cout << "trie.searchPrefix(app)?: " << trie.searchPrefix("app") << "\n";
	cout << "trie.searchPrefix(cat)?: " << trie.searchPrefix("cat") << "\n";
	cout << "trie.search(app)? " << trie.search("app") << "\n";
	cout << "trie.search(apple)? " << trie.search("apple") << "\n";
	trie.printAll();
	return 0;
}
