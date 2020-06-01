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

struct Node{
    ll count;
    char left;
    char right;
    void init(ll c, char l, char r){
        count = c;
        left = l;
        right = r;
    }
    void merge(Node a, Node b){
        count = a.count + b.count + (a.right == b.left);
        left = a.left;
        right = b.right;
    }
};

class SegmentTrees{
    public:
    ll n;
    string s;
    vector<Node> tree;
    SegmentTrees(string st){
        tree.clear();
        s = st;
        n = st.size();
        tree.resize(4*n);
        build(0,n-1,1);
    }
    void build(ll st, ll en, ll idx){
        if(st==en){
            tree[idx].init(0,s[st],s[st]);
            return;
        }
        ll mid = mid = st + (en-st)/2;
        build(st,mid,2*idx);
        build(mid+1,en,2*idx+1);
        tree[idx].merge(tree[2*idx],tree[2*idx + 1]);
    }
    Node query(ll st, ll en, ll idx, ll l, ll r){
        Node res;
        if(st>en || st>r || en<l || l>r){
            res.init(0,'-','+');
            return res;
        }
        if(st>=l && en<=r)
            return tree[idx];
        ll mid = st + (en-st)/2;
        auto left = query(st,mid,2*idx,l,r);
        auto right = query(mid+1,en,2*idx+1,l,r);
        res.merge(left,right);
        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    cin>>s;
    ll n = s.size();
    auto st = SegmentTrees(s);
    ll q;
    cin>>q;
    rep(q){
        ll l,r;
        cin>>l>>r;
        ll res = (st.query(0,n-1,1,l-1,r-1).count);
        cout<<res<<"\n";
    }
    return 0;
}