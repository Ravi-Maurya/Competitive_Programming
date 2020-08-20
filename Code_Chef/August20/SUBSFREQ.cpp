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

struct comp{
    bool operator()(const pair<int,int>& a,const pair<int,int>& b){
        if(a.second==b.second)
            return a.first>b.first;
        return a.second<b.second;
    }
};

int get_element(vector<int> hashed){
    int n = hashed.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>, comp> pq;
    for(int i=0; i<n; i++){
        if(hashed[i]>0)
            pq.push({i,hashed[i]});
    }
    if(pq.empty())
        return 0;
    return pq.top().first;
}

void recursive(vector<int>& A, int idx, vector<int> hashed,vector<int>& ans){
    if(idx>=A.size()){
        int curr = get_element(hashed);
        ans[curr] = (ans[curr]+1)%mod;
        return;
    }
    vector<int> new_hash = hashed;
    new_hash[A[idx]]++;
    recursive(A,idx+1,hashed,ans);
    recursive(A,idx+1,new_hash,ans);
    return;
}

void solve(){
    int n;
    cin>>n;
    vector<int> ans(n+1,0);
    vector<int> A(n);
    rep(n)
        cin>>A[i];
    vector<int> hashed(n+1,0);
    recursive(A,0,hashed,ans);
    for(int i=1; i<=n; i++)
        cout<<ans[i] << " ";
    cout<<"\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}