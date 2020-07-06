#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int n){
    int lis[n],lds[n];
    memset(lis,1,sizeof(lis));
    memset(lds,1,sizeof(lds));
    for(int i=1; i<n; i++)
        for(int j=0; j<i; j++)
            if(arr[j]<arr[i] && lis[i]<lis[j]+1)
                lis[i] = lis[j] + 1;
    
    for(int i=n-2; i>=0 i--)
        for(int j=n-1;j>i; j--)
            if(arr[j]<arr[i] && lds[i]<lds[j]+1)
                lds[i]= lds[j]+1;
    int res = lis[0] + lds[0] - 1;
    for(int i=1; i<n;i++)
        res = max(res,lis[i]+lds[i]-1);
    return res;
}

int main(){
    return 0;
}