class Solution {
public:
    vector<int> sumZero(int n) {
        if(n==0)
            return {};
        if(n==1)
            return {0};
        vector<int> res(n);
        int i = 0;
        if(n&1){
            res[i] = 0;
            i++;
        }
        int k = (n>>1);
        for(int j=1; i<n; i+=2,j++){
            res[i] = -1*j;
            res[i+1] = j;
        }
        return res;
    }
};