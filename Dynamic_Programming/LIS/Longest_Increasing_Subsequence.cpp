#include<bits/stdc++.h>
using namespace std;

int global_max;
int lis(vector<int>& arr, int n){
    if(n==1)
        return 1;
    int res,curr= 1;
    for(int i=1; i<n; i++){
        res = lis(arr,i);
        if(arr[i-1]<arr[n-1] && res+1>curr){
            curr = res+1;
        }
    }
    if(global_max<curr)
        global_max = curr;
    return curr;
}

int solve(vector<int>& arr, int n){
    int Lis[n];
    memset(Lis, 1 ,sizeof(Lis));
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i] && Lis[i]<Lis[j]+1)
                Lis[i] = Lis[j] + 1;
        }
    }
    return *max_element(Lis);
}

vector<int> printLis(vector<int>& arr, int n){
    vector<vector<int>> Lis(n);
    Lis[0].push_back(arr[0]);
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i] && Lis[i].size()<Lis[j].size()+1)
                Lis[i] = Lis[j];
        }
        Lis[i].push_back(arr[i]);
    }
    vector<int> max = Lis[0];
    for(auto l: Lis)
        if(l.size()>max.size())
            max = l;
    return max;
}

int solve2(vector<int>& arr, int n){
    if(n==0)
        return 0;
    vector<int> tail(n,0);
    int length = 1;
    tail[0] = arr[0];
    for(int i=1; i<n; i++){
        auto it = lower_bound(tail.begin(),tail.end(),arr[i]);
        if(it==tail.begin()+length)
            tail[length++] = arr[i];
        else
            *it = arr[i];
    }
    return length;
}

/*
Anothe Approach is use LCS as LCS(arr,sorted(arr));
*/

int main(){
    return 0;
}

