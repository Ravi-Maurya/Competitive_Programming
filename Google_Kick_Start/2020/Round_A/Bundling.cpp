// DFS as Tries

#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

long long int res;
int c[2000001][26], cnt[2000001];

void dfs(int u, int d, int k){
    for(int v=0;v<26; ++v)
        if(c[u][v])
            dfs(c[u][v],d+1, k), cnt[u] += cnt[c[u][v]];
    while(cnt[u]>=k){
        cnt[u] -= k;
        res += d;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int n,k,m=1;
        cin>>n>>k;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            int tmp = 0;
            for(auto ch: s){
                if(!c[tmp][ch-'A'])
                    c[tmp][ch-'A'] = m++;
                tmp = c[tmp][ch-'A'];
            }
            ++cnt[tmp];
        }
        res = 0;
        dfs(0,0,k);
        cout<<"Case #"<<test<<": "<<res<<"\n";
        memset(c,0,m*sizeof(c[0]));
        memset(cnt,0,m*4);
    }
    return 0;
}