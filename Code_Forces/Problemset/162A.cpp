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

bool compare(pair<pll,ll>& a, pair<pll,ll>& b){
    auto x = a.first;
    auto y = b.first;
    int gcd = __gcd(x.second,y.second);
    int lcm = (x.second*y.second)/gcd;
    int i = x.first*(lcm/x.second);
    int j = y.first*(lcm/y.second);
    return i<=j;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    cin>>s;
    int n = s.size();
    vector<int> left,right;
    rep(n){
        auto ch = s[i];
        if(ch=='l')
            left.push_back(i+1);
        else
            right.push_back(i+1);
    }
    for(auto num:right)
        cout<<num<<"\n";
    n = left.size();
    rep(n){
        cout<<left[n-1-i]<<"\n";
    }
    return 0;
}