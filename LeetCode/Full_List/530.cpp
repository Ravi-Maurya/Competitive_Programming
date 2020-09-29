class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        if(s.size()<3)
            return {};
        vector<vector<int>> res;
        int i = 0, j = 0;
        int n = s.size();
        while(j<n){
            while(j<n && s[j]==s[i])
                j++;
            int count = j-i;
            if(count>=3)
                res.push_back({i,j-1});
            i = j;
        }
        return res;
    }
};