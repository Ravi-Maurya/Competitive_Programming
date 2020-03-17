#include <bits/stdc++.h>
bool isValid(vector<int> &A, int B, int curr){
    int n = A.size();
    int students = 1;
    int curr_pages = 0;
    for(int i=0;i<n;i++){
        if (curr_pages+A[i]>curr){
            curr_pages = A[i];
            students++;
            if(students>B)
                return false;
        }
        else{
            curr_pages += A[i];
        }
    }
    return true;
}
int max(int a, int b){
    return a>b?a:b;
}
int Solution::books(vector<int> &A, int B) {
    int n = A.size(),i;
    if (n<B)
        return -1;
    long long int st = 0, en = 0;
    for(i=0;i<n;i++){
        en += A[i];
        st = max(st,A[i]);
    }
    int ans = 0;
    while (st<=en){
        long long int mid = (st+en)/2;
        if (isValid(A,B,mid)){
            ans = mid;
            en = mid-1;
        }
        else
            st = mid+1;
    }
    return ans;
}