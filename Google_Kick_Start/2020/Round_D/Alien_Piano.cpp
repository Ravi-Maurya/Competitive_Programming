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
const int N = 1e4 + 10;
int dp[N][5];

int recursive(vector<int>& arr, int idx, int val){//arr,0,(0,1,2,3)
    if(idx==arr.size()-1){//last Node
        if(val<1 || val>4)// if node is getting out of bound
            return 1;
        return 0;
    }
    if(dp[idx][val]!=-1)
        return dp[idx][val];
    if(val<1 || val>4){// if node is getting out of bound and not last
        int res = INT_MAX;
        for(int i=1; i<=4; i++)//we can recur from starting i.e. 1,2,3,4 for A,B,C,D
            res = min(res,recursive(arr,idx,i));
        return dp[idx][val] = 1 + res;//1 for penalty
    }
    int res = INT_MAX;
    if(arr[idx+1]==arr[idx])//if same the put same
        res = recursive(arr,idx+1,val);
    else if(arr[idx+1]>arr[idx]){// next value can be anything more than now 
        for(int i=val+1; i<=5; i++){
            res = min(res,recursive(arr,idx+1,i));
        }
    }
    else{// next value can be anything less than now 
        for(int i=0; i<val; i++)
        res = min(res, recursive(arr,idx+1,i));
    }
    return dp[idx][val] = res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test<=t; test++){
        cout<<"Case #"<<test<<": ";
        memset(dp,-1,sizeof(dp));
        int n;
        cin>>n;
        vector<int> arr(n);
        rep(n)
            cin>>arr[i];
        if(n<=4){
            cout<< 0 <<"\n";
            continue;
        }
        int res = INT_MAX;
        for(int i=1; i<=4; i++){
            res = min(res,recursive(arr,0,i));
        }
        cout<< res <<"\n";
    }
    return 0;
}