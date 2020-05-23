#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

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
    
    void buildTree(int st, int en, int idx){
        if(st==en){
            tree[idx] = arr[st];
            return;
        }
        int mid = st + (en-st)/2;
        buildTree(st,mid,2*idx);
        buildTree(mid+1,en,2*idx+1);
        tree[idx] = tree[2*idx] + tree[2*idx+1];
        return;
    }

    int query(int st, int en, int l, int r, int idx){ // intitially(0,n-1,i,j,1)
        if(st>en || st>r || en<l || l>r)
            return 0;
        if(st>=l && en<=r)
            return tree[idx];
        int mid = st + (en-st)/2;
        return query(st,mid,l,r,2*idx) + query(mid+1,en,l,r,2*idx+1);
    }

    void update(int st, int en, int i, int val, int idx){
        if(st>en || st>i || en<i)
            return;
        if(st==en){
            tree[idx] = val;
            return;
        }
        int mid = st + (en-st)/2;
        update(st,mid,i,val,2*idx);
        update(mid+1,en,i,val,2*idx+1);
        tree[idx] = tree[2*idx] + tree[2*idx+1];
        return;
    }

};


class SegmentTreeLazyProp{
public:
    vector<int> arr;
    vector<int> tree;
    vector<int> lazy;
    int n;
    SegmentTreeLazyProp(vector<int>& input){
        arr.clear();
        tree.clear();
        lazy.clear();
        arr = input;
        n = input.size();
        tree.resize(4*n);
        lazy.resize(4*n,0);
        buildTree(0,n-1,1);
    }
    
    void buildTree(int st, int en, int idx){
        if(st==en){
            tree[idx] = arr[st];
            return;
        }
        int mid = st + (en-st)/2;
        buildTree(st,mid,2*idx);
        buildTree(mid+1,en,2*idx+1);
        tree[idx] = tree[2*idx] + tree[2*idx+1];
        return;
    }

    int query(int st, int en, int l, int r, int idx){ // intitially(0,n-1,i,j,1)
        if(st>en || st>r || en<l || l>r)
            return 0;
        if(lazy[idx]!=0){
            tree[idx] += (en-st+1)*lazy[idx];
            if(st!=en){
                lazy[2*idx] += lazy[idx];
                lazy[2*idx+1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if(st>=l && en<=r)
            return tree[idx];
        int mid = st + (en-st)/2;
        return (query(st,mid,l,r,2*idx) + query(mid+1,en,l,r,2*idx+1));
    }

    void update(int st, int en, int i, int j, int val, int idx){
        if(lazy[idx]!=0){
            tree[idx] += (en-st+1)*lazy[idx];
            if(st!=en){
                lazy[2*idx] += lazy[idx];
                lazy[2*idx+1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if(st>en || st>i || en<i)
            return;
        if(st>=i && en<=j){
            tree[idx] += (en-st+1)*val;
            if(st!=en){
                lazy[2*idx] += lazy[idx];
                lazy[2*idx+1] += lazy[idx];
            }
            return;
        }
        int mid = st + (en-st)/2;
        update(st,mid,i,j,val,2*idx);
        update(mid+1,en,i,j,val,2*idx+1);
        tree[idx] = tree[2*idx] + tree[2*idx+1];
        return;
    }

};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n = 5;
    vector<int> arr = {1,2,3,4,5};
    auto root1 = SegmentTree(arr);
    root1.update(0,n-1,n-2,1,1);
    cout<<root1.query(0,n-1,0,2,1);
    auto root2 = SegmentTreeLazyProp(arr);
    root2.update(0,n-1,n-2,n-2,1,1);
    cout<<root2.query(0,n-1,0,2,1);
    cout<<"\n";
    return 0;
}