class Solution{
    public:
    int threeSumSmaller(vector<int>& nums, int target){
        if(nums.size()<3)
            return 0;
        int res = 0;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size()-2; i++){
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                int curr = nums[i] + nums[j] + nums[k];
                if(curr<target){
                    res += (k-j);
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return res;
    }
};