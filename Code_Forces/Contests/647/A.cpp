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
    rep(t){
        ll a,b;
        cin>>a>>b;
        if(a==b)
            cout<<0<<"\n";
        else if((a%b == 0) || (b%a==0)){
            if(a<b)
                swap(a,b);
            ll d = a/b;
            if(d&(d-1)){
                cout<<-1<<"\n";
            }
            else{
                ll n = log2(d);
                ll count = 0;
                count += n/3;
                n %= 3;
                count += n/2;
                n %= 2;
                count += n;
                cout<<count<<"\n";
            }
        }
        else{
            cout<<-1<<"\n";
        }
    }
    return 0;
}