class Solution {
public:
    // just simulate it
    double err = 1e-6;
    
    bool solve(vector<double>& nums){
        if(nums.size()==0)
            return false;
        if(nums.size()==1)
            return abs(nums[0]-24)<err;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums.size(); j++){
                if(i!=j){
                    vector<double> tmp;
                    for(int k=0; k<nums.size(); k++)
                        if(k!=i && k!=j)
                            tmp.push_back(nums[k]);
                    for(int k=0; k<4; k++){
                        if(k<2 && j>i)
                            continue;
                        if(k==0)
                            tmp.push_back(nums[i]+nums[j]);
                        else if(k==1)
                            tmp.push_back(nums[i]*nums[j]);
                        else if(k==2)
                            tmp.push_back(nums[i]-nums[j]);
                        else if(k==3){
                            if(nums[j]!=0)
                                tmp.push_back(nums[i]/nums[j]);
                            else
                                continue;
                        }
                        if(solve(tmp))
                            return true;
                        tmp.pop_back();
                    }
                }
            }
        }
        return false;
    }
    
    bool judgePoint24(vector<int>& nums) {
        vector<double> arr;
        for(auto x: nums)
            arr.push_back(x*1.0);
        return solve(arr);
    }
};