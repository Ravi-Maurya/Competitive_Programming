#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
int jump(vector<int> &A) {
    int n = A.size();
    if (n==1)
        return 0;
    int jumps = 1;
    int maxJump = A[0];
    int nxtJump  = A[0];
    for(int i=1;i<n;i++){
        if(i>nxtJump)
            return -1;
        nxtJump = max(nxtJump,i+A[i]);
        if(i==maxJump && i!=n-1){
            maxJump = nxtJump;
            jumps++;
        }
    }
    return jumps;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            cin>>arr[i];
        int res = jump(arr);
        if(res == -1)
            cout<<"-1\n";
        else
            cout<<res<<"\n";
    }
    return 0;
}