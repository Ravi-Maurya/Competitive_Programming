class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.empty())
            return 0;
        int n = matrix.size(), m = matrix[0].size();
        int mn = matrix[0][0], mx=matrix[n-1][m-1];
        while(mn<mx){
            int curr = mn + (mx-mn)/2;
            int count = 0;
            for(int i=0; i<n; i++){
                count += upper_bound(matrix[i].begin(),matrix[i].end(),curr) - matrix[i].begin();
            }
            if(count<k)
                mn = curr+1;
            else
                mx = curr;
        }
        return mn;
    }
};