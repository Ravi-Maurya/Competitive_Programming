class Solution {
public:
    int comp(int& a, int &b){
        if(a==b)
            return 0;
        if(a>b)
            return 1;
        return -1;
    }
    int maxTurbulenceSize(vector<int>& A) {
        int n = A.size();
        int res = 1;
        int j = 0;
        for(int i=1; i<n; i++){
            int x = comp(A[i-1],A[i]);
            if(x==0){
                j = i;
            }
            else if(i==n-1 || x*comp(A[i],A[i+1])!=-1){
                res = max(res,i-j+1);
                j = i;
            }
        }
        return res;
    }
};