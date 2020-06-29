class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int,int>> pq;
        int n = points.size();
        for(int i=0; i<n; i++){
            vector<int> curr = points[i];
            int dist = (curr[0]*curr[0] + curr[1]*curr[1]);
            pq.push({dist,i});
            if(pq.size()>K)
                pq.pop();
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }
};