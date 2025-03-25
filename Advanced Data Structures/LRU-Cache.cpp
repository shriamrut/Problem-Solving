#include <bits/stdc++.h>
using namespace std;
class LRUCache {
public:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> location;

    LRUCache(int capacity) {
    	this->capacity = capacity;    
    }
    
    int get(int key) {
    	auto entry = location.find(key);
    	if(entry == location.end()) {
    		return -1;
    	}    
    	list<pair<int,int>>::iterator it = location[key];
    	int value = it->second;
    	cache.erase(it);
    	cache.push_front({key, value});
    	location[key] = cache.begin();
    	return value;
    }
    
    void put(int key, int value) {
    	auto entry = location.find(key);
    	if(entry != location.end()) {
    		list<pair<int,int>>::iterator it = location[key];
    		cache.erase(it);
    	}
    	else if(cache.size() == capacity) {
    		pair<int, int> leastUsed = cache.back();	
    		auto it = location.find(leastUsed.first);
    		cache.erase(it->second);
    		location.erase(it->first);
    	}
    	cache.push_front({key, value});
    	location[key] = cache.begin();
    	return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	LRUCache lrucache(2);
	lrucache.put(1, 2);
	lrucache.put(2, 3);
	cout << "lrucache.get(1): " << lrucache.get(1) << "\n";
	lrucache.put(3, 3);
	cout << "lrucache.get(2): " << lrucache.get(2) << "\n";
	lrucache.put(4, 4);
	cout << "lrucache.get(1): " << lrucache.get(1) << "\n";
	cout << "lrucache.get(3): " << lrucache.get(3) << "\n";
	cout << "lrucache.get(4): " << lrucache.get(4) << "\n";
	return 0;
}