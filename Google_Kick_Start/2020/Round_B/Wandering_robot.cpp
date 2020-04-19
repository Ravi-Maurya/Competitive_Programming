// Test case -2 TLE

#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int w,h,l,u,r,d;
        cin>>w>>h>>l>>u>>r>>d;
        vector<vector<long double>> matrix(2,vector<long double>(w+1,0));
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                if(u<=i && i<=d && l<=j && j<=r)
                    matrix[1][j] = 0.0;
                else if(i==1 && j==1)
                    matrix[1][j] = 1.0;
                else if(i==h && j==w)
                    matrix[1][j] = matrix[0][j] + matrix[1][j-1];
                else if(i==h)
                    matrix[1][j] = matrix[1][j-1]*1.0 + matrix[0][j]*0.5;
                else if(j==w)
                    matrix[1][j] = matrix[0][j]*1.0 + matrix[1][j-1]*0.5;
                else
                    matrix[1][j] = (matrix[1][j-1]*0.5 )+ (matrix[0][j]*0.5);
                // cout<<matrix[1][j]<<" "<<i<<" "<<j<<"\n";
            }
            swap(matrix[0],matrix[1]);
        }
        cout<<"Case #"<<test<<": "<<fixed<<setprecision(5)<<matrix[0][w]<<"\n";
    }
    return 0;
}