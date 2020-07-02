class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        // correct way is to make a function to calculate the repeating parameter.
        int n = N%14;
        if(n==0)
            n  = 14;
        while(n--){
            vector<int> tmp(8,0);
            for(int i = 1; i<=6; i++)
                tmp[i] = 1-(cells[i-1]^cells[i+1]);
            cells = tmp;
        }
        return cells;
    }
};


class Solution {
public:
    int getnext(int n){
        n = ~(n<<1)^(n>>1);
        n = n & 0x7e;
        return n;
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        unordered_map<int,int> visited;
        int num = 0;
        for(int c: cells){
            num <<= 1;
            num = (num|c);
        }
        bool fast = false;
        while(N>0){
            if(!fast){
                if(visited.count(num)){
                    N %= visited[num] - N;
                    fast = true;
                }
                else{
                    visited[num] = N;
                }
            }
            
            if(N>0){
                N--;
                num = getnext(num);
            }
        }
        vector<int> res(cells.size());
        for(int i=cells.size()-1; i>=0 ; i--){
            res[i] = (num& 0x1);
            num >>= 1;
        }
        return res;
    }
};