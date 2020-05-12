#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
int lis1(int arr[], int n){//O(n*n)
    int dp[n];
    dp[0] = 1;
    for(int i=1; i<n; i++){
        lis[i] = 1;
        for(int j=0; j<i; j++)
            if(arr[j]<arr[i] && lis[i]<lis[j] + 1)
                lis[i] = lis[j] + 1;
    }
    return *max_element(lis, lis+n);
}

int lis2(vector<int> arr){//O(nLog(n))
    // Find the best position for upcoming
    //values in aux array which stores
    //the max possible array size which
    //is Longest increasing;
    int n = arr.size();
    if(n==0)
        return 0;
    vector<int> aux(n,0);
    int lenght = 1;
    aux[0] = arr[0];
    for(int i=1; i<n; i++){
        auto it = lower_bound(aux.begin(), aux.begin()+lenght, arr[i]);
        if(it==aux.begin()+lenght)
            aux[lenght++] = arr[i];
        else
            *it = v[i];
    }
    return lenght;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}