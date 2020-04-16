#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int n,k;
        cin>>k>>n;
        vector<pair<long long int, long long int>> arr(n+1);
        for(int i=1;i<=n;i++)
            cin>>arr[i].first;
        for(int i=1;i<=n;i++)
            cin>>arr[i].second;
        map<int,vector<long long int>> left, right;
        sort(arr.begin()+1,arr.end());
        for(int req: {k/2, (k+1)/2}){
            long long int best_sum = 0;
            priority_queue<long long int> pq;
            for(int i=0;i<req;i++){
                long long tmp = 1e12;
                pq.push(tmp);
                best_sum += tmp;
            }
            left[req].resize(n+2,0);
            if(req)
                for(int w=1; w<=n; w++){
                    left[req][w] = best_sum + req*arr[w].first;
                    long long tmp = arr[w].second - arr[w].first;
                    if(pq.top()>tmp){
                        best_sum += tmp;
                        best_sum -= pq.top();
                        pq.pop();
                        pq.push(tmp);
                    }
                }
        }
        for(int req: {k/2, (k+1)/2}){
            long long int best_sum = 0;
            priority_queue<long long int> pq;
            for(int i=0;i<req;i++){
                long long tmp = 1e12;
                pq.push(tmp);
                best_sum += tmp;
            }
            right[req].resize(n+2,0);
            if(req)
                for(int w=n; w>=1; w--){
                    right[req][w] = best_sum - req*arr[w].first;
                    long long tmp = arr[w].second + arr[w].first;
                    if(pq.top()>tmp){
                        best_sum += tmp;
                        best_sum -= pq.top();
                        pq.pop();
                        pq.push(tmp);
                    }
                }
        }
        long long int res = 1e18;
        for(int w=1; w<=n; w++){
            res = min({res,arr[w].second + right[k/2][w] + left[(k+1)/2][w], arr[w].second + left[k/2][w] + right[(k+1)/2][w]});
        }
        cout<<"Case #"<<test<<": "<<res<<"\n";
    }
    return 0;
}