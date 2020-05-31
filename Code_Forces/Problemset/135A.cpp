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
    ll k;
    cin>>k;
    string s;
    cin>>s;
    if((s.size())%k != 0){
        cout<<-1<<"\n";
        return 0;
    }
    vector<int> arr(26,0);
    for(auto ch: s){
        arr[ch-'a']++;
    }
    string res = "";
    for(int i=0;i<26;i++){
        if(arr[i]>0 && arr[i]%k != 0){
            cout<<-1<<"\n";
            return 0;
        }
        else if(arr[i]%k == 0){
            int times = arr[i]/k;
            while(times--){
                res += (i+'a');
            }
        }
    }
    for(int i=0;i<k;i++)
        cout<<res;
    cout<<"\n";
    return 0;
}