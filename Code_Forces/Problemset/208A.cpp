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
    bool intersect = false;
    int n;
    cin>>n;
    vector<int> arr(n);
    rep(n)
        cin>>arr[i];
    if(n<2){
        cout<<"no\n";
        return 0;
    }
    for(int i=0;i<n-1;i++){
        int x1 = min(arr[i],arr[i+1]);
        int x2 = max(arr[i],arr[i+1]);
        for(int j=i+1;j<n-1;j++){
            int x3 = min(arr[j],arr[j+1]);
            int x4 = max(arr[j],arr[j+1]);
            if((x1<x3 && x3<x2 && x2<x4) || (x3<x1 && x1<x4 && x4<x2)){
                cout<<"yes\n";
                return 0;
            }
        }
    }
    cout<<"no\n";
    return 0;
}