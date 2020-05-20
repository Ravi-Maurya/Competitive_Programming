#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    string chicken ="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int t;
    cin>>t;
    for(int test=1;test<=t; test++){
        int r,c,k, count_r = 0, pos = 0;
        cin>>r>>c>>k;
        vector<string> grid(r);
        for(int i=0;i<r;i++){
            cin>>grid[i];
            for(int j=0; j<c; j++)
                if(grid[i][j]=='R')
                    count_r++;
        }
        int equal = count_r/k;
        int extra = count_r%k;
        int count = 0;
        for(int i=0; i<r; i++){
            if(i&1){
                for(int j = c-1; j>=0; j--){
                    if(grid[i][j]=='R')
                        count++;
                    grid[i][j] = chicken[pos];
                    if(extra>0 && count == equal +1){
                        extra--;
                        if(pos<k-1)
                            pos++;
                        count = 0;
                    }
                    if(extra == 0 && count==equal){
                        if(pos < k-1)
                            pos++;
                        count = 0;
                    }
                }
            }
            else{
                for(int j = 0; j<c; j++){
                    if(grid[i][j]=='R')
                        count++;
                    grid[i][j] = chicken[pos];
                    if(extra>0 && count == equal +1){
                        extra--;
                        if(pos<k-1)
                            pos++;
                        count = 0;
                    }
                    if(extra == 0 && count==equal){
                        if(pos < k-1)
                            pos++;
                        count = 0;
                    }
                }
            }
        }
        for(int i=0; i<r; i++)
            cout<<grid[i]<<"\n";
    }
    return 0;
}