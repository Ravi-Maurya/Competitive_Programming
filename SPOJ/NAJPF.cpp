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

const int p = 31;
const int mm = 1e9+9;
const int N = 1e6+1;
vector<ll> power(N);

void precompute(){
    power[0] = 1;
    for(int i=1; i<N; i++)
        power[i] = (power[i-1]*p)%mm;
    return;
}

vector<int> rabin_karp(const string& pattern, const string& text){
    int m = pattern.size(), n = text.size();
    if(m>n)
        return {};
    vector<ll> hashes(n+1,0);
    for(int i=0; i<n; i++)
        hashes[i+1] = (hashes[i] + (text[i]-'a'+1)*power[i])%mm;
    ll pat_hash = 0,text_hash;
    for(int i=0;i<m;i++)
        pat_hash = (pat_hash + (pattern[i]-'a' + 1)*power[i])%mm;
    // cout<< pat_hash << " -d\n";
    vector<int> indices;
    for(int i=0; i<n-m+1;i++){
        text_hash = (hashes[i+m] + mm - hashes[i])%mm;
        // cout << text_hash << " " << pat_hash*power[i]%mm << " " << pat_hash << "\n";
        if(text_hash == pat_hash * power[i]%mm){
            indices.push_back(i);
        }
    }
    return indices;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    precompute();
    while(t--){
        string text, pattern;
        cin>>text>>pattern;
        auto res = rabin_karp(pattern,text);
        int k = res.size();
        if(k == 0){
            cout << "Not Found\n\n";
            continue;
        }
        cout<< k <<"\n";
        for(auto idx: res)
            cout<< idx+1 << " ";
        cout<<"\n\n";
    }
    return 0;
}