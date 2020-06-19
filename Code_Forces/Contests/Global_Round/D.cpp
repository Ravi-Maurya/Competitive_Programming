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
    ll n;
    cin>> n;
    minheap(ll) pq1;
    maxheap(ll) pq2;
    rep(n){
        ll t;
        cin>>t;
        if(t&1)
            pq2.push(t);
        else
            pq1.push(t);
    }
    ll res = 0;
    while(!pq1.empty() && !pq2.empty()){
        ll mx = pq1.top();pq1.pop();
        ll mn = pq2.top();pq2.pop();
        ll Or = mn|mx;
        ll And = mn&mx;
        res += Or*Or + And*And;
    }
    while(pq1.size()>1){
        ll mx = pq1.top();
        pq1.pop();
        ll mn = pq1.top();
        pq1.pop();
        ll Or = mx|mn;
        ll And = mx&mn;
        res += Or*Or;
        pq1.push(And);
    }   
    while(!pq1.empty()){
        res += pq1.top()*pq1.top();
        pq1.pop();
    }
    while(pq2.size()>1){
        ll mx = pq2.top();
        pq2.pop();
        ll mn = pq2.top();
        pq2.pop();
        ll Or = mx|mn;
        ll And = mx&mn;
        res += Or*Or;
        pq2.push(And);
    }   
    while(!pq2.empty()){
        res += pq2.top()*pq2.top();
        pq2.pop();
    }
    cout<< res<<"\n";
    return 0;
}