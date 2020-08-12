class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> prev,res;
        if(n==0)
            return {1};
        if(n==1)
            return {1,1};
        prev.push_back(1);
        prev.push_back(1);
        for(int i=2; i<=n; i++){
            res.clear();
            res.push_back(1);
            for(int j=1; j<prev.size(); j++){
                res.push_back(prev[j]+prev[j-1]);
            }
            res.push_back(1);
            prev = res;
        }
        return res;
    }
};