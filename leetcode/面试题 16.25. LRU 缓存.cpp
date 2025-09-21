#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity): cap(capacity) {

    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            return mp[key];

            while (!pq.empty()) {
                
            }
        }

        return -1;
    }
    
    void put(int key, int value) {
        
    }

private:
    priority_queue<pair<int, int>> pq;
    unordered_map<int, int> mp;
    int cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */