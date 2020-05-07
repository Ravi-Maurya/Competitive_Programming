#include <bits/stdc++.h> 
using namespace std; 

class Solution{
    public:
    pair<int,int> two_sum_less_than_k(vector<int>& arr, int k){
        int n = arr.size();
        if(n<2)
            return {-1,-1};
        sort(arr.begin(), arr.end());
        int i=0, j = n-1;
        int res = INT_MIN;
        pair<int,int> ans = {-1,-1};
        while(i<j){
            int curr_val = arr[i] + arr[j];
            if(curr_val<k){
                if(curr_val>res){
                    res = curr_val;
                    ans = {arr[i],arr[j]};
                }
                i++;
            }
            else
                j--;
        }
        return ans;
    }
}