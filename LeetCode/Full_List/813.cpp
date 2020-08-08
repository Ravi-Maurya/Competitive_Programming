class Solution {
public:
    const double fill = -1;
    vector<vector<double>> dp;
    double avg(int i, int j, vector<int>& A){
        if(i==0)
            return (A[j]*1.0)/(j-i+1);
        return ((A[j]-A[i-1])*1.0)/(j-i+1);
    }
    double solve(vector<int>& A, int i, int k){
        if(i>=A.size() && k>=1)
            return INT_MIN;
        if(k==1){
            return avg(i,A.size()-1,A);
        }
        if(dp[i][k]!=fill)
            return dp[i][k];
        double res = 0.0;
        for(int j = i; j<A.size(); j++){
            double tmp = avg(i,j,A) + solve(A, j+1, k-1);
            if(tmp>res)
                res = tmp;
        }
        return dp[i][k] = res;
    }
    
    double largestSumOfAverages(vector<int>& A, int K) {
        for(int i=1; i<A.size(); i++)
            A[i] += A[i-1];
        dp.resize(A.size(),vector<double>(K+1,fill));
        return solve(A,0,K);
    }
};


class Solution {
public:
    const double fill = -1;
    vector<vector<double>> dp;
    double avg(int i, int j, vector<int>& A){
        if(i==0)
            return (A[j]*1.0)/(j-i+1);
        return ((A[j]-A[i-1])*1.0)/(j-i+1);
    }
    double solve(vector<int>& A, int K, int i, int j){
        if(j-i+1 <= K){
            return INT_MIN*1.0;
        }
        if(K==0)
            return avg(i,j,A);
        if(dp[i][K]!=fill)
            return dp[i][K];
        double res = 0.0;
        for(int k=i; k<j;k++){
            double tmp = avg(i,k,A) + solve(A,K-1, k+1,j);
            if(tmp>res)
                res = tmp;
        }
        return dp[i][K] = res;
    }
    
    double largestSumOfAverages(vector<int>& A, int K) {
        for(int i=1; i<A.size(); i++)
            A[i] += A[i-1];
        dp.resize(A.size(),vector<double>(K+1,fill));
        return solve(A,K-1,0,A.size()-1);
    }
};