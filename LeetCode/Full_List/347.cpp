class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto& x: nums){
            count[x]++;
        }
        for(auto& [x,cnt]:count){
            if(pq.size()<k)
                pq.push({cnt,x});
            else{
                if(cnt>pq.top().first){
                    pq.pop();
                    pq.push({cnt,x});
                }
            }
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};