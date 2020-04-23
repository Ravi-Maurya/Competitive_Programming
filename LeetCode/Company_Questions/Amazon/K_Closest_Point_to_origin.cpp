class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int,pair<int,int>>> pq;
        for(auto curr: points){
            int dist = (curr[0]*curr[0] + curr[1]*curr[1]);
            if(pq.size()==K){
                if(pq.top().first > dist){
                    pq.pop();
                    pq.push({dist,{curr[0],curr[1]}});
                }
            }
            else{
                pq.push({dist,{curr[0],curr[1]}});
            }
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            res.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return res;
    }
};