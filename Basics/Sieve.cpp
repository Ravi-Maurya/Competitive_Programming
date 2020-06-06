#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
typedef long long ll;

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