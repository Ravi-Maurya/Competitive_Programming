#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
vector<int> tree;
int build(vector<int>& arr, int i, int j, int idx){
    if(i==j){
        tree[idx] = arr[i];
        return tree[idx];
    }
    int mid = i + (j-i)/2;
    tree[idx] = min(build(arr,i,mid,idx*2 +1),build(arr,mid+1,j,idx*2 +2));
    return tree[idx];
}
void constructor(vector<int>& arr){
    int n = arr.size();
    int p = int(ceil(log2(n)));
    int size = 2*pow(2,p) - 1;
    tree.clear();
    tree.resize(size);
    build(arr,0,n-1,0);
    return;
}
int query(int i, int j, int a, int b, int idx){
    if(a<=i && b>=j)
        return tree[idx];
    if(j<a || i>b)
        return INT_MAX;
    int mid = i + (j-i)/2;
    return min(query(i,mid,a,b,2*idx+1), query(mid+1,j,a,b,2*idx+2));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}