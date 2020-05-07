class LFUCache {
public:
    typedef unordered_map<int, list<int>> FreqList;
    typedef unordered_map<int, tuple<int,int,list<int>::iterator>> Cache;
    FreqList freq;
    Cache cache;
    int minFreq, maxSize;
    LFUCache(int capacity) {
        maxSize = capacity;
    }
    
    void update(int key){
        auto& f = ::get<1>(cache[key]);
        auto& i = ::get<2>(cache[key]);
        freq[f].erase(i);
        if(freq[f].empty() && minFreq == f)
            minFreq++;
        f += 1;
        i = freq[f].insert(freq[f].begin(), key);
    }
    
    int get(int key) {
        if(!cache.count(key))
            return -1;
        update(key);
        return ::get<0>(cache[key]);
    }
    
    void put(int key, int value) {
        if(maxSize<=0)
            return;
        if(cache.count(key)){
            update(key);
            ::get<0>(cache[key]) = value;
            return;
        }
        if(cache.size()==maxSize){
            cache.erase(freq[minFreq].back());
            freq[minFreq].pop_back();
        }
        minFreq = 1;
        freq[minFreq].push_front(key);
        cache[key] = make_tuple(value, minFreq, freq[minFreq].begin());
        return;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */