#include<bits/stdc++.h>
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        int k = min(numRows,int(s.size()));
        vector<string> rows(k);
        int curr = 0;
        bool down = false;
        for(auto ch: s){
            rows[curr] += ch;
            if(curr == 0 || curr == k-1)
                down = !down;
            curr += down?1:-1;
        }
        string res ="";
        for(auto row:rows)
            res += row;
        return res;
    }
};