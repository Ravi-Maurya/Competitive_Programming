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
    int n;
    cin>>n;
    vector<int> arr(n);
    ll post = 0, neg = 0, zer = 0;
    unordered_map<int,vector<int>> ump;
    vector<int> negatives;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==0){
            zer++;
            ump[0].push_back(arr[i]);
        }
        else if(arr[i]>0){
            post++;
            ump[1].push_back(arr[i]);
        }
        else{
            neg++;
            negatives.push_back(arr[i]);
        }
    }
    if(post == 0){
        ump[1].push_back(negatives[neg-1]);
        neg--;
        negatives.pop_back();
        ump[1].push_back(negatives[neg-1]);
        neg--;
        negatives.pop_back();
    }
    if(neg%2==0){
        ump[0].push_back(negatives[neg-1]);
        neg--;
        negatives.pop_back();
    }
    cout<<neg<<" ";
    for(auto num: negatives)
        cout<<num<<" ";
    cout<<"\n";
    cout<<(ump[1].size())<<" ";
    for(auto num: ump[1])
        cout<<num<<" ";
    cout<<"\n";
    cout<<(ump[0].size())<<" ";
    for(auto num: ump[0])
        cout<<num<<" ";
    cout<<"\n";
    return 0;
}