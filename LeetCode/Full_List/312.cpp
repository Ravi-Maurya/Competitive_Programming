class Solution {
public:
    int dp[505][505];
    int solve(vector<int>& nums, int i, int j){
        //base condition
        if(j-i==1)
            return 0;
        if(dp[i][j]>0)
            return dp[i][j];
        int res = 0;
        for(int k=i+1; k<j; k++){
            int curr = nums[i]*nums[k]*nums[j];
            int tmp1 = solve(nums,i,k);
            int tmp2 = solve(nums,k,j);
            res = max(res, curr + tmp1 + tmp2);
        }
        return dp[i][j] = res;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp,0,sizeof(dp));
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        return solve(nums,0,n-1);
    }
};

class Solution {
public:
    long long int dp[505][505];
    int maxCoins(vector<int>& nums) {
        memset(dp,0,sizeof(dp));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        for(int i=n-2; i>=0 ;i--){
            for(int j=i+2; j<n; j++){
                for(int k=i+1; k<j; k++){
                    dp[i][j] = max(dp[i][j], nums[i]*nums[k]*nums[j] + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};

class Solution {
public:
    int arr[505];
    int dp[505][505];
    Solution(){
        memset(dp,0,sizeof(dp));
        memset(arr,0,sizeof(arr));
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        arr[0] = 1;
        for(int i=0; i<n; i++)
            arr[i+1] = nums[i];
        arr[n+1] = 1;
        n = n+2;
        int res = 0;
        for(int length = 2; length<=n; length++){
            for(int i=1; i<n-length+1; i++){
                int j = i+length-1;
                for(int k=i; k<j; k++){
                    res = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                    if(dp[i][j]<res)
                        dp[i][j] = res;
                }
            }
        }
        return dp[1][n-1];
    }
};