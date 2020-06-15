class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k<0)
            return 0;
        unordered_map<int,int> mp;
        for(auto x:nums)
            mp[x]++;
        int res = 0;
        for(auto& [x,cnt]: mp){
            if(k==0){
                if(cnt>1)
                    res++;
            }
            else{
                if(mp.count(x+k))
                    res++;
            }
        }
        return res;
    }
};