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

int dp[100][2];

void add(int& a, int b){
    a += b;
    if(a>=mod)
        a-=mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n,k,d;
    cin>>n>>k>>d;
    dp[0][0] = 1;
    dp[0][1] = 0 ;
    for(int i=1;i<=n;i++){
        dp[i][0] = dp[i][1] = 0;
        for(int j=1; j<=k; j++){
            if(i-j<0)
                break;
            if(j<d){
                add(dp[i][0],dp[i-j][0]);
                add(dp[i][1],dp[i-j][1]);
            }
            else{
                add(dp[i][1],dp[i-j][0]);
                add(dp[i][1],dp[i-j][1]);
            }
        }
    }
    cout<< dp[n][1] <<"\n";
    return 0;
}