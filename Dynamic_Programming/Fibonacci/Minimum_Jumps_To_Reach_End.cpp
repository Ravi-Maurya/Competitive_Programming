#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, int n){
    int dp[n];
    int mn;
    dp[n-1] = 0;
    for(int i=n-2; i>=; i--){
        if(nums[i]==0)
            dp[i] = INT_MAX;
        else if(nums[i]>= n-i-1)
            dp[i] = 1;
        else{
            mn = INT_MAX;
            for(int j=i+1; j<n && j<=nums[i]+i; j++){
                if(mn>dp[j])
                    mn = dp[j];
            }
            if(mn != INT_MAX)
                dp[i] = mn + 1;
            else
                dp[i] = mn;
        }
    }
    return dp[0];
}


int greedy(vector<int>& nums, int n){
    if(n==1)
        return 0;
    int next_jump = nums[0];
    int max_jump = nums[0];
    int jumps = 1;
    for(int i=1; i<n; i++){
        if(i>next_jump)
            return -1;
        next_jump = max(next_jump,i+nums[i]);
        if(i==max_jump && i!=n-1){
            max_jump = next_jump;
            jumps++;
        }
    }
    return jumps;

}

int main(){
    return 0;
}