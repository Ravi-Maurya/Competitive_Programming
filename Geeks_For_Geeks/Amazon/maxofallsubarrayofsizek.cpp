#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

vector<int> slidingMaximum(const vector<int> &A, int B) {
    if(B==1)
        return A;
    deque<int> q;
    int n = A.size(),i;
    B = min(B,n);
    for(i=0;i<B;i++){
        while(!q.empty() && A[i]>=A[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    vector<int> res;
    for(i=B;i<n;i++){
        res.push_back(A[q.front()]);
        while(!q.empty() && q.front()<=i-B)
            q.pop_front();
        while(!q.empty() && A[i]>=A[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    res.push_back(A[q.front()]);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0; i<n;i++){
            cin>>arr[i];
        }
        vector<int> res = slidingMaximum(arr,k);
        for(auto x:res)
            cout<<x<<" ";
        cout<<"\n";
    }
    return 0;
}