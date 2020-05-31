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
    ll min_moves = (n+1)/2;
    ll min_times = min_moves/m;
    ll max_times = n/m;
    if((min_times == max_times) && (min_moves%m != 0) && (n%m != 0)){
        cout<<-1<<"\n";
        return 0;
    }
    // cout<<min_moves<<" "<<n<<"\n";
    // cout<<min_times<<" "<<max_times<<"\n";
    for(ll i=min_times; i<=max_times; i++){
        ll tmp = m*i;
        if(min_moves<= tmp && tmp<=n){
            cout<<tmp<<"\n";
            return 0;
        }
    }
    return 0;
}