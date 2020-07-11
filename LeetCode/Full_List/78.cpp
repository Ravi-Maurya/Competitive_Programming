class Solution {
public:
    vector<vector<int>> res;
    void recursive(vector<int>& nums, int n, vector<int>& tmp){
        if(n==nums.size()){
            res.push_back(tmp);
            return;
        }
        recursive(nums,n+1,tmp);
        tmp.push_back(nums[n]);
        recursive(nums,n+1,tmp);
        tmp.pop_back();
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        recursive(nums,0,tmp);
        return res;
    }
};