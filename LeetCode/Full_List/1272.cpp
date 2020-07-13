class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> res;
        for(auto& curr: intervals){
            if(curr[1]<=toBeRemoved[0] || curr[0]>=toBeRemoved[1]){//not intersection
                res.push_back(curr);
            }
            else if(curr[0]<toBeRemoved[0] && toBeRemoved[1]<curr[1]){// outer intersect
                res.push_back({curr[0],toBeRemoved[0]});
                res.push_back({toBeRemoved[1],curr[1]});
            }
            else if(curr[0]<toBeRemoved[0] && curr[1]<=toBeRemoved[1]){//partial intersect
                res.push_back({curr[0],toBeRemoved[0]});
            }
            else if(toBeRemoved[0]<=curr[0] && toBeRemoved[1]<curr[1]){//partial intersect
                res.push_back({toBeRemoved[1],curr[1]});
            }
        }
        return res;
    }
};