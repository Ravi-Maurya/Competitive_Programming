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

class SegmentTree{
public:
    vector<int> arr;
    vector<int> tree;
    int n;
    SegmentTree(vector<int>& input){
        arr.clear();
        tree.clear();
        arr = input;
        n = input.size();
        tree.resize(4*n);
        buildTree(0,n-1,1);
    }
    
    bool buildTree(int st, int en, int idx){
        if(st==en){
            tree[idx] = arr[st];
            return true;
        }
        int mid = st + (en-st)/2;
        auto a = buildTree(st,mid,2*idx);
        auto b = buildTree(mid+1,en,2*idx+1);
        if(a && b){
            tree[idx] = (tree[2*idx] | tree[2*idx+1]);
            return false;
        }
        else{
            tree[idx] = (tree[2*idx] ^ tree[2*idx+1]);
            return true;
        }
    }

    bool update(int st, int en, int i, int val, int idx){
        if(st>en || st>i || en<i)
            return true;
        if(st==en){
            tree[idx] = val;
            return true;
        }
        int mid = st + (en-st)/2;
        auto a = update(st,mid,i,val,2*idx);
        auto b = update(mid+1,en,i,val,2*idx+1);
        if(a && b){
            tree[idx] = (tree[2*idx] | tree[2*idx+1]);
            return false;
        }
        else{
            tree[idx] = (tree[2*idx] ^ tree[2*idx+1]);
            return true;
        }
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    n = pow(2,n);
    vector<int> arr(n);
    rep(n)
        cin>>arr[i];
    auto st = SegmentTree(arr);
    while(m--){
        ll i,val;
        cin>>i>>val;
        st.update(0,n-1,i-1,val,1);
        cout<<st.tree[1]<<"\n";
    }
    return 0;
}