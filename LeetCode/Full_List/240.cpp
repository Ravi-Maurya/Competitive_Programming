class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int i = 0, j = matrix[0].size()-1;
        while(i<matrix.size() && j>=0){
            if(target==matrix[i][j])
                return true;
            else if(target>matrix[i][j])
                i++;
            else
                j--;
        }
        return false;
    }
};