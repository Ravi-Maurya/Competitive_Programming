class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int min1, min2,tmp1,tmp2;
        int n = arr.size(), m = arr[0].size();
        min1 = INT_MAX, min2 = INT_MAX;
        for(int j=0; j<m; j++){
            if(min1>arr[n-1][j] && min2>arr[n-1][j]){
                min2 = min1;
                min1 = arr[n-1][j];
            }
            else if(min1<= arr[n-1][j] && min2>arr[n-1][j]){
                min2 = arr[n-1][j];
            }
        }
        for(int i=n-2; i>=0 ;i--){
            tmp1 = INT_MAX, tmp2 = INT_MAX;
            for(int j=0; j<n; j++){
                if(arr[i+1][j]==min1)
                    arr[i][j] += min2;
                else
                    arr[i][j] += min1;
                
                if(tmp1>arr[i][j] && tmp2>arr[i][j]){
                    tmp2 = tmp1;
                    tmp1 = arr[i][j];
                }
                else if(tmp1<= arr[i][j] && tmp2>arr[i][j]){
                    tmp2 = arr[i][j];
                }
            }
            min1 = tmp1;
            min2 = tmp2;
        }
        return min1;
    }
};