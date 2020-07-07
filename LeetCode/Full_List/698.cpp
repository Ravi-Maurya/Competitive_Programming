class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int sum = 0;
        for(auto x: nums)
            sum += x;
        int target = sum/k;
        if(sum%k>0 || nums[n-1]>target)
            return false;
        int N = 1<<n;
        bool dp[N];
        memset(dp,false,sizeof(dp));
        dp[0] = true;
        int res[N];
        memset(res,0,sizeof(res));
        for(int state = 0; state<N; state++){
            if(!dp[state])
                continue;
            for(int i=0; i<n; i++){
                int tmp = (state | (1<<i));
                if(state!=tmp && (dp[tmp]==false)){
                    if(nums[i]<=target-(res[state]%target)){
                        dp[tmp] = true;
                        res[tmp] = res[state] + nums[i];
                    }
                    else
                        break;
                }
            }
        }
        return dp[N-1];
    }
};