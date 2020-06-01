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
    string s1,s2;
    cin>>s1>>s2;
    ll actual = 0;
    unordered_map<ll,ll> ump;
    for(auto ch: s1)
        actual += ((ch=='+')?1:-1);
    ump[actual] = 0;
    ll curr = 0;
    ll prob = 0;
    for(auto ch: s2){
        if(ch=='?')
            prob++;
        else
            curr += ((ch=='+')?1:-1);
    }
    if(prob==0){
        double res = ((curr==actual)? (1.0) : (0.0));
        cout<<precise(res,9)<<"\n";
        return 0;
    }
    vector<vector<ll>> ncr(prob+1,vector<ll>(prob+1,0));
    ncr[0][0] = 1;
    for(ll i=1; i<=prob; i++){
        ncr[i][0] = 1;
        for(ll j=1; j<i+1; j++){
            ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
            ncr[i][i-j] = ncr[i][j];
        }
    }
    ll den = pow(2,prob);
    ll nem = 0;
    ll tmp = prob;
    ll i = 0;
    while(tmp>=0){
        ump[curr + tmp] += ncr[prob][i++];
        // cout<<tmp<<" "<<ump[curr]<<"\n";
        if(tmp!=0)
            ump[curr - tmp] += ump[curr + tmp];
        tmp -= 2;
    }
    nem = ump[actual];
    double res = (nem*1.0)/den;
    cout<<precise(res,9)<<"\n";
    return 0;
}