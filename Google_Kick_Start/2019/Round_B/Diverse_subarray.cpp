#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
#define sz(x) (int)x.size()

int n,s,a[100005];
vector<int> f[100005];
const int N=100005;
int seg[4*N],lazy[4*N];

void update(int node,int start,int end,int l,int r,int val){
    if(lazy[node]!=0){
        seg[node]+=lazy[node];
        if(start!=end){
            lazy[node<<1]+=lazy[node];
            lazy[node<<1|1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(start>end || start>r || end<l) return;
    if(l<=start && end<=r){
        seg[node]+=val;
        if(start!=end){
            lazy[node<<1]+=val;
            lazy[node<<1|1]+=val;
        }
        return;
    }
    int mid=(start+end)>>1;
    update(node<<1,start,mid,l,r,val);
    update(node<<1|1,mid+1,end,l,r,val);
    seg[node]=max(seg[node<<1],seg[node<<1|1]);
}

int query(int node,int start,int end,int l,int r){
    if(start>end || start>r || end<l) return 0;
    if(lazy[node]!=0){
        seg[node]+=lazy[node];
        if(start!=end){
            lazy[node<<1]+=lazy[node];
            lazy[node<<1|1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(start>=l && end<=r) return seg[node];
    int mid=(start+end)>>1;
    int q1=query(node<<1,start,mid,l,r);
    int q2=query(node<<1|1,mid+1,end,l,r);
    return max(q1,q2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        memset(seg,0,sizeof seg);
        memset(lazy,0,sizeof lazy);
        int ans=0;
        cin>>n>>s;
        for(int i = 1; i<n+1; i++){
            cin>>a[i];
            if(sz(f[a[i]])==0) f[a[i]].push_back(n+1);
        }
    for(int i=n;i>=1;i--){
        f[a[i]].push_back(i);
        if(sz(f[a[i]])>=s+2)
            update(1,1,n,f[a[i]][sz(f[a[i]])-s-1],f[a[i]][sz(f[a[i]])-s-2]-1,-s);
        update(1,1,n,f[a[i]].back(),f[a[i]][max(0LL,(long long)(sz(f[a[i]])-s-1))]-1,1);
        ans=max(ans,query(1,1,n,1,n));
    }
    for(int i=1;i<n+1; i++) f[a[i]].clear();
    cout<<"Case #"<<test<<": "<<ans<<"\n";
    }
    return 0;
}