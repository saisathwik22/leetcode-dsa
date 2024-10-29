// Leetcode 146 - LRU cache
// Approach - Brute Force
// TLE
class LRUCache {
public:
    vector<pair<int, int>> cache;
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        for(int i = 0; i < cache.size(); i++) {
            if(cache[i].first == key) {
                int val = cache[i].second;
                pair<int, int> temp = cache[i];
                cache.erase(cache.begin() + i);
                cache.push_back(temp);
                return val;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        for(int i = 0; i < cache.size(); i++) {
            if(cache[i].first == key) {
                cache.erase(cache.begin() + i);
                cache.push_back({key, value});
                return;
            }
        }
        if(cache.size() == n) {
            cache.erase(cache.begin());
            cache.push_back({key, value});
        } else {
            cache.push_back({key, value});
        }
    }
};

// Approach 2 - optimal
// Doubly Linked List
class LRUCache {
public:
    list<int> dll;
    map<int, pair<list<int>::iterator, int>> cache;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    void makeMostRecentlyUsed(int key) {
        dll.erase(cache[key].first);
        dll.push_front(key);
        cache[key].first = dll.begin();
    }
    int get(int key) {
        if(!cache.count(key)) {
            return -1;
        }
        makeMostRecentlyUsed(key);
        return cache[key].second;
    }
    
    void put(int key, int value) {
        if(cache.count(key)) {
            cache[key].second = value;
            makeMostRecentlyUsed(key);
        } else{
            dll.push_front(key);
            cache[key] = {dll.begin(), value};
            capacity--;
        }
        if(capacity < 0) {
            cache.erase(dll.back());
            dll.pop_back();
            capacity++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
