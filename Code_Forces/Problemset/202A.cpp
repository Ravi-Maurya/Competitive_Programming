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
    ll n;
    cin>>n;
    unordered_map<ll,ll> change;
    change[25] = 0;
    change[50] = 0;
    change[100] = 0;
    bool possible = true;
    for(ll i=0; i<n; i++){
        ll take,give;
        cin>>take;
        change[take]++;
        give = take - 25;
        if(possible){
            if(give == 25){
                if(change[25]!=0){
                    change[25]--;
                }
                else{
                    possible = false;
                }
            }
            else if(give == 75){
                if(change[50]!=0 && change[25]!=0){
                    change[50]--;
                    change[25]--;
                }
                else if(change[25]>=3){
                    change[25] -= 3;
                }
                else{
                    possible = false;
                }
            }
        }
    }
    cout<< ((possible)?"YES\n":"NO\n");
    return 0;
}