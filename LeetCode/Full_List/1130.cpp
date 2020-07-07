class Solution {
public:
    int dp[45][45][2];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    pair<int,int> mcm(vector<int>& arr, int i, int j){//0 to n-1
        if(dp[i][j][0]!=-1)
            return {dp[i][j][0],dp[i][j][1]};
        if(i==j){
            dp[i][j][0] = 0;
            dp[i][j][1] = arr[i];
            return {0,arr[i]};
        }
        int ans = INT_MAX;
        int val = INT_MAX;
        for(int k=i; k<j;k++){
            auto left = mcm(arr,i,k);
            auto right = mcm(arr,k+1,j);
            int sum = left.first + right.first + left.second*right.second;
            int big = max(left.second,right.second);
            if(ans>sum || (ans==sum && big<val)){
                ans = sum;
                val = big;
            }
        }
        dp[i][j][0] = ans;
        dp[i][j][1] = val;
        return {ans,val};
    }
    int mctFromLeafValues(vector<int>& arr) {
        auto res = mcm(arr,0,arr.size()-1);
        return res.first;
    }
};

class Solution {
public:
    int dp[45][45][2];
    Solution(){
        memset(dp,0,sizeof(dp));
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        for(int i=0; i<n; i++){
            dp[i][i][0] = 0;
            dp[i][i][1] = arr[i];
        }
        for(int length=2; length<=n; length++){
            for(int i=0; i<n-length+1; i++){
                int j = i+length-1;
                int ans = INT_MAX;
                int val = INT_MAX;
                for(int k=i; k<j; k++){
                    int sum = dp[i][k][0] + dp[k+1][j][0] + dp[i][k][1]*dp[k+1][j][1];
                    int big = max(dp[i][k][1],dp[k+1][j][1]);
                    if(ans>sum || (ans==sum && big<val)){
                        ans = sum;
                        val = big;
                    }
                }
                dp[i][j][0] = ans;
                dp[i][j][1] = val;
            }
        }
        return dp[0][n-1][0];
    }
};