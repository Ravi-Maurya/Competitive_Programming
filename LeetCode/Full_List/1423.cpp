class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        if(n==1)
            return cardPoints[0];
        int curr = 0, res = INT_MIN;
        for(int i=0; i<k; i++)
            curr += cardPoints[i];
        res = max(res,curr);
        int i = n-1, j = k-1;
        while(j>=0){
            curr -= cardPoints[j];
            curr += cardPoints[i];
            if(curr>res)
                res = curr;
            i--;
            j--;
        }
        return res;
    }
};