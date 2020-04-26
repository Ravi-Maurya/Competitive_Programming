struct Cache {
    int _key;
    int _value;
    Cache(int key = 0, int value = 0) {
        _key = key;
        _value = value;
    }
};

class LRUCache{
    list<Cache> cache;
    unordered_map<int, list<Cache>::iterator> posMap;
    int _capacity;
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if (posMap.find(key) == posMap.end()) return -1;
        //find the position of key
        auto it = posMap[key];
        //move the founded cache value to the front
        cache.push_front(*it);
        //delete the duplicate copy at the original position
        cache.erase(it);
        //update the posMap of key to new position: begin()
        posMap[key] = cache.begin();
        return posMap[key]->_value;
    }
    
    void put(int key, int value) {
        //if cannot find the new key in the cache, need to insert it
        //only in this case delete is needed, when cache size is larger than capacity
        //else just update the value and update the cache key position to the front
        if (posMap.find(key) == posMap.end()) {
            //insert the new cache value to the front
            cache.push_front(Cache(key, value));
            posMap[key] = cache.begin();
            //if size larger than capacity, delete the last value
            if (cache.size() > _capacity) {
                //delete the last elements' iterator in map, and delete the last element
                Cache lastNode = cache.back();
                posMap.erase(lastNode._key);
                cache.pop_back();
            }
        } else {
            //find the position of the key, update value and update pos to begin()
            auto it = posMap[key];
            it->_value = value;
            cache.push_front(*it);
            cache.erase(it);
            posMap[key] = cache.begin();
        }
    }
};