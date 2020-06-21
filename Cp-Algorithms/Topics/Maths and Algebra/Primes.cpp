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

vector<bool> SieveLtoR(int l, int r){// O((R−L+1)log(R)+ sqrt(R))
    vector<bool> is_prime(r-l+1,true);
    for(int i=2; i*i<=r; i++)
        for(int j = max(i*i,(l+i-1)/(i*i)); j<=r; j+=i)
            is_prime[j-l] = false;
    if(l==1)
        is_prime[0] = false;
    return is_prime;
}

vector<bool> Sieve(int n){//O(nlog(log(n))) for 1 to n check prime;
    vector<bool> is_prime(n+1,true);
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i*i<=n; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

class SegmentedSieve{//O(n) amortized also gives smallest prime factor for given number in 1 to n
    public:
    ll n;
    vector<ll> spf;
    vector<ll> primes;
    SegmentedSieve(ll N){
        n = N+1;
        spf.resize(n,0);
        primes.clear();
        build();
    }

    void build(){
        spf[1] = 1;
        for(ll i = 2; i<n; i++){
            if(spf[i]==0){
                primes.push_back(i);
                spf[i] = i;
            }
            for(ll j = 0; (j<primes.size() && i*primes[j]<=n && primes[j]<=spf[i]); j++)
                spf[i*primes[j]] = primes[j];
        }
        return;
    }
    
    bool isprime(ll k){
        if(k<2)
            return false;
        return spf[k]==k;
    }
    
    ll get(ll k){//prime number <= given k in log(primes.size())
        auto idx = lower_bound(primes.begin(),primes.end(),k)-primes.begin();
        return primes[idx];
    }
};

bool check_prime(int n){//O(sqrt(n))
    if(n<2)
        return false;
    if(n<4)
        return true
    if(n%2==0 || n%3==0)
        return false;
    for(int i=5; i*i<=n; i+=6)
        if(n%i==0 || n%(i+2)==0)
            return false;
    return true;
}

vector<int> prime_factorization(int n){
    vector<int> res;
    while(n&1 == 0){
        res.push_back(2);
        n >>= 1;
    }
    for(int i=3; i*i<=n; i+=2){
        while(n%i == 0){
            res.push_back(i);
            n /= i;
        }
    }
    if(n>2)
        res.push_back(n);
    return res;
}

vector<int> prime_factorization_Sieve(int n){//O(logn)
    auto st = SegmentedSieve(n);
    vector<int> res;
    while(n!=1){
        res.push_back(st.spf[n]);
        n = n/st.spf[n];
    }
    return res;
}

int phi(int n){// O(sqrt(n)) gives number of coprimes with n less than n
    int res = n;
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            while(n%i==0)
                n /= i;
            res -= res/i;
        }
    }
    if(n>1)
        res -= res/n;
    return res;
}

void Sieve_phi(int n){//O(nlog(logn))
    vector<int> phi_arr(n+1);
    for(int i=0; i<=n; i++)
        phi_arr[i] = i;
    for(int i=2; i<=n; ++)
        if(phi_arr[i]==i)
            for(int j=i; j<=n; j+=i)
                phi_arr[j] -= phi_arr[j]/i;
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    auto st = SegmentedSieve(10);
    for(int i = 1; i<=10; i++)
        cout<< st.isprime(i) << " " << st.spf[i] <<"\n";
    return 0;
}