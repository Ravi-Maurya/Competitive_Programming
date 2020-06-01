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

ll n,a,b,c,DP[4001];
 
ll solve(int n){
	if(n == 0)
        return 0;
	if(n < 0)
        return  INT_MIN;
	if(DP[n] != -1)
        return DP[n];
    DP[n] = max(1+solve(n-a),max(1+solve(n-b),1+solve(n-c)));
	return DP[n];
}
 
int main(){
    cin >> n >> a >> b >> c;
    memset(DP,-1,sizeof(DP));
    cout << solve(n) << endl;
    return 0;
}