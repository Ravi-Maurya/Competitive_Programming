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

bool position(string& p){
    for(int i=1; i<p.size(); i++){
        if(p[i]!=p[i-1]){
            if(p[i]<p[i-1])
                return true;
            return false;
        }        
    }
    return false;
}

void solve(){
    string p,s;
    cin>>s>>p;
    vector<int> hashed(26,0);
    for(auto ch: s)
        hashed[ch-'a']++;
    for(auto ch: p)
        hashed[ch-'a']--;
    bool flag = false;
    bool first = position(p);
    string res = "";
    for(int i=0; i<26; i++){
        if(!flag && first && i==(p[0]-'a')){
            res += p;
            flag = true;
        }
        while(hashed[i]>0){
            res += (char)(i+'a');
            hashed[i]--;
        }
        if(!flag && !first && i==(p[0]-'a')){
            res += p;
            flag = true;
        }
    }
    cout<<res;
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
    return 0;
}