class RandomizedSet {
public:
    
        
    /** Initialize your data structure here. */
    unordered_map<int,int> exists;
    vector<int> element;
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        
        if(exists.count(val)==0){
            element.push_back(val);
            exists[val]=element.size()-1;
            return true;
        }
        return false;
    
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(exists.count(val) >0){
            
            int valIndex = exists[val];
            int lastIndex = element.size()-1;
            int lastElement = element[lastIndex];
            
            swap(element[valIndex],element[lastIndex]);
            exists[lastElement]=valIndex;
            exists.erase(val);
            element.pop_back();
            
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        
        //srand(rand());
        return element[rand()%element.size()];
        
    }
};