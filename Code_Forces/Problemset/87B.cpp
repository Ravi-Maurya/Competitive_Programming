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


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<string> field(n);
    vector<int> dirs = {-1,0,1,0,-1};
    queue<pll> q;
    rep(n){
        cin>>field[i];
        for(ll j=0; j<m; j++){
            if(field[i][j]=='W')
                q.push({i,j});
        }
    }
    ll res = 0;
    while(!q.empty()){
        auto curr = q.front();q.pop();
        for(int k=0; k<4; k++){
            ll nr = curr.first + dirs[k];
            ll nc = curr.second + dirs[k+1];
            if(0<=nr && nr<n && 0<=nc && nc<m && field[nr][nc]=='P'){
                res++;
                field[nr][nc] = '.';
                break;
            }
        }
    }
    cout<<res<<"\n";
    return 0;
}