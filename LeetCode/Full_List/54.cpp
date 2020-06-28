class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dirs = 0;
        vector<int> res;
        if(matrix.empty())
            return res;
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0, right = m-1;
        int top = 0, bottom = n-1;
        while(top<=bottom && left<=right){
            if(dirs==0){
                for(int i=left; i<=right; i++){
                    res.push_back(matrix[top][i]);
                }
                top++;
            }
            else if(dirs==1){
                for(int i=top; i<=bottom; i++){
                    res.push_back(matrix[i][right]);
                }
                right--;
            }
            else if(dirs==2){
                for(int i=right; i>=left; i--){
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            else{
                for(int i=bottom; i>=top; i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
            dirs = (dirs+1)%4;
        }
        return res;
    }
};