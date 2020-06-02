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
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<ll>> matrix(n,vector<ll>(m));
    for(ll i=0; i<n; i++){
        for(ll j = 0; j<m ;j++){
            cin>>matrix[i][j];
        }
    }
    vector<ll> row(n),col(m);
    rep(n)
        row[i] = i;
    rep(m)
        col[i] = i;
    while(k--){
        char q;
        ll r,c;
        cin>>q>>r>>c;
        if(q=='g'){
            cout<<matrix[row[r-1]][col[c-1]]<<"\n";
        }
        else if(q=='r'){
            swap(row[r-1],row[c-1]);
        }
        else
            swap(col[r-1],col[c-1]);
    }
    return 0;
}