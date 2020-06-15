class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i<nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int j = i+1, k = nums.size()-1;
            while(j<k){
                int s = nums[i] + nums[j] + nums[k];
                if(s<0)
                    j++;
                else if(s>0)
                    k--;
                else{
                    res.push_back(vector<int> {nums[i],nums[j],nums[k]});
                    do{
                        j++;
                    }while(j<k && nums[j-1]==nums[j]);
                    do{
                        k--;
                    }while(j<k && nums[k]==nums[k+1]);
                }
            }
        }
        return res;
    }
};