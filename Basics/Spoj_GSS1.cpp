#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
typedef long long int ll;

ll arr[50005];
struct Tree{
    ll prefix,suffix,total,best;
};
Tree tree[200005];
void build(ll idx, ll st, ll en){
    if(st>en)
        return;
    if(st==en){
        tree[idx].prefix = arr[st];
        tree[idx].suffix = arr[st];
        tree[idx].total = arr[st];
        tree[idx].best = arr[st];
        return;
    }
    ll mid = st + (en-st)/2;
    build(2*idx,st,mid);
    build(2*idx+1,mid+1,en);
    tree[idx].prefix = max(tree[2*idx].prefix, tree[2*idx].total + tree[2*idx+1].prefix);
    tree[idx].suffix = max(tree[2*idx+1].suffix, tree[2*idx+1].total + tree[2*idx].suffix);
    tree[idx].total = tree[2*idx].total + tree[2*idx + 1].total;
    tree[idx].best = max({tree[2*idx].suffix + tree[2*idx+1].prefix, tree[2*idx].best,tree[2*idx+1].best});
    return;
}
Tree query(ll idx, ll st, ll en, ll i, ll j){
    Tree t;
    if(st>en || st>j || en<i || i>j){
        t.prefix = t.suffix = t.best = INT_MIN;
        t.total = 0;
        return t;
    }
    if(st>=i && en<=j)
        return tree[idx];
    ll mid = st + (en-st)/2;
    auto q1 = query(2*idx,st,mid,i,j);
    auto q2 = query(2*idx+1,mid+1,en,i,j);
    t.prefix = max(q1.prefix, q1.total + q2.prefix);
    t.suffix = max(q2.suffix, q1.suffix + q2.total);
    t.total = q1.total + q2.total;
    t.best = max({q1.suffix + q2.prefix, q1.best, q2.best});
    return t;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll n,m;
    cin>>n;
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }
    build(1,0,n-1);
    cin>>m;
    for(ll q=0;q<m;q++){
        ll i,j;
        cin>>i>>j;
        auto res = query(1,0,n-1,i-1,j-1);
        cout<<res.best<<"\n";
    }
    return 0;
}