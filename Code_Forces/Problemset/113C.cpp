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

void insertpq(maxheap(ll)& max, minheap(ll)& min, ll& tmp){
    if(max.size()==0){
        max.push(tmp);
    }
    else{
        if(max.size()==min.size()){
            if(tmp<min.top())
            max.push(tmp);
            else{
                max.push(min.top());
                min.pop();
                min.push(tmp);
            }
        }
        else if(max.size()>min.size()){
            if(max.top()<tmp)
                min.push(tmp);
            else{
                min.push(max.top());
                max.pop();
                max.push(tmp);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll n,val;
    cin>>n>>val;
    maxheap(ll) max;
    minheap(ll) min;
    rep(n){
        ll tmp;
        cin>>tmp;
        insertpq(max,min,tmp);
    }
    ll res = 0;
    while(max.top()!=val){
        res++;
        insertpq(max,min,val);
    }
    cout<<res<<"\n";
    return 0;
}