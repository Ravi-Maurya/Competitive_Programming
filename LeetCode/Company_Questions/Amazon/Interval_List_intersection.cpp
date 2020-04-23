class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        int i=0, j=0;
        while(i<A.size() && j<B.size()){
            int l = max(A[i][0],B[j][0]);
            int h = min(A[i][1],B[j][1]);
            if(l<=h)
                res.push_back({l,h});
            if(A[i][1]<B[j][1])
                i++;
            else
                j++;
        }
        return res;
    }
};