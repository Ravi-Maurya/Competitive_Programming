class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        vector<long long> sua(nums.size()+1);
        sua[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            sua[i]=nums[i]+sua[i+1];
        }
        vector<vector<long long > > dp(n+1,vector<long long >(m+1,-1));
        for(int i=1;i<=m;i++){
            dp[n-1][i]=nums[n-1];
        }
        for(int i=1;i<=m;i++){
            dp[n][i]=INT_MAX;
        }
        for(int i=0;i<n;i++){
            dp[i][1]=sua[i];
        }
        for(int i=n-2;i>=0;i--){
            for(int k=2;k<=m;k++){
                long long ma=INT_MAX,su=0;
                for(int j=i;j<n;j++){
                    su+=nums[j];
                    ma=min(ma,max(su,dp[j+1][k-1]));
                }
                dp[i][k]=ma;
            }
        }
        return dp[0][m];
    }
};

// My Approach use memoization
// class Solution {
// public:
//     int recursive(vector<int>& nums, int m, int n){
//         if(n<0)
//             return INT_MAX;
//         if(m==1){
//             int sum = 0;
//             for(int i=n;i>=0;i--)
//                 sum += nums[i];
//             return sum;
//         }
//         int sum = 0;
//         int res = INT_MAX;
//         for(int i = n; i>=0; i--){
//             sum += nums[i];
//             res = min(res,max(sum,recursive(nums,m-1,i-1)));
//         }
//         return res;
//     }
//     int splitArray(vector<int>& nums, int m) {
//         return recursive(nums,m,nums.size()-1);
//     }
// };