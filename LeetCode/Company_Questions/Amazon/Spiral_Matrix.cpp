class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size()==0)
            return res;
        int top = 0, bottom = matrix.size()-1;
        int left = 0, right = matrix[0].size()-1;
        while(left<=right && top<=bottom){
            for(int c=left; c<=right; c++)
                res.push_back(matrix[top][c]);
            for(int r=top+1; r<=bottom; r++)
                res.push_back(matrix[r][right]);
            if(top<bottom && left<right){
                for(int c=right-1; c>left; c--)
                    res.push_back(matrix[bottom][c]);
                for(int r=bottom; r>top; r--)
                    res.push_back(matrix[r][left]);
            }
            top++;
            bottom--;
            left++;
            right--;
        }
        return res;
    }
};