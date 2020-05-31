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
    string s;
    cin>>s;
    string whitespace = "WUB";
    ll n = s.size();
    ll i =0;
    string tmp = "";
    string res = "";
    while(i<n){
        if(s[i]=='W' && (i+2)<n && (s.substr(i,3) == whitespace)){
            i = i+3;
            if(tmp.size()!=0){
                res += tmp + " ";
            }
            tmp = "";
        }
        else
            tmp += s[i++];
    }
    if(tmp.size()!=0)
        res += tmp;
    cout<<res<<"\n";
    return 0;
}