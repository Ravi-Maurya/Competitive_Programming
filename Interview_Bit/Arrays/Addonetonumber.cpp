#include <bits/stdc++.h> 
using namespace std;
class Solution{
    public:
    vector<int> plusOne(vector<int> &A) {
    int i,n = A.size();
    int carry = 0;
    for(i=n-1;i>-1;i--){
        if (carry==0 && i!=n-1)
            break;
        if (i==n-1)
            A[i] += 1;
        else
            A[i] += carry;
        
        if (A[i]==10){
            A[i] = 0;
            carry = 1;
        }
        else
            carry = 0;
    }
    if (carry==1){
        vector<int> res;
        res.push_back(carry);
        for(i=0;i<n;i++)
            res.push_back(A[i]);
        return res;
    }
    else{
        i = 0;
        while (i<n && A[i]==0)
            i++;
        if (i==0)
            return A;
        vector<int> res;
        while (i<n){
            res.push_back(A[i]);
            i++;
        }
        return res;
    }
}

};