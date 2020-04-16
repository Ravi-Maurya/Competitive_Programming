#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int n,m,K;
        cin>>n>>m>>K;
        int res = 0;
        vector<vector<int>> matrix(n,vector<int>(m));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>matrix[i][j];
        vector<vector<vector<int>>> sol(n,vector<vector<int>>(m,vector<int>(m)));
        for(int i=0; i<n;i++){
            for(int j=0;j<m;j++){
                int mn = matrix[i][j];
                int mx = matrix[i][j];
                for(int k=j; k<m; k++){
                    mn = min(mn,matrix[i][k]);
                    mx = max(mx,matrix[i][k]);
                    sol[i][j][k] = mx - mn;
                }
            }
        }
        for(int j=0; j<m ;j++){
            for(int k=j; k<m;k++){
                int tmp = 0;
                for(int i=0;i<n;i++){
                    if(sol[i][j][k]>K){
                        res = max(res, tmp*(k-j+1));
                        tmp = 0;
                    }
                    else
                        tmp++;
                }
                res = max(res, tmp*(k-j+1));
            }
        }
        cout<<"Case #"<<test<<": "<<res<<"\n";
    }
    return 0;
}