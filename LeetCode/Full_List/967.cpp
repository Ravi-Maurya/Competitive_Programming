class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        if(N==1){
            return {0,1,2,3,4,5,6,7,8,9};
        }
        
        queue<int> q;
        for(int i=1; i<=9; i++)
            q.push(i);
        for(int l=1; l<N; l++){
            queue<int> nq;
            while(!q.empty()){
                int x = q.front();q.pop();
                int t = x%10;
                vector<int> next_digits;
                next_digits.push_back(t+K);
                if(K!=0)
                    next_digits.push_back(t-K);
                for(auto nx: next_digits){
                    if(0<=nx && nx<10){
                        nq.push(x*10 + nx);
                    }
                }
            }
            q = nq;
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};