class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        if(A.empty()||B.empty())
            return -1;
        vector<vector<int>> count(6,vector<int>(3,0));// i is i+1 th domino number
        // count[i][0] = if i+1 in A
        // count[i][1] = if i+1 in B
        // count[i][2] = if i+1 in A and B Both;
        for(int i=0; i<A.size(); i++){
            int top = A[i], bottom = B[i];
            if(top==bottom)
                count[top-1][2]++;
            else
                count[top-1][0]++, count[bottom-1][1]++;
        }
        int res = INT_MAX;
        for(auto& vals: count){
            if(vals[0]+vals[1]+vals[2] == A.size())
                res = min({res,vals[0],vals[1]});
        }
        return res==INT_MAX?-1:res;
    }
};