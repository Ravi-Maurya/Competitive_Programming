class Solution {
public:
    string reorganizeString(string S) {
        int n = S.size();
        if(n<2)
            return S;
        int max = (n+1)/2;
        vector<int> count(26,0);
        for(auto& ch:S){
            count[ch-'a']+=1000;
        }
        for(int i=0;i<26;i++)
            count[i] += i;
        string res(n,0);
        sort(count.begin(),count.end());
        int t = 1;
        for(int i =0; i<26;i++){
            int cnt = count[i]/1000;
            char ch = char('a' + count[i]%1000);
            if(cnt>max)
                return "";
            while(cnt--){
                if(t>=n)
                    t = 0;
                res[t] = ch;
                t += 2;
            }
        }
        return res;
    }
};