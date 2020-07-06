#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int n){
    int lis[n][2];
    memset(lis,1,sizeof(lis));
    int res = 1;
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i] && lis[i][0]<lis[i][1] + 1)
                lis[i][0] = lis[i][1] + 1;
            
            if(arr[j]>arr[i] && lis[i][1]<lis[j][0] + 1)
                lis[i][1] = lis[j][0] + 1;
        }
        int tmp = max(lis[i][1],lis[i][0]);
        if(res<tmp)
            res = tmp;
    }
    return res;
}


int main(){
    return 0;
}