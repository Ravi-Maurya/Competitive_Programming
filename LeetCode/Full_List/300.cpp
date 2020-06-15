class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n = nums.size();
        int res = 1;
        vector<int> dp(n,1);
        for(int i = 1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j] && dp[i]<dp[j]+1){
                    dp[i] = dp[j] + 1;
                    res = max(res,dp[i]);
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        if(n==0)
            return 0;
        vector<int> aux(n,0);
        int lenght = 1;
        aux[0] = arr[0];
        for(int i=1; i<n; i++){
            auto it = lower_bound(aux.begin(), aux.begin()+lenght, arr[i]);
            if(it==aux.begin()+lenght)
                aux[lenght++] = arr[i];
            else
                *it = arr[i];
        }
        return lenght;
    }
};