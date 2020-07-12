// #include <bits/stdc++.h>
// using namespace std;
// #pragma GCC optimize ("-O3")

// #define ll long long int
// #define pll pair<ll,ll> 
// #define pls pair<ll,string>
// #define psl pair<string,ll>
// #define plc pair<ll,char>
// #define pcl pair<char,ll>
// #define pss pair<string,string>
// #define maxheap(type) priority_queue<type>
// #define minheap(type) priority_queue<type,vector<type>,greater<type>>
// #define setbits(x) __builtin_popcountll(x)
// #define zerobits(x) __builtin_ctzll(x)
// #define mod 1000000007
// #define inf 1e18
// #define precise(x,y) fixed<<setprecision(y)<<x
// #define tol(s) transform(s.begin(),s.end(),s.begin(),::tolower);
// #define tou(s) transform(s.begin(),s.end(),s.begin(),::toupper);
// #define rep(n) for(auto i=0; i<n; i++)

// int bf(vector<int>& arr, int start, int k){
//     int n = arr.size();
//     queue<pair<int,pair<int,int>>> q;
//     q.push({start, {start-1,start}});
//     int count = 0;
//     while(!q.empty()){
//         auto curr = q.front();q.pop();
//         count++;
//         if(count==k){
//             return curr.first;
//         }
//         if(curr.second.first==0 && curr.second.second == (n-1))
//             break;
//         else if(curr.second.first == 0 || arr[curr.second.first]>arr[curr.second.second]){
//             q.push({curr.second.second+1,{curr.second.first, curr.second.second+1}});
//         }
//         else if(curr.second.second==(n-1) || arr[curr.second.first]<arr[curr.second.second]){
//             q.push({curr.second.first,{curr.second.first-1, curr.second.second}});
//         }
//     }
//     return -1;
// }

// void printall(vector<vector<int>> res){
//     for(auto& x: res){
//         for(auto& y: x)
//             cout<< y<< " ";
//         cout<<endl;
//     }
// }

// void solve(){
//     int n,q;
//     cin>>n>>q;
//     vector<int> arr(n+1);
//     arr[0] = INT_MAX;
//     arr[n] = INT_MAX;
//     for(int i=1; i<n; i++)
//         cin>>arr[i];
//     while(q--){
//         int i, j;
//         cin>>i>>j;
//         cout<<bf(arr,i,j);
//         cout<<" ";
//     }
//     return;
// }

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(NULL); cout.tie(NULL);
//     int test;
//     cin>>test;
//     for(int t=1; t<=test;t++){
//         cout<<"Case #"<<t<<": ";
//         solve();
//         cout<<"\n";
//     }
//     return 0;
// }

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

vector<int> bf(vector<int>& arr, int start){//brute Force TLE in Test2
    int n = arr.size();    
    queue<pair<int,pair<int,int>>> q;
    q.push({start, {start-1,start}});
    vector<int> res;
    while(!q.empty()){
        auto curr = q.front();q.pop();
        res.push_back(curr.first);
        if(curr.second.first==0 && curr.second.second == (n-1))
            break;
        else if(curr.second.first == 0 || arr[curr.second.first]>arr[curr.second.second]){
            q.push({curr.second.second+1,{curr.second.first, curr.second.second+1}});
        }
        else if(curr.second.second==(n-1) || arr[curr.second.first]<arr[curr.second.second]){
            q.push({curr.second.first,{curr.second.first-1, curr.second.second}});
        }
    }
    res.pop_back();
    return res;
}

void printall(vector<vector<int>> res){
    for(auto& x: res){
        for(auto& y: x)
            cout<< y<< " ";
        cout<<endl;
    }
}

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> arr(n+1);
    arr[0] = INT_MAX;
    arr[n] = INT_MAX;
    for(int i=1; i<n; i++)
        cin>>arr[i];
    vector<vector<int>> res;
    for(int i=1; i<=n; i++)
        res.push_back(bf(arr,i));
    printall(res);
    while(q--){
        int i, j;
        cin>>i>>j;
        cout<<res[i-1][j-1];
        cout<<" ";
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int test;
    cin>>test;
    for(int t=1; t<=test;t++){
        cout<<"Case #"<<t<<": ";
        solve();
        cout<<"\n";
    }
    return 0;
}