#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    vector<vector<ll>> grid(n,vector<ll>(n));
    pair<int,int> idx = {-1,-1};
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
            if(grid[i][j]==0)
                idx = {i,j};
        }
    if(n==1 && idx.first != -1){
        cout<<1<<"\n";
        return 0;
    }
    unordered_set<ll> allsum;
    bool r,c,d,di;
    d = (idx.first == idx.second);
    di = (idx.first == n - idx.second-1);
    ll row_rem = -1,col_rem=-1;
    ll d1 = 0, d2 =0;
    ll beensum = 0;
    for(int i=0; i<n; i++){
        d1 += grid[i][i];
        d2 += grid[i][n-i-1];
        r = (i==idx.first);
        ll sum = 0;
        for(int j=0; j<n; j++){
            sum += grid[i][j];
        }
        if(r)
            row_rem = sum;
        else
            beensum = sum;
        allsum.insert(sum);
    }
    for(int j=0; j<n; j++){
        c = (j==idx.second);
        ll sum = 0;
        for(int i=0; i<n; i++){
            sum += grid[i][j];
        }
        if(c)
            col_rem = sum;
        allsum.insert(sum);
    }
    allsum.insert(d1);
    allsum.insert(d2);
    // for(auto a: allsum)
    //     cout<<a<<" ";
    // cout<<row_rem<<" "<<col_rem<<" "<<d1<<" "<<d2<<"\n";
    if(allsum.size()!=2 || (row_rem!=col_rem) || (!d && d1!=beensum) || (!di && d2!=beensum)){
        cout<<-1<<"\n";
        return 0;
    }
    ll res = beensum - row_rem;
    cout<<((res>0)?res:-1)<<"\n";
    return 0;
}