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
    string s1,s2;
    cin>>s1>>s2;
    if(s1.size()!=s2.size()){
        cout<<"NO\n";
        return 0;
    }
    ll one1 = 0, one2 = 0, zero1 = 0, zero2 = 0;
    for(auto& ch: s1){
        if(ch=='1')
            one1++;
        else
            zero1++;
    }
    for(auto& ch: s2){
        if(ch=='1')
            one2++;
        else
            zero2++;
    }
    if((one1>0 && one2>0)||(zero1==s1.size() && zero2==s1.size())){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}