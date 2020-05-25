#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
typedef long long int ll;

ll calculate(vector<int>& p, vector<vector<ll>>& matrix){
    int n = p.size();
    ll sum = 0;
    for(int i=0; i<n-1; i++){
        sum += ((matrix[p[i]][p[i+1]] + matrix[p[i+1]][p[i]])*((i>=2)?2:1));
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    vector<int> p = {0,1,2,3,4};
    vector<vector<ll>> matrix(5,vector<ll>(5));
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            cin>>matrix[i][j];
    ll res = 0;
    do{
        ll tmp = calculate(p,matrix);
        if(res<tmp)
            res = tmp;
    }while(next_permutation(p.begin(),p.end()));
    cout<<res<<"\n";
    return 0;
}