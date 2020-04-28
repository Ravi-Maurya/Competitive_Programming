#include<bits/stdc++.h>
using namespace std;
int find_missing(vector<int>& arr){
    int l=0, r = arr.size()-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(arr[mid]!=mid+1 && arr[mid-1]==mid)
            return mid+1;
        if(arr[mid]!=mid+1)
            r = mid-1;
        else
            l=mid+1;
    }
    return -1;
}