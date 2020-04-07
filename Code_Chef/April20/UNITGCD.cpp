#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
#define MAXN 1000001
int spf[MAXN];
unordered_map<int,unordered_set<int>> mapp;
void sieve(){
    spf[1] = 1;
    for(int i=2;i<MAXN;i++)
        spf[i] = i;
    for(int i=4;i<MAXN; i+=2)
        spf[i] = 2;
    for(int i=3; i*i<MAXN;i++)
        if(spf[i]==i)
            for(int j=i*i;j<MAXN;j+=i)
                if(spf[j]==j)
                    spf[j] = i;
}

unordered_set<int> getfactorization(int n){
    if(mapp.find(n)!=mapp.end())
        return mapp[n];
    unordered_set<int> res;
    while(n!=1){
        res.insert(spf[n]);
        n = n/spf[n];
    }
    mapp[n] = res;
    return res;
}

bool check(vector<int>& arr, int n){
    unordered_set<int> tmp = getfactorization(n);
    for(int& i:arr){
        if(i==1)
            continue;
        unordered_set<int> tmp1 = getfactorization(i);
        for(auto x:tmp1)
            if(tmp.find(x)!=tmp.end())
                return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    sieve();
    mapp.clear();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<bool> hash(n+1,false);
        vector<pair<int,vector<int>>> res;
        
    }

    return 0;
}