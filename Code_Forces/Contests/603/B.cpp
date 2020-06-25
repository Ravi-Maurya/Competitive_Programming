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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        unordered_map<string,int> ump;
        rep(n){
            cin>>arr[i];
            ump[arr[i]] = i;
        }
        if(ump.size()==n){
            cout<< 0 <<"\n";
            for(auto x: arr)
                cout<< x<<"\n";
        }
        else{
            int change = n - ump.size();
            cout<< change<< "\n";
            int ch = 0;
            for(int i=0; i<n; i++){
                if(ump[arr[i]]==i){
                    cout<<arr[i]<<"\n";
                    continue;
                }
                else{
                    for(int j=0; j<10; j++){
                        arr[i][3] = (char)(j+'0');
                        if(!ump.count(arr[i])){
                            ump[arr[i]] = i;
                            break;
                        }
                    }
                    cout<<arr[i]<<"\n";
                }
            }
        }
    }
    return 0;
}