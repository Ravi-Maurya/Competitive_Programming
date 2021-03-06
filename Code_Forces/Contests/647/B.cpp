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
    ll t;
    cin>>t;
    for(ll test = 0; test<t; test++){
        ll n;
        cin>>n;
        unordered_set<int> ust;
        int maxi = INT_MIN;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
            ust.insert(arr[i]);
        }
        bool ok = false;
        for(int k=1; k<=1024; k++){
            unordered_set<int> tmp;
            tmp = ust;
            for(int i=0; i<n; i++){
                int x = k^arr[i];
                if(tmp.count(x))
                    tmp.erase(x);
                else
                    break;
            }
            if(!tmp.size()){
                ok = true;
                cout<<k<<"\n";
                break;
            }
        }
        if(!ok)
            cout<<-1<<"\n";
    }
    return 0;
}