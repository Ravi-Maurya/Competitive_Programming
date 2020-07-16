class Solution {
public:
    int binary_search(int val, vector<int> &heaters){
        int res = 0;
        int l = 0, r = heaters.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(heaters[mid]==val)
                return 0;
            else if(heaters[mid]<val)
                l = mid+1;
            else
                r = mid-1;
        }
        return min(heaters[l]-val, val - heaters[r]);
    }
    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int res = 0;
        sort(heaters.begin(),heaters.end());
        for(auto& house: houses){
            if(house<=heaters.front()){
                res = max(res, heaters.front() - house);
                continue;
            }
            if(house>=heaters.back()){
                res = max(res, house - heaters.back());
                continue;
            }
            res = max(res, binary_search(house,heaters));
        }
        return res;
    }
};