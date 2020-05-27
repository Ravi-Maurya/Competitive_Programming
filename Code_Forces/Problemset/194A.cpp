#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>> matrix(n,vector<int>(n));
    vector<int> arr(n);
    
    for(int i=0;i<n; i++){
        for(int j=0; j<n; j++){
            int add = (j+1 + i)%n;
            if(add == 0)
                add  = n;
            int t = n*j + (add);
            cout<<t<<" ";
        }
        cout<<"\n";
    }
    return 0;
}