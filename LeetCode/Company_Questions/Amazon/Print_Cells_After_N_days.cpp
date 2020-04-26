class Solution {
public:
    int nextDay(int state){
        int ans = 0;
        for(int i=1;i<=6;i++){
            if(((state>>(i-1))&1) == ((state>>(i+1))&1))
                ans ^= 1<<i;
        }
        return ans;
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        unordered_map<int,int> ump;
        int state = 0;
        for(int i=0; i<8; i++){
            if(cells[i]>0)
                state ^= (1<<i);
        }
        while(N>0){
            if(ump.find(state)!=ump.end()){
                N %= (ump[state]-N);
            }
            ump[state] = N;
            if(N>=1){
                N--;
                state = nextDay(state);
            }
        }
        vector<int> ans(8,0);
        for(int i=0; i<8; i++)
            if(((state>>i)&1) > 0)
                ans[i] = 1;
        
        return ans;
    }
};