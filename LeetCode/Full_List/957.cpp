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