class Solution {
public:
    bool check(vector<string>& s, int l){
        string s1 = s[0].substr(0,l);
        for(int i=1; i<s.size(); i++)
            if(!(s1==s[i].substr(0,l)))
                return false;
        return true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        int minLen = INT_MAX;
        for(string s: strs){
            minLen = min(minLen, (int)s.size());
        }
        int l = 1, h = minLen;
        while(l<=h){
            int mid = (l+h)/2;
            if(check(strs,mid))
                l = mid+1;
            else
                h = mid-1;
        }
        return strs[0].substr(0,(l+h)/2);
    }
};