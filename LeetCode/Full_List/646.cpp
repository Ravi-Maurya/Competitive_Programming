class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(begin(pairs),end(pairs),compare);
        int curr = INT_MIN;
        int res = 0;
        for(auto& p: pairs)
            if(curr<p[0]){
                curr = p[1];
                res++;
            }
        return res;
    }
};

// or DP solution LIS with sorting;