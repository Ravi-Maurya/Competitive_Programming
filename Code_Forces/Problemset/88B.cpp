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
    ll t;
    cin>>t;
    while(t--){
        ll n,m,a,b;
        cin>>n>>m>>a>>b;
        bool single  = (2*a < b);
        ll res = 0;
        rep(n){
            vector<int> tmp;
            int count = 0;
            char first,second;
            for(ll j = 0; j<m; j++){
                cin>>second;
                if(second=='*'){
                    if(count!=0)
                        tmp.push_back(count);
                    count = 0;
                }
                else{
                    count++;
                }
            }
            if(count!=0)
                tmp.push_back(count);
            
            if(single){
                for(auto x: tmp)
                    res += (x*a);
            }
            else{
                for(auto x: tmp)
                    res += (x%2)*a + (x>>1)*b;
            }
        }
        cout<< res<<"\n";
    }
    return 0;
}