#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
typedef long long int ll;

struct Tree{
    ll sum, suma,size;
    void init(ll val){
        sum = suma = val;
        size = 1;
    }
    void merge(Tree L, Tree R){
        size = L.size + R.size;
        sum = L.sum + R.sum;
        suma = L.suma + R.suma + (ll) R.sum * L.size;
    }
};



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int n,q;
        ll total = 0;
        cin>>n>>q;
        vector<ll> arr(n+1);
        for(int i=1; i<=n; ++i){
            cin>>arr[i];
            if(i%2)
                arr[i] *= -1;
        }
        int B = 1;
        while(B<=n){
            B *= 2;
        }
        vector<Tree> tree(2*B);
        for(int i=0; i<B; i++)
            tree[B+i].init(0);
        for(int i=1; i<=n; i++)
            tree[B+i].init(arr[i]);
        for(int i=B-1; i>=1; --i)
            tree[i].merge(tree[2*i],tree[2*i+1]);
        
        while(q--){
            char ch;
            cin>>ch;
            if(ch=='U'){
                int id;
                ll val;
                cin>>id>>val;
                if(id%2)
                    val *= -1;
                tree[B+id].init(val);
                for(int i=(B+id)/2; i>=1; i/=2){
                    tree[i].merge(tree[2*i],tree[2*i + 1]);
                }
            }
            else{
                int l, r;
                cin>>l>>r;
                bool sign = l%2;
                l += B;
                r += B;
                bool single = (l==r);
                Tree left,right;
                left = tree[l];
                right = tree[r];
                while(l+1<r){
                    if(l%2==0)
                        left.merge(left,tree[l+1]);
                    if(r%2)
                        right.merge(tree[r-1],right);
                    l /= 2;
                    r /= 2;
                }
                Tree res = left;
                if(!single){
                    res.merge(left,right);
                }
                if(sign)
                    res.suma *= -1;
                total += res.suma;
            }
        }
        cout<<"Case #"<<test<<": "<<total<<"\n";
    }
    return 0;
}