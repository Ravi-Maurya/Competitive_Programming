class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i<nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int j = i+1, k = nums.size()-1;
            while(j<k){
                int s = nums[i] + nums[j] + nums[k];
                if(s<0)
                    j++;
                else if(s>0)
                    k--;
                else{
                    res.push_back(vector<int> {nums[i],nums[j],nums[k]});
                    do{
                        j++;
                    }while(j<k && nums[j-1]==nums[j]);
                    do{
                        k--;
                    }while(j<k && nums[k]==nums[k+1]);
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {//o(n2)
        vector<vector<int>> res;
        set<pair<int,int>> ust;
        unordered_set<int> dup;
        unordered_map<int,int> visited;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(dup.insert(nums[i]).second){
                for(int j=i+1; j<n; j++){
                    int comp = -nums[i]-nums[j];
                    auto it = visited.find(comp);
                    if(it != visited.end() && it->second == i){
                        int v1 = min({nums[i],nums[j],comp});
                        int v2 = max({nums[i],nums[j],comp});
                        if(ust.insert({v1,v2}).second)
                            res.push_back({nums[i],comp,nums[j]});
                    }
                    visited[nums[j]] = i;
                }
            }
        }
        return res;
    }
};