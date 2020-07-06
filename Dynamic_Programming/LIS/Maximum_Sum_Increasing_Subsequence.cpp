#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> arr, int n){
    vector<int> lis = arr;
    int res = lis[0];
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++)
            if(arr[j]<arr[i] && lis[i] < lis[j] + arr[i])
                lis[i] = lis[j] + arr[i];
        
        if(lis[i]>res)
            res = lis[i];
    }
    return res;
}

int main(){
    return 0;
}