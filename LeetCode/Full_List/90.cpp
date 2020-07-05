class Solution {
public:

    void recursive(vector<int>& nums, int startIdx, vector<int>& curr, vector<vector<int>>& res)
    {
        for(int i = startIdx; i < nums.size(); ++i)
        {
            curr.push_back(nums[i]);
            res.push_back(curr);
            recursive(nums, i + 1, curr, res);
            curr.pop_back();
            while(i < nums.size() - 1 && nums[i] == nums[i + 1])
                i++;
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        
        res.push_back({});
        vector<int> curr;
        sort(nums.begin(), nums.end());
        recursive(nums, 0, curr, res);
        return res;
    }
};