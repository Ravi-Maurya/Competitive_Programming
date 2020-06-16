class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int,int>> pq;
        int n = points.size();
        for(int i=0; i<n; i++){
            vector<int> curr = points[i];
            int dist = (curr[0]*curr[0] + curr[1]*curr[1]);
            if(pq.size()==K){
                if(pq.top().first > dist){
                    pq.pop();
                    pq.push({dist,i});
                }
            }
            else{
                pq.push({dist,i});
            }
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }
};