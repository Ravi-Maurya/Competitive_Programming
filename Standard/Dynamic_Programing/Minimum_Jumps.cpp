#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int jump(vector<int>& arr){
    int n = arr.size();
    if(n==1)
        return 0;
    int jumps = 1;
    int max_jump = arr[0], next_jump = arr[0];
    for(int i=1; i<n; i++){
        if(next_jump<i)
            return -1;
        next_jump = max(next_jump, arr[i]+i);
        if(max_jump == i && i!=n-1){
            max_jump = next_jump;
            jumps++;
        }
    }
    return jumps;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}