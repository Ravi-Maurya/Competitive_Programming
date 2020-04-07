#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test=1;test<=t;test++){
        int n;
        cin>>n;
        int latin = 0;
        int r=0,c=0;
        vector<vector<int>> matrix(n,vector<int>(n));
        bool flag = false;
        for(int i=0;i<n;i++){
            vector<int> row(n+1,0);
            for(int j=0;j<n;j++){
                cin>>matrix[i][j];
                if(i==j)
                    latin += matrix[i][j];
                row[matrix[i][j]]++;
                if(row[matrix[i][j]]>1 && !flag){
                    flag = true;
                    r++;
                }
            }
            flag = false;
        }
        flag = false;
        for(int j=0;j<n;j++){
            vector<int> col(n+1,0);
            for(int i=0;i<n;i++){
                col[matrix[i][j]]++;
                if(col[matrix[i][j]]>1 && !flag){
                    flag = true;
                    c++;
                }
            }
            flag = false;
        }
        cout<<"Case #"<<test<<": "<<latin<<" "<<r<<" "<<c<<endl;
    }
    return 0;
}