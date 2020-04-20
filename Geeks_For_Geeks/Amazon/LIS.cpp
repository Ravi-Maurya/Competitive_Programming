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
        vector<int> arr(n),lis(n,1);
        for(int i=0; i<n;i++)
            cin>>arr[i];
        for(int i=1;i<n;i++)
            for(int j=0;j<i;j++)
                if(arr[i]>arr[j] && lis[i]<lis[j]+1)
                    lis[i] = lis[j]+1;
        cout<<*max_element(lis.begin(),lis.end())<<"\n";
    }
    return 0;
}