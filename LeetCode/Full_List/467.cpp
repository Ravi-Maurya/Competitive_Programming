class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        if(n<2)
            return n;
        int alpha[26];
        memset(alpha,0,sizeof(alpha));
        alpha[p[0]-'a']++;
        int count = 1;
        for(int i=1; i<n; i++){
            if((p[i] == p[i-1]+1) || (p[i-1]=='z' && p[i] =='a')){
                count++;
                alpha[p[i]-'a'] = max(alpha[p[i]-'a'], count);
            }
            else{
                alpha[p[i]-'a'] = max(alpha[p[i]-'a'],1);
                count = 1;
            }
        }
        int res = 0;
        for(auto x: alpha)
            res += x;
        return res;
    }
};