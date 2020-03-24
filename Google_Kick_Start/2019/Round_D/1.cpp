#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
using ll = long long;
using ld = long double;
const ll mod = 1000000007;
const ll inf = 1000000000000000000;
const ll rk = 256;

#define eb emplace_back
#define pb push_back
#define mp make_pair
#define vc vector
#define fs first
#define sec second
#define pq priority_queue
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll> 
#define pls pair<ll,string>
#define psl pair<string,ll>
#define plc pair<ll,char>
#define pcl pair<char,ll>
#define pss pair<string,string>
int bit_count(int n){
    int cnt =0;
    while (n!=0){
        cnt += n&1 ;
        n >>= 1;
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin>>T;
    for(int test=1;test<=T;++test){
        int n,q,num;
        cin>>n,q;
        set<int> s;
        for(int i=0;i<n;i++){
            cin>>num;
            if(__builtin_popcount(num)&1)
                s.insert(num);
        }
        int size;
        cout<<"Case #"<<t<<": ";
        while (q--){
            int ind,nw;
            cin>>ind>>nw;
            s.erase(ind);
            if(__builtin_popcount(nw)&1)
                s.insert(ind);
            size = s.size();
            if (size&1 == 0){
                cout<<n<<" ";
                continue;
            }
            int l = *s.begin();
            int r = *s.end();
            cout << max(n-l-1,r)<<" ";
        }
        cout<<"\n";
    }
    return 0;
}