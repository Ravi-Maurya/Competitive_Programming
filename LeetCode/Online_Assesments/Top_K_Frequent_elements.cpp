#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
// Approach 1
class Solution1 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int n: nums){
            if(mp.find(n)==mp.end())
                mp[n] = 1;
            else
                mp[n] += 1;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it:mp){
            pq.push(make_pair(it.second,it.first));
        }
        vector<int> res;
        for(int i=0; i<k; i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};

// Approach 2
class Solution2 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int n: nums){
            if(mp.find(n)==mp.end())
                mp[n] = 1;
            else
                mp[n] += 1;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto it:mp){
            if(pq.size()==k){
                if(it.second>pq.top().first){
                    pq.pop();
                    pq.push(make_pair(it.second,it.first));
                }
            }
            else
                pq.push(make_pair(it.second,it.first));
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}