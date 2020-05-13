class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.empty())
            return 0;
        int rowSize = matrix.size(), colSize = matrix[0].size();
        int ret = INT_MIN;
        for(int l = 0; l < colSize; ++l){
            vector<int> sums(rowSize, 0);
            for(int c = l; c < colSize; ++c){
                for(int r = 0; r < rowSize; ++r)
                    sums[r] += matrix[r][c];
                set<int> sums_set; 
                sums_set.insert(0);
                int maxSum = INT_MIN, sum = 0;
                for(int i = 0; i < rowSize; ++i)
                {
                    sum += sums[i];
                    auto iter = sums_set.lower_bound(sum-k);
                    if(iter != sums_set.end()) maxSum = max(maxSum, sum-*iter);
                    sums_set.insert(sum);
                }
                ret = max(ret, maxSum);
            }
        }
        return ret;
    }
};