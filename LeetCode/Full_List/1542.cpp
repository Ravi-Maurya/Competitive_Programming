class Solution {
public:
    int longestAwesome(string s) {
        int last[1<<10];
        fill(last,last+(1<<10),1000000);
        int ans=0;
        last[0]=-1;
        int now=0;
        for(int i = 0;i<s.size();i++){
            now^=(1<<(s[i]-'0'));
            last[now]=min(last[now],i);
            ans=max(ans,i-last[now]);
            for(int j=0;j<10;j++){
                ans=max(ans,i-last[now^(1<<j)]);
            }
        }
        return ans;
    }
};