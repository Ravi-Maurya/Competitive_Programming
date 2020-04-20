#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

long long int merge(vector<long long int>& arr, vector<long long int>& tmp, long long int left, long long int mid, long long int right){
    long long int i,j,k;
    long long int inv = 0;
    i = left;
    j = mid+1;
    k = left;
    while ((i<=mid) && (j<=right)){
        if(arr[i]<=arr[j])
            tmp[k++] = arr[i++];
        else{
            tmp[k++] = arr[j++];
            inv += (mid-i+1);
        }
    }
    while(i<=mid)
        tmp[k++] = arr[i++];
    while(j<=right)
        tmp[k++] = arr[j++];
    for(int i=left; i<=right; i++)
        arr[i] = tmp[i];
    return inv;
    
}

long long int mergesort(vector<long long int>& arr, vector<long long int>& tmp, long long int l, long long int r){
    long long int m,inv = 0;
    if(r>l){
        m = l + ((r-l)>>1);
        inv += mergesort(arr,tmp,l,m);
        inv += mergesort(arr,tmp,m+1,r);
        inv += merge(arr,tmp,l,m,r);
    }
    return inv;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        long long int n;
        cin>>n;
        vector<long long int> arr(n),tmp(n);
        for(int i=0; i<n;i++)
            cin>>arr[i];
        cout<<mergesort(arr,tmp,0,n-1)<<"\n";
    }
    return 0;
}