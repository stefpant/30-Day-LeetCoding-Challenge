class LRUCache {
    unordered_map<int, int> cache;
    vector<int> lru;
    int cap;
public:
    LRUCache(int capacity) {
        lru = {};
        this->cap = capacity;
        cache = {};
    }
    
    int get(int key) {
        if(cache[key] == 0) return -1;
        lru.erase(find(lru.begin(), lru.end(), key));
        lru.push_back(key);
        return cache[key];
    }
    
    void put(int key, int value) {
        if(cache[key] != 0){
            cache[key] = value;
            lru.erase(find(lru.begin(), lru.end(), key));
            lru.push_back(key);
            return;
        }
        cache[key] = value;
        if(lru.size() == cap){
            cache[lru[0]] = 0;
            lru.erase(lru.begin());
        }
        lru.push_back(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
