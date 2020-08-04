class MyHashSet {
public:
    int hashed[1000002];
    /** Initialize your data structure here. */
    MyHashSet() {
        memset(hashed,-1,sizeof(hashed));
    }
    
    void add(int key) {
        hashed[key] = key;
    }
    
    void remove(int key) {
        hashed[key] = -1;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return (hashed[key] != -1);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */