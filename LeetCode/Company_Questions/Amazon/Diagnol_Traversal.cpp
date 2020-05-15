class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        if(matrix.size()==0) return ans;
        int m=matrix.size(); int n=matrix[0].size();  ans.push_back(matrix[0][0]) ;
     
        for(int k=1;k<=m+n;k++)
        {
            vector<int>temp;
            for(int i=0;i<m;i++)
            {
                
                for(int j=0;j<n;j++)
                {
                    if(i+j==k )
                    {
                        temp.push_back(matrix[i][j]);
                    }
                    if(i+j>k) break;
                }
            }
            if(k%2==0)
                reverse(temp.begin(),temp.end());
            for(auto x:temp)
              ans.push_back(x);
        }
        return ans;
    }
};