class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> ump;
        ump['I'] = 1;
        ump['V'] = 5;
        ump['X'] = 10;
        ump['L'] = 50;
        ump['C'] = 100;
        ump['D'] = 500;
        ump['M'] = 1000;
        int n = s.size();
        int res = 0;
        for(int i =0; i<n-1; i++){
            if(ump[s[i]]<ump[s[i+1]])
                res -= ump[s[i]];
            else
                res += ump[s[i]];
        }
        res += ump[s[n-1]];
        return res;
    }
};