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

// class Sieve{
//     public:
//     ll n;
//     vector<bool> isprime;
//     vector<ll> spf;
//     vector<ll> primes;
//     Sieve(ll x){
//         n = x;
//         isprime.resize(n+1,true);
//         spf.resize(n+1,0);
//         primes.clear();
//     }

//     void generate(){
//         isprime[0] = isprime[1] = false;
//         spf[1] = 1;
//         for(ll i = 2; i<n+1; i++){
//             if(isprime[i]){
//                 primes.push_back(i);
//                 spf[i] = i;
//             }
//             ll j = 0;
//             while(j<primes.size() && i*primes[j]<=n && primes[j]<=spf[i]){
//                 isprime[i*primes[j]] = false;
//                 spf[i*primes[j]] = primes[j];
//                 j++;
//             }
//         }
//     }
// };

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    // auto s = Sieve(1e7);
    // s.generate();
    ll n;
    cin>>n;
    // for(ll i=0; i<n; i++)
    //     cout<<s.primes[i]<<" ";
    for(ll i=n; i<2*n; i++)
        cout<<i<<" ";
    cout<<"\n";
    return 0;
}