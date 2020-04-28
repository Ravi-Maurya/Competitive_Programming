class Solution {
public:
    void recursive(int idx, vector<int> &A, vector<int> &tmp, vector<vector<int>> &res){
        res.push_back(tmp);
        for(int i=idx;i<A.size();i++){
            tmp.push_back(A[i]);
            recursive(i+1,A,tmp,res);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> t;
        vector<vector<int>> res;
        recursive(0,nums,t,res);
        return res;
    }
};