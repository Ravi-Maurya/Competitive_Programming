class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        if(n==3)
            return max({nums[0],nums[1],nums[2]});
        int first1 = nums[0], second1 = max(nums[0],nums[1]);//[0 to n-2]
        int first2 = nums[1], second2 = max(nums[1],nums[2]);//[1 to n-1]
        int third1, third2;
        for(int i=4; i<=n; i++){
            third1 = max(first1+nums[i-2],second1);
            first1 = second1;
            second1 = third1;
            
            third2 = max(first2+nums[i-1],second2);
            first2 = second2;
            second2 = third2;
        }
        return max(third1,third2);
    }
};