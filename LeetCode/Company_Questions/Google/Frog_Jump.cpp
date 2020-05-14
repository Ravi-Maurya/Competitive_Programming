class Solution {
public:
    bool canCross(vector<int>& stones) {
        for(int i=3; i<stones.size(); i++)
            if(stones[i]>stones[i-1]*2)
                return false;
        unordered_set<int> ust(stones.begin(),stones.end());
        stack<pair<int,int>> dfs;
        dfs.push({0,0});
        int last_position = stones[stones.size()-1];
        while(!dfs.empty()){
            auto curr = dfs.top();dfs.pop();
            for(int k=curr.second-1; k<=curr.second+1; k++){
                if(k<=0)
                    continue;
                
                int next_position = curr.first + k;
                if(next_position == last_position)
                    return true;
                if(ust.count(next_position))
                    dfs.push({next_position,k});
            }
        }
        return false;
    }
};