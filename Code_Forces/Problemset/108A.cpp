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
    ll n,m;
    cin>>n>>m;
    unordered_map<ll,pair<ll,vector<ll>>> ump;
    for(int i=0;i<n;i++){
        string tmp;
        cin>>tmp;
        for(int j=0; j<m; j++){
            ll t = (tmp[j]-'0');
            if(ump.count(j)){
                if(ump[j].first == t){
                    ump[j].second.push_back(i);
                }
                else if(ump[j].first < t){
                    ump[j].first = t;
                    ump[j].second.clear();
                    ump[j].second.push_back(i);
                }
            }
            else{
                ump[j].second.push_back(i);
                ump[j].first = t;
            }
        }
    }
    unordered_set<ll> visited;
    for(int i=0;i<m;i++){
        for(auto& num: ump[i].second)
            visited.insert(num);
    }
    cout<<(visited.size())<<"\n";
    return 0;
}