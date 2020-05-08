class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(),i,j,k,l;
        set<vector<int>> st;
        vector<vector<int>> res;
        if(n<4)
            return res;
        for(i=0; i<n-3; i++){
            for(j=i+1; j<n-2;j++){
                k = j+1;
                l = n-1;
                while(k<l){
                    auto s = nums[i]+nums[j]+nums[k]+nums[l];
                    if(s-target == 0){
                        st.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++;l--;
                    }
                    else if(s>target)
                        l--;
                    else
                        k++;
                }
            }
        }
        for(auto r:st)
            res.push_back(r);
        return res;
    }
};

class Solution2 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target){
        vector<vector<int>>res;
        int i,j,k,l;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n<4)
            return res;
        for(i=0;i<n-3;i++){
            if((i>0)&&(nums[i]==nums[i-1]))
                continue;
            int t0=target-nums[i];
            for(j=i+1;j<n-2;j++){
                if((j>i+1)&&(nums[j]==nums[j-1]))
                    continue;
                int t1=t0-nums[j];
                if(nums[j+1]+nums[j+2] > t1)
                    break;
                if(nums[n-1]+nums[n-2] < t1)
                    continue;
                k=j+1,l=n-1;
                while(k<l){
                    int t3=nums[k]+nums[l];
                    if(t3>t1)
                        l--;
                    else if(t3<t1)
                        k++;
                    else{
                        res.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                        while((k<l)&&(nums[k]==nums[k-1]))
                            k++;
                        while((k<l)&&(nums[l]==nums[l+1]))
                            l--;
                    }
                }
            }
        }
        return res;
    }
};