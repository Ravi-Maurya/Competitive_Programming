#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int n;
        cin>>n;
        vector<long long int> arr(n),res(n);
        stack<int> s;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        s.push(0);
        for(int i=1; i<n; i++){
            if(s.empty()){
                s.push(i);
                continue;
            }
            while(!s.empty() && arr[s.top()]<arr[i]){
                res[s.top()] = arr[i];
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            res[s.top()] = -1;
            s.pop();
        }
        for(auto x:res)
            cout<<x<<" ";
        cout<<"\n";
    }
    return 0;
}