struct Cache{
    int key;
    int value;
    Cache(int k=0, int val = 0){
        key = k;
        value = val;
    }
};
class LRUCache {
    list<Cache> cache;// erase takes O(number of elements erased)
    unordered_map<int, list<Cache>::iterator> ump;
    int cap;
public:
    LRUCache(int capacity) {
        cap  = capacity;
    }
    
    int get(int key) {
        if(!ump.count(key))
            return -1;
        auto it = ump[key];
        cache.push_front(*it);
        cache.erase(it);
        ump[key] = cache.begin();
        return ump[key]->value;
    }
    
    void put(int key, int value) {
        if(!ump.count(key)){
            cache.push_front(Cache(key, value));
            ump[key] = cache.begin();
            if(cache.size()>cap){
                auto last = cache.back();
                ump.erase(last.key);
                cache.pop_back();
            }
        }
        else{
            auto it = ump[key];
            it->value = value;
            cache.push_front(*it);
            cache.erase(it);
            ump[key] = cache.begin();
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */