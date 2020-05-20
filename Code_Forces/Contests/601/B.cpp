#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")


bool compare(pair<int,int>& a, pair<int,int>& b){
    if(a.first==b.first)
        return a.second<=b.second;
    return a.first<=b.first;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    scanf("%d",&t);
    for(int test = 1; test<=t; test++){
        int n,m;
        long long int res = 0;
        scanf("%d%d",&n,&m);
        vector<pair<int,int>> arr(n);
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_heap;
        for(int i=0; i<n;i++){
            int tmp;
            scanf("%d",&tmp);
            arr[i] = {tmp,i};
            res += tmp;
        }
        if(m<n || (m>((n*(n-1))/2))){
            cout<<-1<<"\n";
            continue;
        }
        sort(arr.begin(),arr.end(),compare);
        res *= 2;
        m -= n;
        vector<pair<int,int>> ans;
        for(int i=0; i<n, m>0; i++){
            for(int j=i+1; j<n, m>0; j++){
                if(abs(arr[i].second - arr[j].second)==1)
                    continue;
                res += arr[i].first + arr[j].first;
                ans.push_back({arr[i].second+1, arr[j].second+1});
                m--;
            }
        }
        cout<<res<<"\n";
        for(int i=1;i<n;i++){
            cout<<i<<" "<<i+1<<"\n";
        }
        cout<<n<<" "<<1<<"\n";
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i].first<<" "<<ans[i].second<<"\n";
        }
    }
    return 0;
}