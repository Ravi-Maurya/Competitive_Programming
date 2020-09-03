typedef long long int ll;
class Solution {
public:
    bool check(map<ll,ll>& mp, ll x, ll t){
        if(mp.size()==0)
            return false;
        auto it = mp.lower_bound(x);
        if(it!=mp.end()){
            if(abs(it->first - x)<=t)
                return true;
            it--;
            if(it!=mp.end() && abs(it->first - x)<=t)
                return true;
        }
        else{
            it--;
            return abs(it->first - x)<=t;
        }
        return false;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size()<2 || t<0 || k<=0)
            return false;
        map<ll,ll> mp;
        for(int i=0; i<k; i++){
            if(check(mp,nums[i],t))
                return true;
            mp[nums[i]]++;
        }
        for(int i=k; i<nums.size(); i++){
            if(check(mp,nums[i],t))
                return true;
            mp[nums[i]]++;
            mp[nums[i-k]]--;
            if(mp[nums[i-k]] <= 0)
                mp.erase(nums[i-k]);
        }
        return false;
    }
};