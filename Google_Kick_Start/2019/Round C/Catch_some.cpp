#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
#define inf 200000000

int n,k;
int freq[1100];
int dp[1010][1010][2];
vector<pair<int,int>> v;
vector<int> g[1005];
int c =  0;
int rec(int color,int left,int ret){
	if(left <= 0)
		return 0;
	if(color >= c)
		return inf;
	if(dp[color][left][ret] == -1){
		int ans = inf;
		ans = rec(color + 1,left,ret);
		for(int i = 0; i < g[color].size();i++){
			int j = i+1;
			for(;j < g[color].size();j++){
				if(g[color][i] == g[color][j]);
				else
					break;
			}
			int lans = 2*g[color][i] + rec(color+1,left - j,ret);
			i = j - 1;
			if(ret == 0)
				lans = min(lans,g[color][i] + rec(color+1,left - j,1));
			ans =  min(ans,lans);
		}
		dp[color][left][ret] = ans;
		return ans;
	}
	else
		return dp[color][left][ret];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        memset(freq,0,sizeof(freq));
        memset(dp,-1,sizeof(dp));
        cin>>n>>k;
        for(int i=0; i<=1001; i++)
            g[i].clear();
        v.resize(n);
        for(int i=0;i<n;i++)
            cin>>v[i].first;
        map<int,int> m;
        for(int i=0;i<n;i++){
            cin>>v[i].second;
            m[v[i].second]++;
        }
        c = 0;
        for(auto &it: m){
            it.second = c;
            c++;
        }
        for(int i=0; i<n; i++){
            v[i].second = m[v[i].second];
            g[v[i].second].push_back(v[i].first);
        }
        for(int i=0;i<=1000; i++){
            if(g[i].size()>0)
                sort(g[i].begin(),g[i].end());
        }
        int res = rec(0,k,0);
        cout<<"Case #"<<test<<": "<<res<<"\n";
    }
    return 0;
}