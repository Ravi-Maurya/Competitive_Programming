class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> ust;
        for(auto& c:J)
            ust.insert(c);
        int res = 0;
        for(auto& c: S){
            if(ust.count(c))
                res++;
        }
        return res;
    }
};