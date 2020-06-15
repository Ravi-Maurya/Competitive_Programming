class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==0)
            return {};
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int val = 1;
        int left =0 ,right = n-1, top = 0, bottom = n-1;
        int dirs = 0;
        while(left<=right && top<=bottom){
            if(dirs==0){
                for(int i = left; i<=right; i++,val++){
                    matrix[top][i] = val;
                }
                top++;
            }
            else if(dirs==1){
                for(int i=top; i<=bottom; i++,val++){
                    matrix[i][right] = val;
                }
                right--;
            }
            else if(dirs==2){
                for(int i = right; i>=left; i--,val++){
                    matrix[bottom][i] = val;
                }
                bottom--;
            }
            else{
                for(int i=bottom; i>=top; i--,val++){
                    matrix[i][left] = val;
                }
                left++;
            }
            dirs = (dirs+1)%4;
        }
        return matrix;
    }
};