class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        if(n==0)
            return res;
        res.push_back({1});
        if(n==1)
            return res;
        res.push_back({1,1});
        if(n==2)
            return res;
        for(int i=3; i<=n; i++){
            vector<int> tmp(i,1);
            for(int j=1; j<i-1; j++){
                tmp[j] = res[i-2][j] + res[i-2][j-1];
            }
            res.push_back(tmp);
        }
        return res;
    }
};