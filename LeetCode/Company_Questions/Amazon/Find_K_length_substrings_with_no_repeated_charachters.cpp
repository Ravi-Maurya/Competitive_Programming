class Solution
{
public:
    int numKLenSubstrNoRepeats(string s, int K){
        int n = s.size();
        if(K>26 || n<K)
            return 0;
        vector<int> alph(26,0);
        int i=0, j=0, res = 0;
        while(i<=n-K+1 && j<n){
            if(alph[s[j]-'a']==0)
                alph[s[j]-'a']++;
            else{
                while(alph[s[j]-'a']==1)
                    alph[s[i++]-'a']--;
                alph[s[j]-'a']++;
            }
            if(j-i+1 == K){
                res++;
                alph[s[i++]-'a']--;
            }
            j++;
        }
        return res;
    }
};