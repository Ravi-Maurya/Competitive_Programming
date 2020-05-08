class Solution{
public:
    vector< vector<int> > threeSum(vector<int> &nums){
        sort(begin(nums), end(nums));
        vector< vector<int> > res;
        for (size_t i=0; i<nums.size(); i++) {
            if ((i>0) && (nums[i]==nums[i-1]))
                continue;
            size_t j = i+1, k = nums.size()-1;
            while (j<k) {
                int s = nums[i]+nums[j]+nums[k];
                if (s>0)
                    k--;
                else if (s<0)
                    j++;
                else {
                    res.push_back(vector<int> {nums[i], nums[j], nums[k]});
                    do{
                        j++;
                    }while (j<k && nums[j-1]==nums[j]);
                    do{
                        k--;
                    }while (j<k && nums[k+1]==nums[k]);
                }
            }
        }
        return res;
    }
};