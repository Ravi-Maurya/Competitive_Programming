class Solution {
public:
    struct Node{
        double max_val, min_val;
        string max_res, min_res;
        bool flag;
        Node(){
            max_val = INT_MIN*1.0;
            min_val = INT_MAX*1.0;
            max_res = "";
            min_res = "";
            flag = false;
        }
        void fill(double mx, double mn, string maxs, string mins){
            max_val = mx;
            min_val = mn;
            max_res = maxs;
            min_res = mins;
            flag = true;
        }
    };
    vector<vector<Node>> dp;
    
    Node optimize(vector<int>& nums, int st, int en, string op){
        if(dp[st][en].flag){
            return dp[st][en];
        }
        Node res = Node();
        if(st==en){
            res.fill(nums[st],nums[st],to_string(nums[st]),to_string(nums[st]));
            dp[st][en] = res;
            return res;
        }
        for(int i=st; i<en; i++){
            auto left = optimize(nums,st,i,"");
            auto right = optimize(nums,i+1,en,"");
            if(res.min_val > (left.min_val/right.max_val)){
                res.min_val = (left.min_val/right.max_val);
                res.min_res = left.min_res + "/";
                if(i+1!=en){
                    res.min_res += "(";
                }
                res.min_res += right.max_res;
                if(i+1 != en){
                    res.min_res += ")";
                }
            }
            if(res.max_val < (left.max_val/right.min_val)){
                res.max_val = (left.max_val/right.min_val);
                res.max_res = left.max_res + "/";
                if(i+1!=en){
                    res.max_res += "(";
                }
                res.max_res += right.min_res;
                if(i+1 != en){
                    res.max_res += ")";
                }
            }
        }
        dp[st][en] = res;
        return res;
    }
    
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,vector<Node>(n,Node()));
        auto res = optimize(nums,0,nums.size()-1,"");
        return res.max_res;
    }
};

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return to_string(nums[0]);
        if(n==2)
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        string res = to_string(nums[0]) + "/(" + to_string(nums[1]);
        for(int i=2; i<n; i++)
            res += "/" + to_string(nums[i]);
        res += ")";
        return res;
    }
};