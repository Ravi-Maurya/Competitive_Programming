class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n*m-1;
        while(left<=right){
            int mid = (left+right)/2;
            int val = matrix[mid/n][mid%n];
            if(target==val)
                return true;
            else if(target<val)
                right = mid-1;
            else
                left = mid+1;
        }
        return false;
    }
};