#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

#define ll long long int
#define pll pair<ll,ll> 
#define pls pair<ll,string>
#define psl pair<string,ll>
#define plc pair<ll,char>
#define pcl pair<char,ll>
#define pss pair<string,string>
#define maxheap(type) priority_queue<type>
#define minheap(type) priority_queue<type,vector<type>,greater<type>>
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define precise(x,y) fixed<<setprecision(y)<<x
#define tol(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define tou(s) transform(s.begin(),s.end(),s.begin(),::toupper);
#define rep(n) for(auto i=0; i<n; i++)

const int N = 1005;
int arr[N];
int t,n,k;
// int dp[N][N];
int dp[N];
int repeat[N][N];
// int recursion(int i, int j){
//     if(dp[i][j]!=-1)
//         return dp[i][j];
//     if(i==j){
//         return dp[i][j] = k;
//     }
//     int res = k + repeat[i][j];
//     for(int l=i; l<j; l++){
//         int tmp = 0;
//         if(dp[i][l]!=-1)
//             tmp += dp[i][l];
//         else
//             tmp += recursion(i,l);
        
//         if(dp[l+1][j]!=-1)
//             tmp += dp[l+1][j];
//         else
//             tmp += recursion(l+1,j);
        
//         if(tmp<res)
//             res = tmp;
//     }
//     return dp[i][j] = res;
// }

int recursion2(int i, int j){
    // Accepted
    if(dp[i]!=-1)
        return dp[i];
    if(i==j){
        return dp[i] = k;
    }
    int res = k + repeat[i][j];
    for(int l=i; l<j; l++){
        int tmp = k + repeat[i][l] + recursion2(l+1,j);
        if(tmp<res)
            res = tmp;
    }
    return dp[i] = res;
}

int solve(){
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
        vector<int> tmp(101,0);
        for(int j=i; j<n; j++){
            ++tmp[arr[j]];
            repeat[i][j] += (j==0)?0:repeat[i][j-1];
            if(tmp[arr[j]]==1){
                repeat[i][j] += 0;
            }
            else if(tmp[arr[j]]==2){
                repeat[i][j] += 2;
            }
            else{
                repeat[i][j] += 1;
            }
        }
    }
    // debug(repeat);
    return recursion2(0,n-1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        memset(repeat,0,sizeof(repeat));
        cout << solve() << "\n";
    }
    return 0;
}