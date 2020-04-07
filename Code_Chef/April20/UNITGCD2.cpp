#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
#define MAXN 1000001

int gcd(unsigned long long int x,unsigned long long int y){
    if(y==0)
        return x;
    return gcd(y,x%y);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<1<<endl;
            cout<<1<<" "<<1<<endl;
            continue;
        }
        vector<vector<int>> res;
        vector<int> r1,r2,tmp;
        for(int i=2;i<=n;i++)
            r1.push_back(i);
        tmp.push_back(1);
        unsigned long long int prod = 1;
        while(r1.size()){
            for(int& x:r1){
                if(gcd(prod,x)==1){
                    tmp.push_back(x);
                    prod = prod*x;
                }
                else{
                    r2.push_back(x);
                }
            }
            prod = 1;
            res.push_back(tmp);
            tmp.clear();
            r1 = r2;
            r2.clear();
        }
        int k = res.size();
        cout<<k<<endl;
        for(int i=0;i<k;i++){
            cout<<res[i].size()<<" ";
            int j;
            for(j=0;j<res[i].size()-1;j++)
                cout<<res[i][j]<<" ";
            cout<<res[i][j]<<endl;
        }
    }
    return 0;
}