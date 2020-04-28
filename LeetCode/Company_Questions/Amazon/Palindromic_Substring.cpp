class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), res =0;
        for(int i=0; i<=2*n-1;i++){
            int j = i/2;
            int k = j + i % 2;
            while(j>=0 && k<n && s[j]==s[k]){
                res++;
                j--;
                k++;
            }
        }
        return res;
    }
};