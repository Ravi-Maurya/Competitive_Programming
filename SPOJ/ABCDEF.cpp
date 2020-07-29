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

int n;
int arr[105];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    rep(n)
        cin>>arr[i];
    map<int,int> mp1,mp2;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                int s1 = arr[i]*arr[j] + arr[k];
                int s2 = arr[i]*(arr[j] + arr[k]);
                mp1[s1]++;
                if(arr[i]!=0)
                    mp2[s2]++;
            }
        }
    }
    int count = 0;
    for(auto it: mp1){
        auto it2 = mp2.lower_bound(it.first);
        if(it2 != mp2.end() && it2->first == it.first){
            count += (it.second * it2->second);
        }
    }
    cout<<count<<"\n";
    return 0;
}