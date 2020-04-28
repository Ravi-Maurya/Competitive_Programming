class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int size = matrix.size(), l = matrix[0][0], r = matrix[size-1][size-1];
        while(l < r)
        {
            int smaller = 0, m = l+((r-l)>>1);
            for(int i = 0; i < size; ++i) 
                smaller += upper_bound(matrix[i].begin(), matrix[i].end(), m)-matrix[i].begin();
            if(smaller<k)
                l=m+1;
            else
                r=m;
        }
        return r;
    }
};