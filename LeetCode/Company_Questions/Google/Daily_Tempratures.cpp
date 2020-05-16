class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n,0);
        stack<int> stck;
        for(int i=n-1; i>=0; i--){
            while(!stck.empty() && T[i]>=T[stck.top()])
                stck.pop();
            res[i] = stck.empty()?0:stck.top()-i;
            stck.push(i);
        }
        return res;
    }
};