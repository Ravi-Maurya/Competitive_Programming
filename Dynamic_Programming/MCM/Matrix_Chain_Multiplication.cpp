#include<bits/stdc++.h>
using namespace std;

int mcm(vector<int>& arr, int i, int j){//mcm(arr,1,n-1);
    if(i>=j)
        return 0;
    int res = INT_MAX;
    for(int k=i; k<j; k++){
        int tmp = mcm(arr,i,k) + mcm(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        res = min(res,tmp);
    }
    return res;
}

int solve(vector<int>& arr){//O(n3)
    int n = arr.size();
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int length= 2; length<n; length++){
        for(int i=1; i<n-length+1;i++){
            int j = i+length-1;
            dp[i][j] = INT_MAX;
            for(int k=i; k<j; k++){
                int tmp = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if(tmp<dp[i][j])
                    dp[i][j] = tmp;
            }
        }
    }
    return dp[1][n-1];
}

void printit(int i, int j, int n, int *bracket, char &name){
    if(i==j){
        cout<< name++;
        return;
    }
    cout<<"(";
    printit(i, *((bracket+j*n)+i), n, bracket, name);
    printit(*((bracket+j*n)+i)+1, j, n, bracket, name);
    cout<<")";
}

void printMCM(vector<int>& arr, int n){
    int dp[n][n], bracket[n][n];
    for(int i=1; i<n; i++)
        dp[i][i] = 1;
    for(int length= 2; length<n; length++){
        for(int i=1; i<n-length+1;i++){
            int j = i+length-1;
            dp[i][j] = INT_MAX;
            for(int k=i; k<j; k++){
                int tmp = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if(tmp<dp[i][j]){
                    dp[i][j] = tmp;
                    bracket[i][j] = k;
                }
            }
        }
    }
    char name = 'A';
    printit(1,n-1,n,bracket,name);
}

int main(){
    return 0;
}