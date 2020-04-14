// Interval Tree for queries + Greedy approach

#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

bool check(int k, vector<pair<int,int>>& bookings, int q){
    vector<int> bias(q);
    for(int i=0;i<q;i++)
        bias[i] = bookings[i].first;
    for(int i=0;i<q;i++){
        int st = bias[i], ed = -bookings[i].second, count = 0;
        for(int j=i+1; j<q;j++){
            if(-bookings[j].second <= -bookings[i].second){
                if(bookings[j].first <= st){
                    st = max(st, 1 - bookings[j].second);
                }
                else{
                    count += bookings[j].first - st;
                    st = max(st, 1 - bookings[j].second);
                    if(count>=k){
                        ed = bookings[j].first - count + k;
                        break;
                    }
                }
            }
        }
        if(count<k){
            count += 1 - bookings[i].second - st;
            if(count<k)
                return false;
            ed = 1 - bookings[i].second - count + k;
        }
        for(int j=i+1;j<q;j++){
            if(bookings[j].first >= ed)
                break;
            if(-bookings[j].second > -bookings[i].second)
                bias[j] = max(bias[j],1 - bookings[i].second);
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test=1;test<=t;test++){
        int n,q;
        cin>>n>>q;
        vector<pair<int,int>> bookings;
        for(int i=0;i<q;i++){
            int left,right;
            cin>>left>>right;
            bookings.push_back(make_pair(left,-right));
        }
        sort(bookings.begin(),bookings.end());
        int res = 0,l=0,r=n;
        while(l<=r){
            int mid = (l+r)>>1;
            if(check(mid,bookings,q)){
                res = mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        cout<<"Case #"<<test<<": "<<res<<"\n";
    }
    return 0;
}