class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> ump;
        for(auto& ch: s)
            ump[ch]++;
        int res = 0;
        bool is_odd = false;
        for(auto& [ch,val]: ump){
            if(val%2 == 0)
                res += val;
            else{
                res += val-1;
                is_odd = true;
            }
        }
        if(is_odd)
            res += 1;
        return res;
    }
};