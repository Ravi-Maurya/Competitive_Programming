class Solution {//O(n*32)
public:
    int count(int n){
        int res = 0;
        while(n){
            res++;
            n = n&(n-1);
        }
        return res;
    }
    vector<int> countBits(int num) {
        vector<int> res;
        for(int x=0; x<=num; x++)
            res.push_back(count(x));
        return res;
    }
};

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1,0);
        for(int i=1; i<=num; i++){
            // for even number there are same bits as i/2 e.g. 100(4), 10(2), 1(1) have same
            // for odd there is 1 + same as (i-1) e.g. 101(5) = 1 + 100(4) = 1 + 10(4/2);
            res[i] = i%2 + res[i>>1];
        }
        return res;
    }
};