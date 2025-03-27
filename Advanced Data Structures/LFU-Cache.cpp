#include <bits/stdc++.h>
using namespace std;


class Node {
public:
	int key, value, freq;
	Node(int key, int value, int freq = 1) {
		this->key = key;
		this->value = value;
		this->freq = freq;
	}
};

class LFUCache {
public:
	int minFreq;
	int capacity;
	unordered_map<int, list<Node>> freqToNodes;
	unordered_map<int, list<Node>::iterator> keyToPtr;

    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }
    
    int get(int key) {
    	if(keyToPtr.count(key) == 0) {
    		return -1;
    	}
    	Node node = *keyToPtr[key];
    	remove(node);
    	node.freq++;
    	insert(node);
    	return node.value;
    }
    
    void put(int key, int value) {
    	if(keyToPtr.count(key) == 0) {
    		//Because we are adding a new entry
    		if(capacity == keyToPtr.size()) {
	        	//Cache overflow, remove least frequently used item
	        	Node lfuNode = freqToNodes[minFreq].back();
	        	// cout << "freqToNode[" << minFreq << "].back() - "; 
	        	// cout << "lfuNode - {" << lfuNode.key << ", " << lfuNode.value << ", " << lfuNode.freq << "}\n";
	        	remove(lfuNode);
        	}
        	Node node(key, value);
        	insert(node);
        	minFreq = 1;
    	}
    	else {
    		Node node = *keyToPtr[key];
    		remove(node);
    		node.freq++; // because we are adding a new entry
    		node.value = value;
    		insert(node);
    	}
  
    }

    void insert(Node node) {
    	freqToNodes[node.freq].push_front(node);
    	keyToPtr[node.key] = freqToNodes[node.freq].begin();
    }

    void remove(Node node) {
    	list<Node>::iterator ptr = keyToPtr[node.key];
    	freqToNodes[node.freq].erase(ptr);
    	if(freqToNodes[node.freq].empty()) {
    		freqToNodes.erase(node.freq);
			if(node.freq == minFreq) {
				minFreq++;
			}
    	}
    	keyToPtr.erase(node.key);
    }
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
	LFUCache lfu(2);
	lfu.put(1, 1);
	lfu.put(2, 2);
	cout << "lfu.get(1) " << lfu.get(1) << "\n";
	lfu.put(3, 3);
	cout << "lfu.get(2) " << lfu.get(2) << "\n";
	cout << "lfu.get(3) " << lfu.get(3) << "\n";
	lfu.put(4, 4);
	cout << "lfu.get(1) " << lfu.get(1) << "\n";
	cout << "lfu.get(3) " << lfu.get(3) << "\n";
	cout << "lfu.get(4) " << lfu.get(4) << "\n"; 
	return 0;
}