#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int cons_sum(int n){
    return n*(n+1)/2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        int sum = 0;
        bool flag = 0;
        for(int i=0;i<n;i++){
            cin>>A[i];
            if(A[i]>=n)
                flag = true;
            sum += A[i];
        }
        if(flag){
            cout<<0<<endl;
            continue;
        }
        if(n==2){
            if(A[0]==A[1] && A[0]==1){
                cout<<1<<endl;
                cout<<1<<1<<endl;
            }
            else
                cout<<0<<endl;
            continue;
        }
        vector<int> mapp1(n,0),mapp2(n,0);
        int sum1 = A[0], sum2 = sum-A[0];
        mapp1[A[0]]++;
        for(int i=1;i<n;i++)
            mapp2[A[i]]++;
        for(int i=1;i<n;i++){
            // 
        }

    }
    return 0;
}