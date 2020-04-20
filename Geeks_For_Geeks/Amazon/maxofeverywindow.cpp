#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int n,mx = -1;
        cin>>n;
        stack<int> s;
        vector<int> res(n+1,0),arr(n),left(n+1,-1),right(n+1,n);
        for(int i=0; i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>=arr[i])
                s.pop();
            if(!s.empty())
                left[i] = s.top();
            s.push(i);
        }
        while(!s.empty())
            s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i])
                s.pop();
            if(!s.empty())
                right[i] = s.top();
            s.push(i);
        }
        for(int i=0;i<n;i++){
            int length = right[i] - left[i] - 1;
            res[length] = max(res[length],arr[i]);
        }
        for(int i=n-1; i>=1; i--)
            res[i] = max(res[i],res[i+1]);
        for(int i=1;i<=n;i++)
            cout<<res[i]<<" ";
        cout<<"\n";
    }
    return 0;
}