class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> m;
        for(auto t:trips){
            m[t[1]] += t[0];
            m[t[2]] -= t[0];
        }
        int cnt = capacity;
        for(auto item:m){
            cnt -= item.second;
            if(cnt < 0) return false;
        }
        return true;
    }
};