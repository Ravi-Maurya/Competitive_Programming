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
    int test;
    cin>>test;
    for(int t=0; t<test; t++){
        unordered_map<int,int> ump;
        int n;
        cin>>n;
        bool can_sell = true;
        rep(n){
            int a;
            cin>>a;
            ump[a]++;
            int diff = a-5;
            if(diff!=0 && can_sell){
                if(diff==10){
                    if(ump.count(10) && ump[10]>=1){
                        ump[10]--;
                    }
                    else if(ump.count(5) && ump[5]>=2){
                        ump[5] -=2;
                    }
                    else{
                        can_sell = false;
                    }
                }
                else if(diff == 5 && ump.count(5) && ump[5]>=1){
                    ump[5]--;
                }
                else
                    can_sell = false;
            }
        }
        cout << ((can_sell) ? "YES\n":"NO\n");
    }
    return 0;
}