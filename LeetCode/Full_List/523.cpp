class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int,int> ump;
        ump[0]=-1;
        for(int i=0; i<nums.size();i++){
            sum += nums[i];
            if(k!=0)
                sum = sum%k;
            if(ump.count(sum)){
                if(i-ump[sum]>1)
                    return true;
            }
            else
                ump[sum] = i;
        }
        return false;
    }
};

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; i++)
            dp[i] = dp[i-1] + nums[i-1];
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                int sum = dp[j]-dp[i-1];
                if(sum==k || (k!=0 && sum%k==0))
                    return true;
            }
        }
        return false;
    }
};