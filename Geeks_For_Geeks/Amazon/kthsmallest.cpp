#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int partition(vector<int>& arr, int l, int r){
    int x = arr[r], i = l;
    for(int j=l; j<=r-1;j++)
        if(arr[j]<=x){
            swap(arr[i],arr[j]);
            i++;
        }
    swap(arr[i],arr[r]);
    return i;
}

int randomPartition(vector<int>& arr, int l, int r) 
{ 
    int n = r-l+1; 
    int pivot = rand() % n;
    swap(arr[l + pivot], arr[r]); 
    return partition(arr, l, r); 
} 

int kthsmallest(vector<int>& arr, int l, int r, int k){
    if(k>0 && k<=r-l+1){
        int pos = randomPartition(arr,l,r);
        if(pos-l == k-1)
            return arr[pos];
        if(pos-l>k-1)
            return kthsmallest(arr,l,pos-1,k);
        return kthsmallest(arr,pos+1,r,k-pos+l-1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int n,k;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        cout<<kthsmallest(arr,0,n-1,k)<<"\n";
    }
    return 0;
}