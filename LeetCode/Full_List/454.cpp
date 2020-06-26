class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<long long int,int> ump;
        for(auto x: A)
            for(auto y: B)
                ump[x+y]++;
        long long int res = 0;
        for(auto x: C)
            for(auto y: D)
                if(ump.count(0-x-y))
                    res += ump[0-x-y];
        return res;
    }
};