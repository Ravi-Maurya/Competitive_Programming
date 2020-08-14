class CombinationIterator {
    vector<string> res;
    int count = 0;
public:
    CombinationIterator(string characters, int combinationLength) {
        for(int i=1; i< pow(2,characters.size()); i++){
            string curr= "";
            for(int j=0; j<characters.size(); j++){
                if(i & (1<<j))
                    curr += characters[j];
            }
            if(curr.size() == combinationLength)
                res.push_back(curr);
        }
        sort(res.begin(),res.end());
    }
    
    string next() {
        return res[count++];
    }
    
    bool hasNext() {
        return count != res.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */