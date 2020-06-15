class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        if(n==0)
            return {0};
        res.push_back(0);
        res.push_back(1);
        if(n==1)
            return res;
        for(int i = 2; i<=n; i++){
            int size = res.size();
            int add = pow(2,i-1);
            while(size--){
                res.push_back(add+res[size]);
            }
        }
        return res;
    }
};