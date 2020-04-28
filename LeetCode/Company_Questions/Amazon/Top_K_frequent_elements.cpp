class Solution {
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