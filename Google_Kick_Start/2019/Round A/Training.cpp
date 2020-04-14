// Deque concept + sorting

#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int n,p;
        cin>>n>>p;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr.begin(),arr.end());
        deque<int> dq;
        int prev_max = arr[p-1];
        int sm = 0;
        for(int i=0;i<p;i++){
            sm += arr[i];
            dq.push_back(i);
        }
        int res = p*prev_max - sm;
        for(int i=p; i<n;i++){
            sm -= arr[dq.front()];
            dq.pop_front();
            sm += arr[i];
            dq.push_back(i);
            res = min(res, p*arr[i] - sm);
        }
        cout<<"Case #"<<test<<": "<<res<<"\n";
    }
    return 0;
}