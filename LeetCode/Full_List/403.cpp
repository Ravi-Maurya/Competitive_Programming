class Solution {//O(n3)
public:
    vector<vector<int>> dp;
    bool helper(vector<int>& stones, int idx, int jump){
        if(dp[idx][jump]>=0)
            return dp[idx][jump];
        for(int i= idx+1; i<stones.size(); i++){
            int gap = stones[i]-stones[idx];
            if(gap>=jump-1 && gap<=jump+1){
                if(helper(stones,i,gap)){
                    dp[idx][jump] = 1;
                    return 1;
                }
            }
        }
        dp[idx][jump] = (idx==stones.size()-1)?1:0;
        return dp[idx][jump];
    }
    bool canCross(vector<int>& stones) {
        dp.resize(stones.size(),vector<int>(stones.size(),-1));
        return helper(stones,0,0);
    }
};

class Solution {//O(n2)
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,unordered_set<int>> ump;//for every stones[i]+steps put steps as reached here
        int n = stones.size();
        ump[0].insert(0);
        for(int i=0; i<n; i++){
            if(ump.count(stones[i])){
                for(int k:ump[stones[i]]){
                    for(int steps=k-1;steps<=k+1; steps++){
                        if(steps>0)
                            ump[stones[i]+steps].insert(steps);
                    }
                }
            }
        }
        if(ump.count(stones[n-1]))
            return true;
        return false;
    }
};


class Solution {//Given best
public:
    
    bool frogjump(vector<int>& stones,int index,int k,int n){
        if(index+1==n)
            return true;
        for(int i=k+1;i>=k-1;i--){//O(3)
            for(int j=index+1;j<n;j++){
                if(stones[j]-stones[index]>i)
                    break;
                if(stones[j]-stones[index]==i){
                  if(frogjump(stones,j,i,n))
                      return true;
                }
            }
        }
        return false;
    }
    bool canCross(vector<int>& stones) {
        
        int n = stones.size();
        if(n<2)return false;
        if(stones[1]!=1)return false;
        // the maxm jumps may be 1 2 3 4 5 6 7 8 9 .....n-1  starting from 1
        // so the last number of stone should be less than the sum of these maxm jumps
        //i.e sum = n*(n-1)/2;
         if(stones[n-1]>n*(n-1))return false;
        
        return frogjump(stones,1,1,n);
    }
};