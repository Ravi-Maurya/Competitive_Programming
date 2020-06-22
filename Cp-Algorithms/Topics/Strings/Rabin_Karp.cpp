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

vector<int> rabin_karp(const string& pattern, const string& text){//O(n)
    const int p = 31;
    const int mm = 1e9+9;
    int m = pattern.size(), n = text.size();
    if(m>n)//if pattern is greater in size than text
        return {};
    vector<ll> power(n);
    power[0] = 1;
    for(int i=1; i<n; i++)//precompute the powers till p**(n-1)
        power[i] = (power[i-1]*p)%mm;
    vector<ll> hashes(n+1,0);
    for(int i=0; i<n; i++)// compute prefixes for text to compute hash([i,j]) of length m
        hashes[i+1] = (hashes[i] + (text[i]-'a'+1)*power[i])%mm;
    ll pat_hash = 0;
    for(int i=0;i<m;i++)
        pat_hash = (pat_hash + (pattern[i]-'a'+1)*power[i])%mm;
    vector<int> indices;
    for(int i=0; i<n-m+1;i++){
        ll text_hash = (hashes[i+m] + mm - hashes[i])%mm;
        // text_hash = text_hash*modInverse(power[i],m); so rather than doing this we multiply
        // pat_hash with this ie (pat_hash*power[i])%mm and compare it
        // note its better to check the actual pattern and text after hashes are equal;
        if(text_hash == (pat_hash*power[i])%mm)
            indices.push_back(i);
    }
    return indices;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    return 0;
}