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

ll stringHash(const string& s){
    const int p = 31; // Asuming all lowercase/Uppercase but not both , for both p = 53;
    const int m = 1e9 + 9;
    ll res = 0;
    ll power = 1;
    for(char ch: s){
        res = (res + (c - 'a' +1)*power)%m;
        power = (power*p)%m;//optimization can be done by precomputing power of p
    }
    return res;
    // to find hash between [i,j] its good to comute hashes of all prefixes as hash([i,j]) = (hash([0,j]) - hash([0,i-1]) mod m)*modInverse(p,i,m);
}

int count_unique_substrings(const string& s){
    int n = s.size();
    const int p = 31;
    const int m = 1e9 + 9;
    vector<ll> power(n);
    power[0] = 1;
    for(int i=1; i<n; i++)
        power[i] = (power[i-1]*p)%m;
    vector<ll> hashes(n+1,0);
    for(int i=0; i<n; i++)
        hashes[i+1] = (hashes[i] + (s[i]-'a'+1)*power[i])%m;
    int res = 0;
    for(int l = 1; l<=n; l++){
        unordered_set<ll> hs;
        for(int i=0;i<n-l+1;i++){
            ll curr = (hashes[i+l] + m - hashes[i])%m;
            curr = (curr*power[n-1-i])%m;
            hs.insert(curr);
        }
        res += hs.size();
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    return 0;
}