// class Solution {
// public:
//     vector<vector<int>> dp;
//     int solve(vector<int>& nums, int idx,  int n, int m){
//         if(m==1){
//             int curr = 0;
//             if(idx>=n)
//                 return 0;
//             for(int i=idx;i<n; i++)
//                 curr += nums[i];
//             return dp[idx][m] = curr;
//         }
//         if(idx>=n)
//             return INT_MAX;
//         if(dp[idx][m]!=-1)
//             return dp[idx][m];
//         int curr = 0; int res = INT_MAX;
//         for(int i=idx; i<n; i++){
//             curr += nums[i];
//             int tmp = max(curr,solve(nums,i+1,n,m-1));
//             if(tmp<res)
//                 res = tmp;
//         }
//         return dp[idx][m] = res;
//     }
//     int splitArray(vector<int>& nums, int m) {
//         int n = nums.size();
//         dp.resize(n+1,vector<int>(m+1,-1));
//         return solve(nums,0,n,m);
//     }
// };

class Solution {
public:
    long long sum(vector<int>& A) {
        long long s = 0;
        for(int i = 0; i < A.size(); i++) {
            s += A[i];
        }
        return s;
    }

    bool isPossible(vector<int>& A, long long s, int m) {
        long long sums = 0;
        for(int i = 0; i < A.size(); i++) {
            if(A[i] > s) {
                return false;
            }
            if(sums + A[i] > s) {
                sums = A[i];
                m--;
                if(m < 0) {
                    return false;
                }
            } else {
                sums += A[i];
            }
        }
        if(sums > 0) {
            m--;
        }
        return m >= 0;
    }
    
    int splitArray(vector<int>& A, int m) {
        long long low = 0, high = sum(A), ans = 0;
        while(low <= high) {
            long mid = low + (high - low)/2;
            if(isPossible(A, mid, m)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }                
};