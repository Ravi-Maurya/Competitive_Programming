#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int h,w;
    cin>>h>>w;
    vector<vector<char>>x;
    int i,j;
    char ans;
    for(i=0;i<h;i++){
        vector<char>y;
        for(j=0;j<w;j++){     
            cin>>ans;
            y.push_back(ans);
        }
        x.push_back(y);
    }
    int dp[h][w]={0};
    for(i=0;i<h;i++)
        for(j=0;j<w;j++)
            dp[i][j]=0;
    dp[0][0]=1;
    for(i=1;i<w;i++){
        if(x[0][i]=='.')
            dp[0][i]=1;
        else
            break;
    }
    for(i=1;i<h;i++){
        if(x[i][0]=='.')
            dp[i][0]=1;
        else
            break;  
    }
    for(i=1;i<h;i++){
        for(j=1;j<w;j++){
            if(x[i][j]=='.')
                dp[i][j]+=(dp[i-1][j]+dp[i][j-1])%1000000007;
            else
                continue;
        }
    }
    cout<<dp[h-1][w-1]<<"\n";
    return 0;
}