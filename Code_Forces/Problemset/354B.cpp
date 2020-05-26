#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

// int bin_search(vector<int>& arr, int val){
//     int l = 0, h = arr.size();
//     if(val>=arr[h-1])
//         return arr[h-1];
//     while (l<h){
//         int mid = l + (h-l)/2;
//         if(arr[mid]==val)
//             return arr[mid];
//         else if (arr[mid]<val)
//             l = mid;
//         else
//             h = mid-1;
//     }
//     return arr[l];
// }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n,t;
    cin>>n>>t;
    vector<vector<float>> A(n+2,vector<float>(n+2,0));
    A[1][1] = t;
    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(A[i][j]>=1){
            float left = A[i][j]-1;
            res++;
            float dst = (left*1.0)/2;
            A[i+1][j] += dst;
            A[i+1][j+1] += dst;
            }
        }
    }
    cout<<res<<"\n";
    // vector<int> arr(n);
    // for(int i=0; i<n; i++){
    //     arr[i] = pow(2,i+1) -1;
    //     cout<<arr[i]<<" ";
    // }
    // cout<<"\n";
    // auto it = bin_search(arr,t);
    // cout<<it;
    // if(it != arr.end())
    //     cout<<*it;
    // else
    //     cout<<arr[n-1];
    // cout<<"\n";
    return 0;
}