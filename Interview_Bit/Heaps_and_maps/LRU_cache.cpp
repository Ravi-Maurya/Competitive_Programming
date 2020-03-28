map<int,int> cache;
deque<int> lru;
int cap;
set<int> s;

LRUCache::LRUCache(int capacity) {
    cap = capacity;
    cache.clear();
    lru.clear();
    s.clear();
}

int LRUCache::get(int key) {
    if(cache.find(key)==cache.end())
        return -1;
    int id;
    for(int i=0;i<lru.size();i++)
        if(lru[i]==key){
            id = i;
            break;
        }
    lru.erase(lru.begin()+id);
    lru.push_back(key);
    return cache[key];
}

void LRUCache::set(int key, int value) {
    if(cache.size()<cap || cache.count(key)>0){
        cache[key] = value;
        if(s.find(key)==s.end()){
            s.insert(key);
            lru.push_back(key);
        }
        else{
            int id;
            for(int i=0;i<lru.size();i++)
            if(lru[i]==key){
                id = i;
                break;
            }
            lru.erase(lru.begin()+id);
            lru.push_back(key);
        }
    }
    else{
        int val = lru.front();
        lru.pop_front();
        cache.erase(val);
        s.erase(val);
        cache[key] = value;
        s.insert(key);
        lru.push_back(key);
    }
}
