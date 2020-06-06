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

const ll N = 1e5 + 7;

class SegmentedSieve{
    public:
    ll n;
    vector<bool> isprime;
    vector<ll> spf;
    vector<ll> primes;
    SegmentedSieve(){
        n = N;
        isprime.resize(n,true);
        spf.resize(n,0);
        primes.clear();
        build();
    }

    void build(){
        isprime[0] = isprime[1] = false;
        spf[1] = 1;
        for(ll i = 2; i<n; i++){
            if(isprime[i]){
                primes.push_back(i);
                spf[i] = i;
            }
            ll j = 0;
            while(j<primes.size() && i*primes[j]<=n && primes[j]<=spf[i]){
                isprime[i*primes[j]] = false;
                spf[i*primes[j]] = primes[j];
                j++;
            }
        }
        return;
    }

    ll get(ll k){
        auto idx = lower_bound(primes.begin(),primes.end(),k)-primes.begin();
        return primes[idx];
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    auto s = SegmentedSieve();
    ll r,c;
    cin>>r>>c;
    vector<vector<ll>> arr(r,vector<ll>(c));
    ll minval = inf;
    bool avail = false;
    for(ll i =0 ;i<r; i++){
        ll sum = 0;
        for(ll j = 0; j<c; j++){
            cin>>arr[i][j];
            if(!s.isprime[arr[i][j]]){
                // cout<<s.get(arr[i][j])<<"-f \n";
                sum += s.get(arr[i][j]) - arr[i][j];
            }
        }
        // cout<<sum<<"\n";
        if(sum == 0)
            avail = true;
        if(minval>sum && (sum != 0))
            minval = sum;
    }
    if(avail){
        cout<<0<<"\n";
        return 0;
    }
    for(ll j=0; j<c; j++){
        ll sum = 0;
        for(ll i =0; i<r; i++){
            sum += s.get(arr[i][j]) - arr[i][j];
        }
        // cout<<sum<<"\n";
        if(sum == 0)
            avail = true;
        if(minval>sum && (sum != 0))
            minval = sum;
    }
    if(avail)
        cout<<0<<"\n";
    else
        cout<<minval<<"\n";
    return 0;
}