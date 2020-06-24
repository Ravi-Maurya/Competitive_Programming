class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int n=v.size();
        int i,cursum=0,maxsum=INT_MIN;
        for(i=0;i<n;i++){
            cursum+=v[i];
            if(cursum>maxsum)
                maxsum=cursum;
            if(cursum<0)
                cursum=0;
        }
        return maxsum;
    }
};