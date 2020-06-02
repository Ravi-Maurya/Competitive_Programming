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
    ll x;
    cin>>x;
    // 4a + 7b = x; x/7>=b>=0;
    ll i4 = 0, i7 = 0;
    for(ll a = 0; a<=x/4; a++){
        double b = ((x - 4*a)*1.0)/7;
        if(b>=0 && (b-ceil(b))==0){
            i4 = a;
            i7 = b;
            break;
        }
    }
    if(i4==0 && i7==0){
        cout<<-1<<"\n";
        return 0;
    }
    while(i4--){
        cout<<4;
    }
    while(i7--){
        cout<<7;
    }
    cout<<"\n";
    return 0;
}