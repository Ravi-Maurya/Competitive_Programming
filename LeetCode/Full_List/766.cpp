class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int j = m-1; j>=0; j--){
            unordered_set<int> ust;
            for(int i=0; i<min(m-j,n); i++){
                ust.insert(matrix[i][j+i]);
                if(ust.size()>=2)
                    return false;
            }
        }
        for(int i=1;i<n;i++){
            unordered_set<int> ust;
            for(int j=0;j<min(m,n-i);j++){
                ust.insert(matrix[i+j][j]);
                if(ust.size()>=2)
                    return false;
            }
        }
        return true;
    }
};