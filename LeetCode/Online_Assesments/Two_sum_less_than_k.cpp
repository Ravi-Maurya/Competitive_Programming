#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int solve(vector<int>& arr, int k){
    sort(arr.begin(),arr.end());
    int l = 0, r = arr.size()-1,res = INT_MIN;
    while(l<r){
        int curr_sum = arr[l]+arr[r];
        if(curr_sum<k && curr_sum>res)
            res = curr_sum;
        else if(curr_sum>=k)
            r--;
        else
            l++;
    }
    return res==INT_MIN?-1:res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}