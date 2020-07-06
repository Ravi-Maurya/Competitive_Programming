#include<bits/stdc++.h>
using namespace std;

int main(){
    return 0;
}

bool isPal(string& arr, int i, int j){
    while(i<=j){
        if(arr[i]!=arr[j])
            return false;
        i++;j--;
    }
    return true;
}

int palpart(string& arr, int i, int j){//(0 to n-1)
    if(i>=j || isPal(arr, i, j))
        return 0;
    int ans = INT_MAX;
    for(int k=i; k<j; k++){
        int tmp = palpart(arr,i,k) + palpart(arr,k+1,j) + 1;
        ans = min(ans,tmp);
    }
    return ans;
}

int solve(string& arr, int n){//O(n3)
    int dp[n][n];
    bool ispal[n][n];
    for(int i=0; i<n; i++){
        ispal[i][i] = true;
        dp[i][i] = 0;
    }

    for(int length=2; lenght<=n; lenght++){
        for(int i=0; i<n-length+1; i++){
            int j=i+length-1;
            if(length==2)
                ispal[i][j] = arr[i] == arr[j];
            else
                ispal[i][j] = (arr[i] == arr[j]) && ispal[i+1][j-1];
            

            if(ispal[i][j])
                dp[i][j] = 0;
            else{
                dp[i][j] = INT_MAX;
                for(int k=i; k<j; k++)
                    dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + 1);
            }
        }
    }
    return dp[0][n-1];
}

int solve2(string& arr, int n){//O(n2)
    int dp[n];
    bool ispal[n][n];
    for(int i=0; i<n; i++)
        ispal[i][i] = true;
    
    for(int length=2; lenght<=n; lenght++){
        for(int i=0; i<n-length+1; i++){
            int j=i+length-1;
            if(length==2)
                ispal[i][j] = arr[i] == arr[j];
            else
                ispal[i][j] = (arr[i] == arr[j]) && ispal[i+1][j-1];
        }
    }
    for(int i=0; i<n; i++){
        if(ispal[0][i])
            dp[i]=0;
        else{
            dp[i] = INT_MAX;
            for(int j=0; j<i; j++){
                if(ispal[j+1][i] && dp[i]>dp[j]+1)
                    dp[i] = dp[j] + 1;
            }
        }
    }
    return dp[n-1];
}
