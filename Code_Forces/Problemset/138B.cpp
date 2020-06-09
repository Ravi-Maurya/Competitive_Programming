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
const int N = 1e5+5;

vector<int> arr(N,0), cnt(N,0);
int k,n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    int diff = 0;
    rep(n){
        cin>>arr[i];
        cnt[arr[i]]++;
        if(cnt[arr[i]] == 1)
            diff++;
    }
    int l = 0, r = n-1;
    while(l<r){
        if(cnt[arr[l]]>1 || diff>k){
            cnt[arr[l]]--;
            if(cnt[arr[l]] == 0)
                diff--;
            l++;
        }
        else if(cnt[arr[r]]>1 || diff>k){
            cnt[arr[r]]--;
            if(cnt[arr[r]] == 0)
                diff--;
            r--;
        }
        else
            break;
    }
    if(diff<k)
        cout<< "-1 -1\n";
    else
        cout<< (l+1) << " "<< (r+1) << "\n";
    return 0;
}