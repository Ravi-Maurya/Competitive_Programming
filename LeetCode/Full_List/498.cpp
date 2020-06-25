class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return {};
        int n = matrix.size();
        int m = matrix[0].size();
        int r = 0, c = 0;
        bool dir = true;
        vector<int> res(n*m);
        int idx = 0;
        while(r<n && c<m){
            res[idx++] = matrix[r][c];
            int nr = r + (dir?-1:1);
            int nc = c + (dir?1:-1);
            if(nr<0 || nr==n || nc<0 || nc==m){
                if(dir){
                    r += (c==m-1)?1:0;
                    c += (c<m-1)?1:0;
                }
                else{
                    c += (r==n-1)?1:0;
                    r += (r<n-1)?1:0;
                }
                dir = !dir;
            }
            else{
                r = nr;
                c = nc;
            }
        }
        return res;
    }
};


class Solution {
public:
    Solution() {ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);}
    
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        int r = 0, c = 0;
        for(int k = 0; k < m*n; ++k){
            res.emplace_back(matrix[r][c]);
            int sum = r + c;
            if(sum%2 == 0){ // moving up
                if     (c == n-1) ++r;
                else if(r == 0)   ++c;
                else              --r, ++c;
            }else {
                if     (r == m-1) ++c;
                else if(c == 0)   ++r;
                else              ++r, --c;
            }
        }
        return res;
    }
};