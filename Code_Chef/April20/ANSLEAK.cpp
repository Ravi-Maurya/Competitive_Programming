#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> res;
        for(int i=0;i<n;i++){
            vector<int> curr(m,0);
            for(int j=0 ; j<k ; j++){
                int row_i_j;
                cin>>row_i_j;
                curr[row_i_j - 1] += 1;
            }
            vector<int> tmp;
            int max_curr = *max_element(curr.begin(), curr.end());
            for(int j=0;j<m;j++)
                if(curr[j]==max_curr)
                    tmp.push_back(j+1);
            res.push_back(*max_element(tmp.begin(),tmp.end()));
        }
        for(int i=0;i<n;i++){
            if(i==(n-1))
                cout<<res[i]<<endl;
            else
                cout<<res[i]<<" ";
        }
    }
    return 0;
}