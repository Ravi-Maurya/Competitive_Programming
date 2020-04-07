#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
const long long int mod = 1000000007;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        priority_queue<long long int> pq;
        for(int i=0;i<n;i++){
            long long int tmp;
            cin>>tmp;
            pq.push(tmp);
        }
        long long int sum = 0;
        int loss = 0;
        while(!pq.empty()){
            long long int tmp = pq.top()-loss;
            sum = (sum%mod + (tmp>=0?tmp:0)%mod)%mod;
            loss++;
            pq.pop();
        }
        cout<<sum<<endl;
    }
    return 0;
}